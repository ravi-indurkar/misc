/* 

THEORY OF T10DIF

typedef struct block_with_t10dif_
{
   uint8_t  data[ 512 ];
   uint16_t guardCRC;   // half-word (short) 16bit CRC checksum 
   uint16_t appTag;     // half-word (short) 16bit OS opague unused 
   uint32_t refTagLBA;  // 32bit uint LBA 

} block_with_t10dif_t ;

 ___________________________________________
|                   511 |512 |514 |516..... |
|                       |513 |515 | .....519|
|                       |crc |app |LBA/Ref  |
|                       |gurd|    |         |
|_______________________|____|____|_________|

type0 = no protection no checking
type1 = CRCguard+--noapp---+RefLBA
type2 = Similar to type1, except first LBA
type3 = CRCguard only

Polynomial bitmask is 18BB7 (see program.c below)

0. At factory before shipping, FORMAT(cdb-opdoce 0x04) and choose whichever type you want
	type0 = no protection no checking
	type1 = CRCguard+--noapp---+RefLBA
	type2 = Similar to type1, except first LBA
	type3 = CRCguard only

1. standard INQUIRY and see if PROTECT (BYTE5, bit0) is set to 0x1
	This tells Is T10DIF feature supported ?? yes/no
	Issue standard SCSI-CDB: (0x12, 0x00, 0x00, 0x00, 0xFF, 0x00)
	return data for SCSI-CDB: 0x00, ... In that check PROTECT (BYTE5, bit0) 

	This is enough, No need to issue extendedInquiry below. Just go to next point 2.
	however, if you are curious to find, What other types are supported?
	1.1 To get more granular, Issue INQUIRY with pagecode=0x86 (aka extendedInquiry)
		Issue standard SCSI-CDB: 0x12, 0x01, 0x86, 0x00, 0xFF, 0x00
		and check SPT (BYTE4, bit3,4,5) to see various supported T10 types
		spt=0 --> type=1   spt=binary000 (bit5,bit4,bit3)=type1 
		spt=1 --> type=1+2 spt=binary001 (bit5,bit4,bit3)=type1, and type2
		spt=2 --> type=2   spt=binary010 (bit5,bit4,bit3)=type2
		spt=3 --> type=1+3 spt=binary011 (bit5,bit4,bit3)=type1 + type3
		spt=4 --> type=3   spt=binary100 (bit5,bit4,bit3)=type3
		spt=5 --> type=2+3 spt=binary101 (bit5,bit4,bit3)=type2 & type3
		spt=6 --> reserved
		spt=7 --> type=1&2&3 spt=binary111 (bit5,bit4,bit3)=all types supported

		BTW to extact unit-serial, issue  Inquiry pagecode=0x80 
		serial-number SCSI-CDB: 0x12, 0x01, 0x80, 0x00, 0xFF, 0x00

		BTW pagecode=0x83 gives more detailed Device Identificatin page

2. Issue READ_CAPA16(0x9E) and see if BYTE12 bit0 (PROT_EN) is set to 0x1
	issue READ_CAPA16(0x9E) CDB:   (0x9e 10 00 00 00 00 00 00 00 00 00 00 00 20 00 00 )
	2.1 BYTE-12 bit0 (PROT_EN) when set to 1 tells , not only do we support, but 
		whether this feature is turned-ON.
	2.2 BYTE-12 bits1,2,3 tell what type is currently in-use (P_TYPE)
		P_TYPE=0 --> type1 ( CRCguard+--noapp---+RefLBA )
		P_TYPE=1 --> type2 ( CRCguard+--noapp---+RefLBA  almost similar to type1 )
		P_TYPE=2 --> type3 ( CRCguard only)
	issue READ_CAPA16(0x9E) CDB:   (0x9e 10 00 00 00 00 00 00 00 00 00 00 00 20 00 00 )
	returned READ_CAPACITY-data:
	00 00 00 00 68 cb 9e 2f 00 00 02 00 01 00 00 00
	00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	Byte 12 = 1 indicates bits PROT_EN = 1 and protection type bits P_TYPE = 0 , TYPE 1 formatted

3. Now write your data using WRITE16(0x8A) by make use or dont use the T10DIF as follows:
	set BYTE1,bits5,6,7 also known as (aka) PROTECT

4. READ the data  using READ16(0x88) and enforce that it is correct by
	setting BYTE1,bits5,6,7 also known as (aka) PROTECT
However,
	we can just temporarily disable checking just for one sector as follows:
	In type 1 and 2, the APPTAG (in middle) is unused, so a storage device can use it to 
	return a value of 0xFFFF, then the I/O controller must disable checking just for that sector
Similarly,
	In type 3, only the CRCguard is used, the APPTAG and LBArefTAG is unused, so a storage device can use 
	the APPTAG+LBArefTAG to return a value of 0xFFFF-FFFFFFFF, then you must disable 
	checking just for that sector

=================================================================== */


