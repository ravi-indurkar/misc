//
// RAVIII created on Thu Jan  8 16:33:14 PST 2015
// 
// gcc -o pillar_crcarray_t10dif pillar_crcarray_t10dif.c
// $ ./pillar_crcarray_t10dif
// is sizeof-short = 16 = 2
// crc = 0x0
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned short globalcrcArrayTable[256] = {
   0x0000,0x8bb7,0x9cd9,0x176e,0xb205,0x39b2,0x2edc,0xa56b,0xefbd,0x640a,
   0x7364,0xf8d3,0x5db8,0xd60f,0xc161,0x4ad6,0x54cd,0xdf7a,0xc814,0x43a3,
   0xe6c8,0x6d7f,0x7a11,0xf1a6,0xbb70,0x30c7,0x27a9,0xac1e,0x0975,0x82c2,
   0x95ac,0x1e1b,0xa99a,0x222d,0x3543,0xbef4,0x1b9f,0x9028,0x8746,0x0cf1,
   0x4627,0xcd90,0xdafe,0x5149,0xf422,0x7f95,0x68fb,0xe34c,0xfd57,0x76e0,
   0x618e,0xea39,0x4f52,0xc4e5,0xd38b,0x583c,0x12ea,0x995d,0x8e33,0x0584,
   0xa0ef,0x2b58,0x3c36,0xb781,0xd883,0x5334,0x445a,0xcfed,0x6a86,0xe131,
   0xf65f,0x7de8,0x373e,0xbc89,0xabe7,0x2050,0x853b,0x0e8c,0x19e2,0x9255,
   0x8c4e,0x07f9,0x1097,0x9b20,0x3e4b,0xb5fc,0xa292,0x2925,0x63f3,0xe844,
   0xff2a,0x749d,0xd1f6,0x5a41,0x4d2f,0xc698,0x7119,0xfaae,0xedc0,0x6677,
   0xc31c,0x48ab,0x5fc5,0xd472,0x9ea4,0x1513,0x027d,0x89ca,0x2ca1,0xa716,
   0xb078,0x3bcf,0x25d4,0xae63,0xb90d,0x32ba,0x97d1,0x1c66,0x0b08,0x80bf,
   0xca69,0x41de,0x56b0,0xdd07,0x786c,0xf3db,0xe4b5,0x6f02,0x3ab1,0xb106,
   0xa668,0x2ddf,0x88b4,0x0303,0x146d,0x9fda,0xd50c,0x5ebb,0x49d5,0xc262,
   0x6709,0xecbe,0xfbd0,0x7067,0x6e7c,0xe5cb,0xf2a5,0x7912,0xdc79,0x57ce,
   0x40a0,0xcb17,0x81c1,0x0a76,0x1d18,0x96af,0x33c4,0xb873,0xaf1d,0x24aa,
   0x932b,0x189c,0x0ff2,0x8445,0x212e,0xaa99,0xbdf7,0x3640,0x7c96,0xf721,
   0xe04f,0x6bf8,0xce93,0x4524,0x524a,0xd9fd,0xc7e6,0x4c51,0x5b3f,0xd088,
   0x75e3,0xfe54,0xe93a,0x628d,0x285b,0xa3ec,0xb482,0x3f35,0x9a5e,0x11e9,
   0x0687,0x8d30,0xe232,0x6985,0x7eeb,0xf55c,0x5037,0xdb80,0xccee,0x4759,
   0x0d8f,0x8638,0x9156,0x1ae1,0xbf8a,0x343d,0x2353,0xa8e4,0xb6ff,0x3d48,
   0x2a26,0xa191,0x04fa,0x8f4d,0x9823,0x1394,0x5942,0xd2f5,0xc59b,0x4e2c,
   0xeb47,0x60f0,0x779e,0xfc29,0x4ba8,0xc01f,0xd771,0x5cc6,0xf9ad,0x721a,
   0x6574,0xeec3,0xa415,0x2fa2,0x38cc,0xb37b,0x1610,0x9da7,0x8ac9,0x017e,
   0x1f65,0x94d2,0x83bc,0x080b,0xad60,0x26d7,0x31b9,0xba0e,0xf0d8,0x7b6f,
   0x6c01,0xe7b6,0x42dd,0xc96a,0xde04,0x55b3
};

#define NUM_BITS (8 * sizeof(unsigned short))

unsigned short crcT10Dif( char *message, unsigned int nBytes )
{
   unsigned char  data;
   unsigned int byte;
   unsigned short crcRetval;
   

   /* Do the division */
   for ( byte = 0; byte < nBytes; ++byte )
   {
      data = (message[byte]) ^ (crcRetval >> (NUM_BITS - 8));
      crcRetval = globalcrcArrayTable[data] ^ (crcRetval << 8);
   }

   return crcRetval;
} 

main()
{
	unsigned short crc;
	char *user_data;

	printf("is sizeof-short = 16 = %d\n", sizeof(unsigned short));
	user_data = (char*)malloc(520);
	memset ((char*)user_data, 0, 520);
	crc = crcT10Dif( (char*)user_data, 512);
	printf("crc = 0x%x\n", crc);
}