// RAVIII downloaded by RSIII on Wed Jan  7 16:19:43 PST 2015
// from http://www.t10.org/drafts.htm and SBC-3 section 4.22
// and Appendix C
// RAVIII downloaded by RSIII on Wed Jan  7 16:19:43 PST 2015

// RAVIII This is how I compile it.
// gcc -o T10DIF T10DIF.c
//
// $ ./T10DIF
// Example CRC all-zeros is 0000
// Example CRC all-ones is a293
// Example CRC incrementing is 0224
// Example CRC FF FF then 30 zeros is 21b8
// Example CRC FF decrementing to E0 is a0b7
// 

// picrc.cpp : SCSI SBC-3 Protection Information CRC generator
// #include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
/* return crc value */

/* function prototype */
unsigned short calculate_crc(unsigned char *, unsigned long);

unsigned short calculate_crc(unsigned char *frame, unsigned long length) 
{
	unsigned short const poly = 0x8BB7L; /* Polynomial */
	unsigned const int poly_length = 16;
	unsigned short crc_gen;
	unsigned short x;
	unsigned int i, j, fb;
	unsigned const int invert = 0;/* 1=seed with 1s and invert the CRC */
	crc_gen = 0x0000;
	crc_gen ^= invert? 0xFFFF: 0x0000; /* seed generator */

	for (i = 0; i < length; i += 2) {
		/* assume little endian */
		x = (frame[i] << 8) | frame[i+1];
		/* serial shift register implementation */
		for (j = 0; j < poly_length; j++) {
			fb = ((x & 0x8000L) == 0x8000L) ^ ((crc_gen & 0x8000L) == 0x8000L);
			x <<= 1;
			crc_gen <<= 1;
			if (fb)
			crc_gen ^= poly;
		}
	}
	return crc_gen ^ (invert? 0xFFFF: 0x0000); /* invert output */
} /* calculate_crc */

void main (void) 
{
	unsigned char *buffer;
	unsigned long buffer_size = 32;
	unsigned short crc;
	unsigned int i;

	/* 32 0x00 */
	buffer = (unsigned char *) malloc (buffer_size);
	for (i = 0; i < buffer_size; i++) {
		buffer[i] = 0x00;
	}
	crc = calculate_crc(buffer, buffer_size);
	printf ("Example CRC all-zeros is %04x\n", crc);
	free (buffer);


	/* 32 0xFF */
	buffer = (unsigned char *) malloc (buffer_size);
	for (i = 0; i < buffer_size; i++) {
		buffer[i] = 0xFF;
	}
	crc = calculate_crc(buffer, buffer_size);
	printf ("Example CRC all-ones is %04x\n", crc);
	free (buffer);
	/* 0x00 incrementing to 0x1F */
	buffer = (unsigned char *) malloc (buffer_size);
	for (i = 0; i < buffer_size; i++) {
		buffer[i] = i;
	}
	crc = calculate_crc(buffer, buffer_size);
	printf ("Example CRC incrementing is %04x\n", crc);
	free (buffer);


	/* 0xFF 0xFF then 30 zeros */
	buffer = (unsigned char *) malloc (buffer_size);
	buffer[0] = 0xff;
	buffer[1] = 0xff;
	for (i = 2; i < buffer_size; i++) {
		buffer[i] = 0x00;
	}
	crc = calculate_crc(buffer, buffer_size);
	printf ("Example CRC FF FF then 30 zeros is %04x\n", crc);
	free (buffer);


	/* 0xFF decrementing to 0xE0 */
	buffer = (unsigned char *) malloc (buffer_size);
	for (i = 0; i < buffer_size; i++) {
		buffer[i] = 0xff - i;
	}
	crc = calculate_crc(buffer, buffer_size);
	printf ("Example CRC FF decrementing to E0 is %04x\n", crc);
	free (buffer);
} 



