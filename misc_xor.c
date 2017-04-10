----------------------
 1. Higher 48 thru 63 bits set see misc/all-bits-either-zero-or-one.cpp
 2. Balance brackets ands braces ({[]}) see misc/bracket_balanced.c
 3. balance an unbalanced tree    unbal_to_bal_bst.cpp
 4. Delete Remove node from Binary tree
 5. Is linked-list circular infinite for-ever  Tortoise Hare
 6. delete nth from last for single-linked-list delete_nth_from_last_in_single_linked.c
 7. delete from middle of single-linked-list delete_middle_from_single_linked.c

delete_nth_from_last_in_single_linked
delete_treenode
----------------------
http://www.programmerinterview.com/
http://www.geeksforgeeks.org/   tags amazon etc
http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm
http://www.sparknotes.com/cs/searching/hashtables/section1.html
https://www.hackerrank.com/domains/algorithms/warmup
pillar fs2-x5
Intel Xeon E5-2699V3 18 cores  (two such CPUs gives 36 cores)

SAS3 HBA PMCSierra chip Thebes3 with 16 ports

Flash SSD SAS 10K RPM 3.5 Inch 4teraByte sequential 180MB/s (ie, in 1 second
it can read sequential 360,000 blocks sequentially

Dell EqualLogic PS-M4110 Blade Arrays and PowerEdge M1000e blade chassis

Hybrid:
nimble    tegile   tintri-shunIBM   emc-XtremeIO
Netapp  emc-XtremeIO   hitachi/Bluearc    dell-compellent

All FLASH:
software: fusionIO-goneBAD  violin-goneBAD  avere  Purestorage
hardware: Pliant, SandForce, Virident, Texas Memory Systems, and emc-XtremIO

----------------------
SPEC-SFS  or SPC
for NAS: NFS-or-CIFS  run SpecFS
for SAN: iscsi-or-FC  run SPC.   Pillar gets 95k iops on standard workload,
    you cannot change if you want to submit to standard for publishing, but
	for internal testing, SPC is very similar to IOMETER
----------------------
SSD SLC versus MLC 

SLC(single layer): High perf, high cost, high life.
MLC(Multi  layer): low perf, low cost, low life

1. CapacityMLC SSD  (slow)   => MLC_SSD ( used for read intensive, so write once,
                                    read many, backup, big capacity 2TB HGST sunset cove)
2. PerformanceSLC SSD        => SLC_SSD ( write is fast, but low capacity, 400GB, HGST SSD)
3. Capacity/Nearline Disk => NEARLINE_HDD
4. Performance Disk       => PERF_HDD

-------------------
pillar NVRAM is not NVRAM but regular DRAM, with FLASH-memory at the backend, and 
special power-shut electronic circuit in-between. Only on sudden power-loss, NVRAM/DRAM is stored
into the FLASH.
In release r6 each instance got 2M to store DIL-entry and  40M for actual data-buffer
In release r7 each instance got 2M to store DIL-entry and 300M shared between all instances for actual data-buffer
----------------------
disk full space quota  DISK FULL SPACE QUOTA
1. at any pwd, any dir; just issue "df -k . "  and see if it is 90%
Filesystem           1K-blocks      Used Available Use% Mounted on
cadv10-as52:/export/build1
                     520695936 433733216  60512896  88% /nfs/cadv10-build1
2. cd to your tree /nfs/cadv10-build1/rindurka  and "du -k . > /tmp/myfile &"

50G is ideal. One unbuild-source tree takes 2G (2406548 du -k) and the same
tree with binarys when fully built tree takes 18G (18050580 du -k)
Most of the space is consumed by "build/bin"
Very last line of du shows xxx Kb
80837292    .     Here I am using 80837292 K ie. 80G, allowed is 50G

----------------------
DEDUPLICATION deduplication
4 steps of dedup
1. chunking, fixed size or variable size, Variable size using rabin-rolling
2. create SHA256 unique signature for above chunk   (sha=secur hash algo)
3. search btree dictionary for above SHA-signature  (using bloom filter)
4. Save new/unsaved data blocks in block-map and enter into dictionary
----------------------
APPLE MACBOOKPRO 

VNC: go to terminal and type  open /System/Library/CoreServices
In that folder search for screen sharing.

OR  goto web-browser safari and type vnc://172.23.xx.xx

also see:
http://www.davidtheexpert.com/post.php?id=5


oracle vpn:  myaccess.oraclevpn.com  rindurka_us  
----------------------
storage Scale:

KB, MB, GB, TB, Peta, Exa, Zetta, Yotta

1 Gigabyte = 1 followed by 9 zeros

1 Terabyte = 1 followed by 12 zeros

1 Petabyte = 1 followed by 15 zeros

1 Exabyte = 1 followed by 18 zeros

1 Zettabyte = 1 followed by 21 zeros

1 Yottabyte = 1 followed by 24 zeros

----------------------
.bashrc alias
HISTIGNORE="&:ls:exit"
shopt -s cdspell
shopt -s no_empty_cmd_completion
shopt -s checkhash
shopt -s checkwinsize
findbigfiles()
{
    find / -mount \( -path /lib -o -path /usr/lib64 -o -path /usr/lib -o -path /usr/libexec -o -path /var/lib \) -prune -o -type f -size +10000k -exec ls -lh {} \; | awk '{ print $9 ": " $5 }'
}

----------------------
passwdless passwordless ssh authentication dsa rsa authorized_keys known_hosts
PASSWDLESS PASSWORDLESS SSH AUTHENTICATION DSA RSA AUTHORIZED_KEYS KNOWN_HOSTS
1. first step is to generate your ssh-key. I have it already under .ssh/authorized_keys
2. ssh into target machine and append/copy that key from your .ssh/authorized_keys into its .ssh/authorized_keys
/home/rindurka/.ssh/known_hosts
----------------------
export PS1="\u@\h:\w\$"
----------------------
# shell script example
#!/bin/bash
#set -x

function invoke_gdb
{
	# echo $1
	# echo $2
	# echo $3

	if [ $# -ne 3 ]; then
		echo "Usage: $0 core-file"
		echo "      binary = full path to the binary"
		echo "      core-file = full path to the core file"
		echo "      desktop_files = full path to the desktop files"
		echo "    Notes: this assumes running on a build machine or similar"
		exit 1
	fi      
	#       
	SDIR=$(cd $(dirname "$0"); pwd)
	echo ${SDIR}
		
	pwd
	gdb -ex "set debug-file-directory ${SDIR}/usr/lib/debug" -ex "set solib-absolute-prefix /dev/null" -ex "set solib-search-path $3" -ex "file $1" -ex "core-file $2"

}

##  This is main
if [ $#  == 0 ] ; then
   echo "No arguments specified, Please specify 0 or 1"
   exit
fi
pwd
echo "^C   ^C    Are you in test0, 1 or 2 ?   ^C   ^C    "
read xxx

if [ $1 == 0 ] ; then
   echo "GDB node0"
	invoke_gdb ../bin/raidfmtest ./raidfmtest.core ../lib64/
else
	echo "GDB node2"
	invoke_gdb ../bin/raidfmtest ./node2/raidfmtest.core ../lib64/
fi

---------------------------------
# .bashrc  with date-time-stamp-macro-for-file-logs

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
        . ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/bin:.
ulimit -c unlimited

export P4PORT="capf02.us.oracle.com:1666"
export P4CONFIG=".p4client"
export P4DIFF="diff -u"
export P4EDITOR="vim"
export P4MERGE="vim"
export PDSMSG_DEST_IP2=10.129.44.74

alias raidc0='nc -U /var/sock/raidconsole0.sock'
ravilog()
{
	mytimestamp=$(date +%F-%H:%M:%S)
	mv /tmp/raviii_raidlog.txt /tmp/raviii_raidlog.txt.$mytimestamp
	touch /tmp/raviii_raidlog.txt
	ls -al /tmp/raviii_raidlog.txt
	filesize=$(ls -al /tmp/raviii_raidlog.txt | awk '{print $5 }')

	# echo RAVIII TIME_BEFORE
	# echo $mytimestamp
	# echo $filesize
	# echo $mytimestamp

	while (( $filesize == 0 ))
	do 
		nc -U /var/sock/raidconsole0.sock >> /tmp/raviii_raidlog.txt
		ls -al /tmp/raviii_raidlog.txt
		date
		filesize=$(ls -al /tmp/raviii_raidlog.txt | awk '{print $5 }')
		sleep 1
	done
	mytimestamp=$(date +%F-%H:%M:%S)
	mv /tmp/raviii_raidlog.txt /tmp/raviii_raidlog.txt.$mytimestamp
}

# Function to automatically debug the last core which was generated in /tmp
# Must be run from Sidrat/bin directory to find raidfmtest executable!
rdebug()
{
        core=$(ll -tr /tmp | grep 'core' | tail -n1 | grep -o 'core.*')
        rtest="../../../storm/test/linux-x86_64.o/raidfmtest"
        if [ -e "$rtest" ] ; then
                gdb -c /tmp/$core ../../../storm/test/linux-x86_64.o/raidfmtest -x dot-gdbinit
        else
                echo "Not in Sidrat/bin directory!"
        fi
}

----------------------
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
if (unlikely(psSI->flags & OtherControllerIsDown))
{
    panic();
}

#define MY_COUNT_HOW_MANY_BITS_ARE_SET(x)   __builtin_popcountl(x)  
#define MY_FIND_FIRST_SET(x)                (__builtin_ffsl(x) - 1)
#define MY_FIND_LAST_SET_ASSUMING_UINT64(x)  (64 - __builtin_clzl(x) -1 )

#define MY_COUNT_HOW_MANY_BITS_ARE_SET(x)   my_which_bitpos_is_set(x)

void my_which_bitpos_is_set( unsigned long mylong)
{
	int i, is_this_bit_set=0;
	for (i=0; i<sizeof(unsigned long); i++) {
		is_this_bit_set = is_this_bitpos_set( mylong, i);
		if ( is_this_bit_set ) printf(" %d ", i);
	}
	printf("\n");
}
int is_this_bitpos_set(unsigned long mylong, int bitpos)
{
    return mylong & (1ULL << bitpos);
}

----------------------
/usr/bin/wget -h -r
wget http://ca-appsvr-03.us.oracle.com:81/0/AK00080324/A136007F0369772D/A136007F0369772D.tds.tar.gz
----------------------
vi vim emacs VI VIM EMACS 
In vi To match #ifdef   [#  or ]#
vi -O file1  file2  for middle-page horizontal split
vi -o file1  file2  for vertical split
in vi  to split   :split  and to toggle CTRLW-CTRLW
CTRL W  h j k l
CTRL W  +  -  <  >  to increase size
CTRL v  and yank visual block

in vi to search blank lines 
/^$

   :%g/^$/d    to delete blank lines
	:%g/anyPattern/d    to delete anyPattern

:%s,oldpatern,newpatern,g
:%s/oldpatern/newpatern/g
-------------------------------------------
cut paste from windows vnc
vncserver -geometry 1280x1024 :50
vncconfig -nowin &
-------------------------------------------
to get color in vi, just use vim  alias vi=vim
-------------------------------------------
awk AWK
most common usage of awk is almost always as follows:

awk '{   print $1 $2 $3 $4 }'

kill -9 `ps -afe | grep MYTEXT | awk '{print $2}' `
ps -afe | awk /"123"/

to create/make new side-by-side column
cat foo | awk '{print $1" "$1}' > feee
-------------------------------------------
csh ksh bash history
CTRL R followed by "your search command", and
press right or left arrow to edit, or keep pressing CTRL R for next occurance
-------------------------------------------
TEE tee
(date|awk '{printf $4" "}' && echo -e $1) | tee -a /tmp/x
-------------------------------------------
indent INDENT cbeautify  CBEAUTIFY
indent file.c   and the options are in ~/.indent.pro
-------------------------------------------
grep -i "abcd\|xyz\|rstuv" file.txt
grep -i "SRB:336\|CmdRef 0xafe\|25397860\|c9bb90\|7f5a4bc88640\|7f5a49a6b088\|7f5a4c26cab8\|7f5a4baf6040" x.txt

show something | grep -A 5 -B 2 -i myGREPtextHERE
-------------------------------------------
rdesktop 10.250.241.9 -f -u Ravi_Indurkar -d ocarina and then CTRL+ALT+ENTER
rm ~/.rdesktop/licence.ravi-desktop
-------------------------------------------
CSCOPE FIND cscope find
find . -iname "output-*.txt" | xargs grep -i -e 'MaintOp_Start' -e 'Maintxyz' 

find . -name "*.[ch]" -exec fgrep -l YOUR_SEARCH_PATTERN_HERE {} \;

to create your own cscope database:
find . -name "*.[ch]" > cscope.files
find . -name "*.cc" >> cscope.files
find . -name "*.hh" >> cscope.files
find . -name "*.asm" >> cscope.files
find . -name "*.S" >> cscope.files

cscope -b -i cscope.files -q

ctags -L cscope.files

-----------------------------------------------------------------------------
DLOPEN
    my_type_t retptr;
    handle = dlopen( "/usr/lib/libpfm.so", RTLD_LAZY);
    if (!handle) {
        fprintf (stderr, "%s:%d dlopen failed for %s. Error:%s\n",
            __FUNCTION__, __LINE__, "usr/lib/libpfm.so", dlerror());
        return (ERROR-1);
    }

    retptr = dlsym( handle, "card_index_sw_card_id_table");
    if (((error = dlerror()) != NULL) || (retptr == NULL))  {
        fprintf (stderr,
                "%s:%d card_index_sw_card_id_table not found. Error:%s\n",
                __FUNCTION__, __LINE__, error);
        return (ERROR-1);
    }
    /* start using retptr */
    If (retptr->sw_card_id == SW_CARD_ID_UNKNOWN) .....

-------------------------------------------
Initial boot device discovery
TUR test unit ready
	SENSE_KEY=unit_attn(0x6) addSenseCode=0x29 (power-on reset)
RE-issue TUR test unit ready re-issue
	SENSE_KEY=not-ready(0x2)
SCSI_START_STOP_UNIT 0x1B startbit=1
SCSI_INQUIRY_6 0x12 get Model,SerialNumber, and inquiry-page-code-0x80
READCAPA  to get T10DIF-PI byte 12
	Determine blocksize (usually 512) plus +8 if T10IDFbit12 set
	Determine LAST-LBA
SecurityProtocolIn 0xA2 securityProtocol=1,inc512=0x80  Determine Encrypt support
	set flag Encrypt/not-Encrypt
DummyRead LBA=0, len=1
	set flag Locked/Unlocked
GetMSID     GetMSID is a state-machine as follows: StartSession, GetMSID, EndSession
	StartSession
		Issue ProtoOUT with StartSession
		Issue ProtoIN  copy remember SessionID
	GetMSID
		Issue ProtoOUT with GetMSID and PreviousStartSessionID
		Issue ProtoIN  copy remember 32 UINT8 msid[32]  (32-single-bytes; sixteenth-sector worth, 256 bits)
	EndSession
		Issue ProtoOUT with EndSession and PreviousStartSessionID
		Issue ProtoIN  do nothing, just check for errors 
In the meantime get Global_key_band0  and User_key_band1
Unlock_band0  and 1   Unlock is a state-machine as follows: StartSession, Authenticate, Unlock, EndSession
	StartSession
		Issue ProtoOUT with StartSession
		Issue ProtoIN  copy remember SessionID
	Authenticate
		Issue ProtoOUT with AuthenticateCmd BMID[0 or 1] and PreviousStartSessionID
		Issue ProtoIN  check for authenticate error
	Unlock
		Issue ProtoOUT with UnlockCmd band0 or 1  and PreviousStartSessionID
		Issue ProtoIN  check for unlocking error
	EndSession
		Issue ProtoOUT with EndSession and PreviousStartSessionID
		Issue ProtoIN  do nothing, just check for errors 


MSID is (uchar*32) ie. 32 bytes, sixteenth-sector worth, 256 bits 
  8 bits,  1 byte, char
 32 bits,  4 byte, int
 64 bits,  8 byte, double, WWN 1_long, 2_ints  sse-mm0 WWN  (2 ints)
128 bits, 16 byte, long-long  SSE-XMM0  (4_ints)
256 bits, 32 byte, sixteenth-a-sector, 8_ints MSID <<== 32-single-bytes 

-------------------------------------------
SSE sse Streaming SIMD Extension   SIMD Single Instruction Multiple Data
http://www.codeproject.com/Articles/8440/Using-SSE-SSE-for-optimization
http://www.tommesani.com/index.php/simd/46-sse-arithmetic.html
http://neilkemp.us/src/sse_tutorial/sse_tutorial.html
http://joryanick.com/retro/memcpy.htm
https://www.cs.fsu.edu/~engelen/courses/HPC-adv/MMXandSSEexamples.txt

-------------------------------------------
SCSI READ16 WRITE16 CDB

 _______________________________________________
|     |     |     |     |     |     |     |     |
| RD      8             |        8              |
| WR      8             |        A              |  0
|     |     |     |     |     |     |     |     |
 _______________________________________________
|     |     |     |     |     |     |     |     |
|  WR/RD protect  | DPO | FUA | RSV | FUA | RSV |  1
|     |     |     |     |     |     |     |     |
 _______________________________________________
|     |     |     |     |     |     |     |     |
|     |     |     |     |     |     |     |     |
|     |     |     |     |     |     |     |     |
|        int64  LBA64                           |  2,3,4,5  6,7,8,9
|     |     |     |     |     |     |     |     |
|     |     |     |     |     |     |     |     |
|     |     |     |     |     |     |     |     |
 _______________________________________________
|     |     |     |     |     |     |     |     |
|     |     |     |     |     |     |     |     |
|        int32  length                          |  10,11,12,13
|     |     |     |     |     |     |     |     |
|     |     |     |     |     |     |     |     |
 _______________________________________________
|     |     |     |     |     |     |     |     |
|                    misc                       |  14
|     |     |     |     |     |     |     |     |
 _______________________________________________
|     |     |     |     |     |     |     |     |
|                  control                      |  15
|     |     |     |     |     |     |     |     |
 _______________________________________________


Data Storage: What is the difference between the SCSI UNMAP command and the WRITE SAME command with the unmap bit set?
What is the difference (if any) between the SCSI UNMAP command and the WRITE SAME command with the unmap bit set? I am trying to understand the behavior of the storage array when either of these commands is sent by a host.
Answer: SCSI UNMAP is used to UNMAP the specified blocks. This is part of the Thin provisioning story of SCSI. Where as WRITE_SAME is different as it is a write operation with specified pattern. WRITE_SAME with unmap bit set tells the device server that it MAY optimize the write operation by unmapping the blocks. It is honored only when the two conditions are met: 1. when the pattern in WRITE_SAME is all zeros and 2. the device server implementation says "I return zeros for unmapped blocks".

-------------------------------------------
SCSI OPCODES scsi opcodes

oracle-pillar create-raid using SCSI-send-diag 0x1d 0x1D pagecode:0x93
oracle-pillar display-raid-status using SCSI-mode-sense 0x1a/0x5a pagecode:0x22

#define     SCSI_READ_6                             0x08
#define     SCSI_READ_10                            0x28
#define     SCSI_READ_12                            0xA8
#define     SCSI_READ_16                            0x88
#define     SCSI_READ_RAID_10_SINGLE                0xF8

#define     SCSI_READ_CAPACITY_10                   0x25
#define     SCSI_READ_CAPACITY_16                   0x9E

#define     SCSI_SEND_DIAGNOSTIC                    0x1D
#define     SCSI_RECEIVE_DIAGNOSTIC                 0x1C

#define     SCSI_INQUIRY_6                          0x12

#define     SCSI_LOG_SENSE                          0x4D
#define     SCSI_LOG_SELECT                         0x4C

#define     SCSI_MODE_SELECT_6                      0x15
#define     SCSI_MODE_SELECT_10                     0x55

#define     SCSI_MODE_SENSE_6                       0x1A
#define     SCSI_MODE_SENSE_10                      0x5A

#define     SCSI_REPORT_LUNS_12                     0xA0
#define     SCSI_REPORT_TARGET_PORT                 0xA3


SCSI Operation Codes
Numeric Sorted Listing
as of  5/10/12

    D - DIRECT ACCESS DEVICE (SBC-3)                   device column key
    .T - SEQUENTIAL ACCESS DEVICE (SSC-3)             -------------------
    . L - PRINTER DEVICE (SSC)                        M = Mandatory
    .  P - PROCESSOR DEVICE (SPC-2)                   O = Optional
    .  .W - WRITE ONCE READ MULTIPLE DEVICE (SBC)     V = Vendor specific
    .  . R - C/DVD DEVICE (MMC-6)                     Z = Obsolete
    .  .  O - OPTICAL MEMORY DEVICE (SBC)
    .  .  .M - MEDIA CHANGER DEVICE (SMC-3)
    .  .  . A - STORAGE ARRAY DEVICE (SCC-2)
    .  .  . .E - ENCLOSURE SERVICES DEVICE (SES-2)
    .  .  .  .B - SIMPLIFIED DIRECT-ACCESS DEVICE (RBC)
    .  .  .  . K - OPTICAL CARD READER/WRITER DEVICE (OCRW)
    .  .  .  .  V - AUTOMATION/DRIVE INTERFACE (ADC-2)
    .  .  .  .  .F - OBJECT-BASED STORAGE (OSD-2)
OP  DTLPWROMAEBKVF  Description
--  --------------  ----------------------------------------------------
00  MMMMMMMMMMMMMM  TEST UNIT READY
01   M              REWIND
01  Z V ZZZZ        REZERO UNIT
02  VVVVVV V
03  MMMMMMMMMMOMMM  REQUEST SENSE
04  M    OO         FORMAT UNIT
04   O              FORMAT MEDIUM
04    O             FORMAT
05  VMVVVV V        READ BLOCK LIMITS
06  VVVVVV V
07  OVV O OV        REASSIGN BLOCKS
07         O        INITIALIZE ELEMENT STATUS
08  ZMV O OV        READ(6)
08     O            RECEIVE
08                  GET MESSAGE(6)
09  VVVVVV V
0A  ZO  O OV        WRITE(6)
0A     M            SEND(6)
0A                  SEND MESSAGE(6)
0A    M             PRINT
0B  Z   ZOZV        SEEK(6)
0B   O              SET CAPACITY
0B    O             SLEW AND PRINT
0C  VVVVVV V
0D  VVVVVV V
0E  VVVVVV V
0F  VOVVVV V        READ REVERSE(6)
10  VM VVV          WRITE FILEMARKS(6)
10    O             SYNCHRONIZE BUFFER
11  VMVVVV          SPACE(6)
12  MMMMMMMMMMMMMM  INQUIRY
13  V VVVV
13   O              VERIFY(6)
14  VOOVVV          RECOVER BUFFERED DATA
15  OMO O OOOO OO   MODE SELECT(6)
16  ZZMZO OOOZ O    RESERVE(6)
16         Z        RESERVE ELEMENT(6)
17  ZZMZO OOOZ O    RELEASE(6)
17         Z        RELEASE ELEMENT(6)
18  ZZZZOZO    Z    COPY
19  VMVVVV          ERASE(6)
1A  OMO O OOOO OO   MODE SENSE(6)
1B  O   OOO O MO O  START STOP UNIT
1B   O          M   LOAD UNLOAD
1B                  SCAN
1B    O             STOP PRINT
1B         O        OPEN/CLOSE IMPORT/EXPORT ELEMENT
1C  OOOOO OOOM OOO  RECEIVE DIAGNOSTIC RESULTS
1D  MMMMM MMOM MMM  SEND DIAGNOSTIC
1E  OO  OOOO   O O  PREVENT ALLOW MEDIUM REMOVAL
1F
20  V   VVV    V
21  V   VVV    V
22  V   VVV    V
23  V   V V    V
23       O          READ FORMAT CAPACITIES
24  V   VV          SET WINDOW
25  M   M M   M     READ CAPACITY(10)
25       O          READ CAPACITY
25             M    READ CARD CAPACITY
25                  GET WINDOW
26  V   VV
27  V   VV
28  M   MOM   MM    READ(10)
28                  GET MESSAGE(10)
29  V   VVO         READ GENERATION
2A  O   MOM   MO    WRITE(10)
2A                  SEND(10)
2A                  SEND MESSAGE(10)
2B  Z   OOO    O    SEEK(10)
2B   M              LOCATE(10)
2B         O        POSITION TO ELEMENT
2C  V    OO         ERASE(10)
2D        O         READ UPDATED BLOCK
2D  V
2E  O   OOO   MO    WRITE AND VERIFY(10)
2F  O   OOO         VERIFY(10)
30  Z   ZZZ         SEARCH DATA HIGH(10)
31  Z   ZZZ         SEARCH DATA EQUAL(10)
31                  OBJECT POSITION
32  Z   ZZZ         SEARCH DATA LOW(10)
33  Z   OZO         SET LIMITS(10)
34  O   O O    O    PRE-FETCH(10)
34   M              READ POSITION
34                  GET DATA BUFFER STATUS
35  O   OOO   MO    SYNCHRONIZE CACHE(10)
36  Z   O O    O    LOCK UNLOCK CACHE(10)
37  O     O         READ DEFECT DATA(10)
37         O        INITIALIZE ELEMENT STATUS WITH RANGE
38      O O    O    MEDIUM SCAN
39  ZZZZOZO    Z    COMPARE
3A  ZZZZOZO    Z    COPY AND VERIFY
3B  OOOOOOOOOOMOOO  WRITE BUFFER
3C  OOOOOOOOOO OOO  READ BUFFER
3D        O         UPDATE BLOCK
3E  O   O O         READ LONG(10)
3F  O   O O         WRITE LONG(10)
40  ZZZZOZOZ        CHANGE DEFINITION
41  O               WRITE SAME(10)
42  O               UNMAP
42       O          READ SUB-CHANNEL
43       O          READ TOC/PMA/ATIP
44   M          M   REPORT DENSITY SUPPORT
44                  READ HEADER
45       O          PLAY AUDIO(10)
46       M          GET CONFIGURATION
47       O          PLAY AUDIO MSF
48  O         O     SANITIZE
49
4A       M          GET EVENT STATUS NOTIFICATION
4B       O          PAUSE/RESUME
4C  OOOOO OOOO OOO  LOG SELECT
4D  OOOOO OOOO OMO  LOG SENSE
4E       O          STOP PLAY/SCAN
4F
50  Z               XDWRITE(10)
51  O               XPWRITE(10)
51       O          READ DISC INFORMATION
52  Z               XDREAD(10)
52       O          READ TRACK INFORMATION
53  O               XDWRITEREAD(10)
53       O          RESERVE TRACK
54       O          SEND OPC INFORMATION
55  OOO OMOOOOMOMO  MODE SELECT(10)
56  ZZMZO OOOZ      RESERVE(10)
56         Z        RESERVE ELEMENT(10)
57  ZZMZO OOOZ      RELEASE(10)
57         Z        RELEASE ELEMENT(10)
58       O          REPAIR TRACK
59
5A  OOO OMOOOOMOMO  MODE SENSE(10)
5B       O          CLOSE TRACK/SESSION
5C       O          READ BUFFER CAPACITY
5D       O          SEND CUE SHEET
5E  OMOOO OOOO   M  PERSISTENT RESERVE IN
5F  OMOOO OOOO   M  PERSISTENT RESERVE OUT
7E  OO   O OOOO O   extended CDB
7F  O            M  variable length CDB (more than 16 bytes)
80  Z               XDWRITE EXTENDED(16)
80   M              WRITE FILEMARKS(16)
81  Z               REBUILD(16)
81   O              READ REVERSE(16)
82  Z               REGENERATE(16)
82   O              ALLOW OVERWRITE
83  OOOOO O    OO   Third-party Copy OUT
84  OOOOO O    OO   Third-party Copy IN
85  O         O     ATA PASS-THROUGH(16)
86  OO OO OOOOOOO   ACCESS CONTROL IN
87  OO OO OOOOOOO   ACCESS CONTROL OUT
88  MO  O O   O     READ(16)
89  O               COMPARE AND WRITE
8A  OO  O O   O     WRITE(16)
8B  O               ORWRITE
8C  OO  O OO  O M   READ ATTRIBUTE
8D  OO  O OO  O O   WRITE ATTRIBUTE
8E  O   O O   O     WRITE AND VERIFY(16)
8F  OO  O O   O     VERIFY(16)
90  O   O O   O     PRE-FETCH(16)
91  O   O O   O     SYNCHRONIZE CACHE(16)
91   O              SPACE(16)
92  Z   O O         LOCK UNLOCK CACHE(16)
92   M              LOCATE(16)
93  O               WRITE SAME(16)
93   M              ERASE(16)
94                  [usage proposed by SCSI Socket Services project]
95                  [usage proposed by SCSI Socket Services project]
96                  [usage proposed by SCSI Socket Services project]
97                  [usage proposed by SCSI Socket Services project]
98
99
9A
9B
9C
9D                  SERVICE ACTION BIDIRECTIONAL
9E                  SERVICE ACTION IN(16)
9F              M   SERVICE ACTION OUT(16)
A0  MMOOO OMMM OMO  REPORT LUNS
A1       O          BLANK
A1  O         O     ATA PASS-THROUGH(12)
A2  OO   O      O   SECURITY PROTOCOL IN
A3  OOO O OOMOOOM   MAINTENANCE IN
A3       O          SEND KEY
A4  OOO O OOOOOOO   MAINTENANCE OUT
A4       O          REPORT KEY
A5   Z  O OM        MOVE MEDIUM
A5       O          PLAY AUDIO(12)
A6         O        EXCHANGE MEDIUM
A6       O          LOAD/UNLOAD C/DVD
A7  ZZ  O O         MOVE MEDIUM ATTACHED
A7       O          SET READ AHEAD
A8  O   OOO         READ(12)
A8                  GET MESSAGE(12)
A9              O   SERVICE ACTION OUT(12)
AA  O   OOO         WRITE(12)
AA                  SEND MESSAGE(12)
AB       O      O   SERVICE ACTION IN(12)
AC        O         ERASE(12)
AC       O          GET PERFORMANCE
AD       O          READ DVD STRUCTURE
AE  O   O O         WRITE AND VERIFY(12)
AF  O   O O         VERIFY(12)
B0      ZZZ         SEARCH DATA HIGH(12)
B1      ZZZ         SEARCH DATA EQUAL(12)
B2      ZZZ         SEARCH DATA LOW(12)
B3  Z   OZO         SET LIMITS(12)
B4  ZZ  OZO         READ ELEMENT STATUS ATTACHED
B5  OO   O      O   SECURITY PROTOCOL OUT
B5         O        REQUEST VOLUME ELEMENT ADDRESS
B6         O        SEND VOLUME TAG
B6       O          SET STREAMING
B7  O     O         READ DEFECT DATA(12)
B8   Z  OZOM        READ ELEMENT STATUS
B9       O          READ CD MSF
BA  O   O OOMO      REDUNDANCY GROUP (IN)
BA       O          SCAN
BB  O   O OOOO      REDUNDANCY GROUP (OUT)
BB       O          SET CD SPEED
BC  O   O OOMO      SPARE (IN)
BD  O   O OOOO      SPARE (OUT)
BD       O          MECHANISM STATUS
BE  O   O OOMO      VOLUME SET (IN)
BE       O          READ CD
BF  O   O OOOO      VOLUME SET (OUT)
BF       O          SEND DVD STRUCTURE
-------------------------------------------
SCSI-STATUS
#define     SCSI_STS_GOOD                           0
#define     SCSI_STATUS_CHECK_CONDITION             0x02
#define     SCSI_STATUS_CONDITION_MET               0x04
#define     SCSI_STATUS_BUSY                        0x08
#define     SCSI_STATUS_INTERMEDIATE                0x10
#define     SCSI_STATUS_INTERMEDIATE_COND           0x14
#define     SCSI_STATUS_RESERVATION_CONF            0x18
#define     SCSI_STATUS_COMMAND_TERMINATED          0x22
#define     SCSI_STATUS_TASK_SET_FULL               0x28

SCSI-SENSEKEY SENSECODE scsi-sensekey sensecode 
#define     SENSE_KEY_NO_SENSE                      0
#define     SENSE_KEY_RECOVD_ERROR                  0x01
#define     SENSE_KEY_NOT_READY                     0x02
#define     SENSE_KEY_MEDIUM_ERROR                  0x03
#define     SENSE_KEY_HWARE_ERROR                   0x04
#define     SENSE_KEY_ILLEGAL_REQ                   0x05
#define     SENSE_KEY_UNIT_ATTEN                    0x06
#define     SENSE_KEY_DATA_PROTECT                  0x07
#define     SENSE_KEY_BLANK_CHECK                   0x08
#define     SENSE_KEY_VENDOR_UNIQUE                 0x09
#define     SENSE_KEY_COPY_ABORT                    0x0A
#define     SENSE_KEY_ABORTED_CMD                   0x0B
#define     SENSE_KEY_VOL_OVERFLOW                  0x0D
#define     SENSE_KEY_MISCOMPARE                    0x0E

TEST-UNIT-READY  TUR:
0x6/0x29/0x1


http://www.t10.org/lists/asc-num.txt

File: ASC-NUM.TXT

SCSI ASC/ASCQ Assignments
Numeric Sorted Listing
as of  7/30/16

         D - Direct Access Block Device (SBC-4)             device column key
         .Z - Host Managed Zoned Block Device (ZBC)        -------------------
         . T - Sequential Access Device (SSC-5)               blank = reserved
         .  P - Processor Device (SPC-2)                   not blank = allowed
         .  .R - C/DVD Device (MMC-6)
         .  . O - Optical Memory Block Device (SBC)
         .  .  M - Media Changer Device (SMC-3)
         .  .  .A - Storage Array Device (SCC-2)
         .  .  . E - SCSI Enclosure Services device (SES-3)
         .  .  .  B - Simplified Direct-Access (Reduced Block) device (RBC)
         .  .  .  .K - Optical Card Reader/Writer device (OCRW)
         .  .  .  . V - Automation/Device Interface device (ADC-4)
         .  .  .  .  F - Object-based Storage Device (OSD-2)
ASC/ASCQ DZTPROMAEBKVF  Description
-------- -------------  ----------------------------------------------------
00h/00h  DZTPROMAEBKVF  NO ADDITIONAL SENSE INFORMATION
00h/01h    T            FILEMARK DETECTED
00h/02h    T            END-OF-PARTITION/MEDIUM DETECTED
00h/03h    T            SETMARK DETECTED
00h/04h    T            BEGINNING-OF-PARTITION/MEDIUM DETECTED
00h/05h    T            END-OF-DATA DETECTED
00h/06h  DZTPROMAEBKVF  I/O PROCESS TERMINATED
00h/07h    T            PROGRAMMABLE EARLY WARNING DETECTED
00h/11h      R          AUDIO PLAY OPERATION IN PROGRESS
00h/12h      R          AUDIO PLAY OPERATION PAUSED
00h/13h      R          AUDIO PLAY OPERATION SUCCESSFULLY COMPLETED
00h/14h      R          AUDIO PLAY OPERATION STOPPED DUE TO ERROR
00h/15h      R          NO CURRENT AUDIO STATUS TO RETURN
00h/16h  DZTPROMAEBKVF  OPERATION IN PROGRESS
00h/17h  DZT ROMAEBKVF  CLEANING REQUESTED
00h/18h    T            ERASE OPERATION IN PROGRESS
00h/19h    T            LOCATE OPERATION IN PROGRESS
00h/1Ah    T            REWIND OPERATION IN PROGRESS
00h/1Bh    T            SET CAPACITY OPERATION IN PROGRESS
00h/1Ch    T            VERIFY OPERATION IN PROGRESS
00h/1Dh  DZT      B     ATA PASS THROUGH INFORMATION AVAILABLE
00h/1Eh  DZT R MAEBKV   CONFLICTING SA CREATION REQUEST
00h/1Fh  DZT      B     LOGICAL UNIT TRANSITIONING TO ANOTHER POWER CONDITION
00h/20h  DZTP     B     EXTENDED COPY INFORMATION AVAILABLE
00h/21h  DZ             ATOMIC COMMAND ABORTED DUE TO ACA
01h/00h  DZ   O   BK    NO INDEX/SECTOR SIGNAL
02h/00h  DZ  RO   BK    NO SEEK COMPLETE
03h/00h  DZT  O   BK    PERIPHERAL DEVICE WRITE FAULT
03h/01h    T            NO WRITE CURRENT
03h/02h    T            EXCESSIVE WRITE ERRORS
04h/00h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, CAUSE NOT REPORTABLE
04h/01h  DZTPROMAEBKVF  LOGICAL UNIT IS IN PROCESS OF BECOMING READY
04h/02h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, INITIALIZING COMMAND REQUIRED
04h/03h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, MANUAL INTERVENTION REQUIRED
04h/04h  DZT RO   B     LOGICAL UNIT NOT READY, FORMAT IN PROGRESS
04h/05h  DZT  O A BK F  LOGICAL UNIT NOT READY, REBUILD IN PROGRESS
04h/06h  DZT  O A BK    LOGICAL UNIT NOT READY, RECALCULATION IN PROGRESS
04h/07h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, OPERATION IN PROGRESS
04h/08h      R          LOGICAL UNIT NOT READY, LONG WRITE IN PROGRESS
04h/09h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, SELF-TEST IN PROGRESS
04h/0Ah  DZTPROMAEBKVF  LOGICAL UNIT NOT ACCESSIBLE, ASYMMETRIC ACCESS STATE TRANSITION
04h/0Bh  DZTPROMAEBKVF  LOGICAL UNIT NOT ACCESSIBLE, TARGET PORT IN STANDBY STATE
04h/0Ch  DZTPROMAEBKVF  LOGICAL UNIT NOT ACCESSIBLE, TARGET PORT IN UNAVAILABLE STATE
04h/0Dh              F  LOGICAL UNIT NOT READY, STRUCTURE CHECK REQUIRED
04h/0Eh  DZT R MAEBKVF  LOGICAL UNIT NOT READY, SECURITY SESSION IN PROGRESS
04h/10h  DZT ROM  B     LOGICAL UNIT NOT READY, AUXILIARY MEMORY NOT ACCESSIBLE
04h/11h  DZT RO AEB VF  LOGICAL UNIT NOT READY, NOTIFY (ENABLE SPINUP) REQUIRED
04h/12h        M    V   LOGICAL UNIT NOT READY, OFFLINE
04h/13h  DZT R MAEBKV   LOGICAL UNIT NOT READY, SA CREATION IN PROGRESS
04h/14h  DZ       B     LOGICAL UNIT NOT READY, SPACE ALLOCATION IN PROGRESS
04h/15h        M        LOGICAL UNIT NOT READY, ROBOTICS DISABLED
04h/16h        M        LOGICAL UNIT NOT READY, CONFIGURATION REQUIRED
04h/17h        M        LOGICAL UNIT NOT READY, CALIBRATION REQUIRED
04h/18h        M        LOGICAL UNIT NOT READY, A DOOR IS OPEN
04h/19h        M        LOGICAL UNIT NOT READY, OPERATING IN SEQUENTIAL MODE
04h/1Ah  DZ       B     LOGICAL UNIT NOT READY, START STOP UNIT COMMAND IN PROGRESS
04h/1Bh  DZ       B     LOGICAL UNIT NOT READY, SANITIZE IN PROGRESS
04h/1Ch  DZT   MAEB     LOGICAL UNIT NOT READY, ADDITIONAL POWER USE NOT YET GRANTED
04h/1Dh  DZ             LOGICAL UNIT NOT READY, CONFIGURATION IN PROGRESS
04h/1Eh  DZ             LOGICAL UNIT NOT READY, MICROCODE ACTIVATION REQUIRED
04h/1Fh  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, MICROCODE DOWNLOAD REQUIRED
04h/20h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, LOGICAL UNIT RESET REQUIRED
04h/21h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, HARD RESET REQUIRED
04h/22h  DZTPROMAEBKVF  LOGICAL UNIT NOT READY, POWER CYCLE REQUIRED
04h/23h  DZ             LOGICAL UNIT NOT READY, AFFILIATION REQUIRED
05h/00h  DZT ROMAEBKVF  LOGICAL UNIT DOES NOT RESPOND TO SELECTION
06h/00h  DZ  ROM  BK    NO REFERENCE POSITION FOUND
07h/00h  DZT ROM  BK    MULTIPLE PERIPHERAL DEVICES SELECTED
08h/00h  DZT ROMAEBKVF  LOGICAL UNIT COMMUNICATION FAILURE
08h/01h  DZT ROMAEBKVF  LOGICAL UNIT COMMUNICATION TIME-OUT
08h/02h  DZT ROMAEBKVF  LOGICAL UNIT COMMUNICATION PARITY ERROR
08h/03h  DZT ROM  BK    LOGICAL UNIT COMMUNICATION CRC ERROR (ULTRA-DMA/32)
08h/04h  DZTPRO    K    UNREACHABLE COPY TARGET
09h/00h  DZT RO   B     TRACK FOLLOWING ERROR
09h/01h      RO    K    TRACKING SERVO FAILURE
09h/02h      RO    K    FOCUS SERVO FAILURE
09h/03h      RO         SPINDLE SERVO FAILURE
09h/04h  DZT RO   B     HEAD SELECT FAULT
09h/05h  DZT RO   B     VIBRATION INDUCED TRACKING ERROR
0Ah/00h  DZTPROMAEBKVF  ERROR LOG OVERFLOW
0Bh/00h  DZTPROMAEBKVF  WARNING
0Bh/01h  DZTPROMAEBKVF  WARNING - SPECIFIED TEMPERATURE EXCEEDED
0Bh/02h  DZTPROMAEBKVF  WARNING - ENCLOSURE DEGRADED
0Bh/03h  DZTPROMAEBKVF  WARNING - BACKGROUND SELF-TEST FAILED
0Bh/04h  DZTPRO AEBKVF  WARNING - BACKGROUND PRE-SCAN DETECTED MEDIUM ERROR
0Bh/05h  DZTPRO AEBKVF  WARNING - BACKGROUND MEDIUM SCAN DETECTED MEDIUM ERROR
0Bh/06h  DZTPROMAEBKVF  WARNING - NON-VOLATILE CACHE NOW VOLATILE
0Bh/07h  DZTPROMAEBKVF  WARNING - DEGRADED POWER TO NON-VOLATILE CACHE
0Bh/08h  DZTPROMAEBKVF  WARNING - POWER LOSS EXPECTED
0Bh/09h  DZ             WARNING - DEVICE STATISTICS NOTIFICATION ACTIVE
0Bh/0Ah  DZTPROMAEBKV   WARNING - HIGH CRITICAL TEMPERATURE LIMIT EXCEEDED
0Bh/0Bh  DZTPROMAEBKV   WARNING - LOW CRITICAL TEMPERATURE LIMIT EXCEEDED
0Bh/0Ch  DZTPROMAEBKV   WARNING - HIGH OPERATING TEMPERATURE LIMIT EXCEEDED
0Bh/0Dh  DZTPROMAEBKV   WARNING - LOW OPERATING TEMPERATURE LIMIT EXCEEDED
0Bh/0Eh  DZTPROMAEBKV   WARNING - HIGH CRITICAL HUMIDITY LIMIT EXCEEDED
0Bh/0Fh  DZTPROMAEBKV   WARNING - LOW CRITICAL HUMIDITY LIMIT EXCEEDED
0Bh/10h  DZTPROMAEBKV   WARNING - HIGH OPERATING HUMIDITY LIMIT EXCEEDED
0Bh/11h  DZTPROMAEBKV   WARNING - LOW OPERATING HUMIDITY LIMIT EXCEEDED
0Ch/00h    T R          WRITE ERROR
0Ch/01h            K    WRITE ERROR - RECOVERED WITH AUTO REALLOCATION
0Ch/02h  DZ   O   BK    WRITE ERROR - AUTO REALLOCATION FAILED
0Ch/03h  DZ   O   BK    WRITE ERROR - RECOMMEND REASSIGNMENT
0Ch/04h  DZT  O   B     COMPRESSION CHECK MISCOMPARE ERROR
0Ch/05h  DZT  O   B     DATA EXPANSION OCCURRED DURING COMPRESSION
0Ch/06h  DZT  O   B     BLOCK NOT COMPRESSIBLE
0Ch/07h  DZ  R          WRITE ERROR - RECOVERY NEEDED
0Ch/08h      R          WRITE ERROR - RECOVERY FAILED
0Ch/09h      R          WRITE ERROR - LOSS OF STREAMING
0Ch/0Ah      R          WRITE ERROR - PADDING BLOCKS ADDED
0Ch/0Bh  DZT ROM  B     AUXILIARY MEMORY WRITE ERROR
0Ch/0Ch  DZTPRO AEBKVF  WRITE ERROR - UNEXPECTED UNSOLICITED DATA
0Ch/0Dh  DZTPRO AEBKVF  WRITE ERROR - NOT ENOUGH UNSOLICITED DATA
0Ch/0Eh  DZT  O   BK    MULTIPLE WRITE ERRORS
0Ch/0Fh      R          DEFECTS IN ERROR WINDOW
0Ch/10h  DZ             INCOMPLETE MULTIPLE ATOMIC WRITE OPERATIONS
0Ch/11h  DZ             WRITE ERROR - RECOVERY SCAN NEEDED
0Ch/12h  DZ             WRITE ERROR - INSUFFICIENT ZONE RESOURCES
0Dh/00h  DZTPRO A  K    ERROR DETECTED BY THIRD PARTY TEMPORARY INITIATOR
0Dh/01h  DZTPRO A  K    THIRD PARTY DEVICE FAILURE
0Dh/02h  DZTPRO A  K    COPY TARGET DEVICE NOT REACHABLE
0Dh/03h  DZTPRO A  K    INCORRECT COPY TARGET DEVICE TYPE
0Dh/04h  DZTPRO A  K    COPY TARGET DEVICE DATA UNDERRUN
0Dh/05h  DZTPRO A  K    COPY TARGET DEVICE DATA OVERRUN
0Eh/00h  DZTPROMAEBK F  INVALID INFORMATION UNIT
0Eh/01h  DZTPROMAEBK F  INFORMATION UNIT TOO SHORT
0Eh/02h  DZTPROMAEBK F  INFORMATION UNIT TOO LONG
0Eh/03h  DZTPR MAEBK F  INVALID FIELD IN COMMAND INFORMATION UNIT
0Fh/00h
10h/00h  DZ   O   BK    ID CRC OR ECC ERROR
10h/01h  DZT  O         LOGICAL BLOCK GUARD CHECK FAILED
10h/02h  DZT  O         LOGICAL BLOCK APPLICATION TAG CHECK FAILED
10h/03h  DZT  O         LOGICAL BLOCK REFERENCE TAG CHECK FAILED
10h/04h    T            LOGICAL BLOCK PROTECTION ERROR ON RECOVER BUFFERED DATA
10h/05h    T            LOGICAL BLOCK PROTECTION METHOD ERROR
11h/00h  DZT RO   BK    UNRECOVERED READ ERROR
11h/01h  DZT RO   BK    READ RETRIES EXHAUSTED
11h/02h  DZT RO   BK    ERROR TOO LONG TO CORRECT
11h/03h  DZT  O   BK    MULTIPLE READ ERRORS
11h/04h  DZ   O   BK    UNRECOVERED READ ERROR - AUTO REALLOCATE FAILED
11h/05h      RO   B     L-EC UNCORRECTABLE ERROR
11h/06h      RO   B     CIRC UNRECOVERED ERROR
11h/07h       O   B     DATA RE-SYNCHRONIZATION ERROR
11h/08h    T            INCOMPLETE BLOCK READ
11h/09h    T            NO GAP FOUND
11h/0Ah  DZT  O   BK    MISCORRECTED ERROR
11h/0Bh  DZ   O   BK    UNRECOVERED READ ERROR - RECOMMEND REASSIGNMENT
11h/0Ch  DZ   O   BK    UNRECOVERED READ ERROR - RECOMMEND REWRITE THE DATA
11h/0Dh  DZT RO   B     DE-COMPRESSION CRC ERROR
11h/0Eh  DZT RO   B     CANNOT DECOMPRESS USING DECLARED ALGORITHM
11h/0Fh      R          ERROR READING UPC/EAN NUMBER
11h/10h      R          ERROR READING ISRC NUMBER
11h/11h      R          READ ERROR - LOSS OF STREAMING
11h/12h  DZT ROM  B     AUXILIARY MEMORY READ ERROR
11h/13h  DZTPRO AEBKVF  READ ERROR - FAILED RETRANSMISSION REQUEST
11h/14h  DZ             READ ERROR - LBA MARKED BAD BY APPLICATION CLIENT
11h/15h  DZ             WRITE AFTER SANITIZE REQUIRED
12h/00h  DZ   O   BK    ADDRESS MARK NOT FOUND FOR ID FIELD
13h/00h  DZ   O   BK    ADDRESS MARK NOT FOUND FOR DATA FIELD
14h/00h  DZT RO   BK    RECORDED ENTITY NOT FOUND
14h/01h  DZT RO   BK    RECORD NOT FOUND
14h/02h    T            FILEMARK OR SETMARK NOT FOUND
14h/03h    T            END-OF-DATA NOT FOUND
14h/04h    T            BLOCK SEQUENCE ERROR
14h/05h  DZT  O   BK    RECORD NOT FOUND - RECOMMEND REASSIGNMENT
14h/06h  DZT  O   BK    RECORD NOT FOUND - DATA AUTO-REALLOCATED
14h/07h    T            LOCATE OPERATION FAILURE
15h/00h  DZT ROM  BK    RANDOM POSITIONING ERROR
15h/01h  DZT ROM  BK    MECHANICAL POSITIONING ERROR
15h/02h  DZT RO   BK    POSITIONING ERROR DETECTED BY READ OF MEDIUM
16h/00h  DZ   O   BK    DATA SYNCHRONIZATION MARK ERROR
16h/01h  DZ   O   BK    DATA SYNC ERROR - DATA REWRITTEN
16h/02h  DZ   O   BK    DATA SYNC ERROR - RECOMMEND REWRITE
16h/03h  DZ   O   BK    DATA SYNC ERROR - DATA AUTO-REALLOCATED
16h/04h  DZ   O   BK    DATA SYNC ERROR - RECOMMEND REASSIGNMENT
17h/00h  DZT RO   BK    RECOVERED DATA WITH NO ERROR CORRECTION APPLIED
17h/01h  DZT RO   BK    RECOVERED DATA WITH RETRIES
17h/02h  DZT RO   BK    RECOVERED DATA WITH POSITIVE HEAD OFFSET
17h/03h  DZT RO   BK    RECOVERED DATA WITH NEGATIVE HEAD OFFSET
17h/04h      RO   B     RECOVERED DATA WITH RETRIES AND/OR CIRC APPLIED
17h/05h  DZ  RO   BK    RECOVERED DATA USING PREVIOUS SECTOR ID
17h/06h  DZ   O   BK    RECOVERED DATA WITHOUT ECC - DATA AUTO-REALLOCATED
17h/07h  DZ  RO   BK    RECOVERED DATA WITHOUT ECC - RECOMMEND REASSIGNMENT
17h/08h  DZ  RO   BK    RECOVERED DATA WITHOUT ECC - RECOMMEND REWRITE
17h/09h  DZ  RO   BK    RECOVERED DATA WITHOUT ECC - DATA REWRITTEN
18h/00h  DZT RO   BK    RECOVERED DATA WITH ERROR CORRECTION APPLIED
18h/01h  DZ  RO   BK    RECOVERED DATA WITH ERROR CORR. & RETRIES APPLIED
18h/02h  DZ  RO   BK    RECOVERED DATA - DATA AUTO-REALLOCATED
18h/03h      R          RECOVERED DATA WITH CIRC
18h/04h      R          RECOVERED DATA WITH L-EC
18h/05h  DZ  RO   BK    RECOVERED DATA - RECOMMEND REASSIGNMENT
18h/06h  DZ  RO   BK    RECOVERED DATA - RECOMMEND REWRITE
18h/07h  DZ   O   BK    RECOVERED DATA WITH ECC - DATA REWRITTEN
18h/08h      R          RECOVERED DATA WITH LINKING
19h/00h  DZ   O    K    DEFECT LIST ERROR
19h/01h  DZ   O    K    DEFECT LIST NOT AVAILABLE
19h/02h  DZ   O    K    DEFECT LIST ERROR IN PRIMARY LIST
19h/03h  DZ   O    K    DEFECT LIST ERROR IN GROWN LIST
1Ah/00h  DZTPROMAEBKVF  PARAMETER LIST LENGTH ERROR
1Bh/00h  DZTPROMAEBKVF  SYNCHRONOUS DATA TRANSFER ERROR
1Ch/00h  DZ   O   BK    DEFECT LIST NOT FOUND
1Ch/01h  DZ   O   BK    PRIMARY DEFECT LIST NOT FOUND
1Ch/02h  DZ   O   BK    GROWN DEFECT LIST NOT FOUND
1Dh/00h  DZT RO   BK    MISCOMPARE DURING VERIFY OPERATION
1Dh/01h  DZ       B     MISCOMPARE VERIFY OF UNMAPPED LBA
1Eh/00h  DZ   O   BK    RECOVERED ID WITH ECC CORRECTION
1Fh/00h  DZ   O    K    PARTIAL DEFECT LIST TRANSFER
20h/00h  DZTPROMAEBKVF  INVALID COMMAND OPERATION CODE
20h/01h  DZTPROMAEBK    ACCESS DENIED - INITIATOR PENDING-ENROLLED
20h/02h  DZTPROMAEBK    ACCESS DENIED - NO ACCESS RIGHTS
20h/03h  DZTPROMAEBK    ACCESS DENIED - INVALID MGMT ID KEY
20h/04h    T            ILLEGAL COMMAND WHILE IN WRITE CAPABLE STATE
20h/05h    T            Obsolete
20h/06h    T            ILLEGAL COMMAND WHILE IN EXPLICIT ADDRESS MODE
20h/07h    T            ILLEGAL COMMAND WHILE IN IMPLICIT ADDRESS MODE
20h/08h  DZTPROMAEBK    ACCESS DENIED - ENROLLMENT CONFLICT
20h/09h  DZTPROMAEBK    ACCESS DENIED - INVALID LU IDENTIFIER
20h/0Ah  DZTPROMAEBK    ACCESS DENIED - INVALID PROXY TOKEN
20h/0Bh  DZTPROMAEBK    ACCESS DENIED - ACL LUN CONFLICT
20h/0Ch    T            ILLEGAL COMMAND WHEN NOT IN APPEND-ONLY MODE
20h/0Dh  D              NOT AN ADMINISTRATIVE LOGICAL UNIT
20h/0Eh  D              NOT A SUBSIDIARY LOGICAL UNIT
20h/0Fh  D              NOT A CONGLOMERATE LOGICAL UNIT
21h/00h  DZT RO   BK    LOGICAL BLOCK ADDRESS OUT OF RANGE
21h/01h  DZT ROM  BK    INVALID ELEMENT ADDRESS
21h/02h      R          INVALID ADDRESS FOR WRITE
21h/03h      R          INVALID WRITE CROSSING LAYER JUMP
21h/04h  DZ             UNALIGNED WRITE COMMAND
21h/05h  DZ             WRITE BOUNDARY VIOLATION
21h/06h  DZ             ATTEMPT TO READ INVALID DATA
21h/07h  DZ             READ BOUNDARY VIOLATION
21h/08h  DZ             MISALIGNED WRITE COMMAND
22h/00h  DZ             ILLEGAL FUNCTION (USE 20 00, 24 00, OR 26 00)
23h/00h  DZTP     B     INVALID TOKEN OPERATION, CAUSE NOT REPORTABLE
23h/01h  DZTP     B     INVALID TOKEN OPERATION, UNSUPPORTED TOKEN TYPE
23h/02h  DZTP     B     INVALID TOKEN OPERATION, REMOTE TOKEN USAGE NOT SUPPORTED
23h/03h  DZTP     B     INVALID TOKEN OPERATION, REMOTE ROD TOKEN CREATION NOT SUPPORTED
23h/04h  DZTP     B     INVALID TOKEN OPERATION, TOKEN UNKNOWN
23h/05h  DZTP     B     INVALID TOKEN OPERATION, TOKEN CORRUPT
23h/06h  DZTP     B     INVALID TOKEN OPERATION, TOKEN REVOKED
23h/07h  DZTP     B     INVALID TOKEN OPERATION, TOKEN EXPIRED
23h/08h  DZTP     B     INVALID TOKEN OPERATION, TOKEN CANCELLED
23h/09h  DZTP     B     INVALID TOKEN OPERATION, TOKEN DELETED
23h/0Ah  DZTP     B     INVALID TOKEN OPERATION, INVALID TOKEN LENGTH
24h/00h  DZTPROMAEBKVF  INVALID FIELD IN CDB
24h/01h  DZTPRO AEBKVF  CDB DECRYPTION ERROR
24h/02h    T            Obsolete
24h/03h    T            Obsolete
24h/04h              F  SECURITY AUDIT VALUE FROZEN
24h/05h              F  SECURITY WORKING KEY FROZEN
24h/06h              F  NONCE NOT UNIQUE
24h/07h              F  NONCE TIMESTAMP OUT OF RANGE
24h/08h  DZT R MAEBKV   INVALID XCDB
24h/09h  DZ             INVALID FAST FORMAT
25h/00h  DZTPROMAEBKVF  LOGICAL UNIT NOT SUPPORTED
26h/00h  DZTPROMAEBKVF  INVALID FIELD IN PARAMETER LIST
26h/01h  DZTPROMAEBKVF  PARAMETER NOT SUPPORTED
26h/02h  DZTPROMAEBKVF  PARAMETER VALUE INVALID
26h/03h  DZTPROMAE K    THRESHOLD PARAMETERS NOT SUPPORTED
26h/04h  DZTPROMAEBKVF  INVALID RELEASE OF PERSISTENT RESERVATION
26h/05h  DZTPRO A BK    DATA DECRYPTION ERROR
26h/06h  DZTPRO    K    TOO MANY TARGET DESCRIPTORS
26h/07h  DZTPRO    K    UNSUPPORTED TARGET DESCRIPTOR TYPE CODE
26h/08h  DZTPRO    K    TOO MANY SEGMENT DESCRIPTORS
26h/09h  DZTPRO    K    UNSUPPORTED SEGMENT DESCRIPTOR TYPE CODE
26h/0Ah  DZTPRO    K    UNEXPECTED INEXACT SEGMENT
26h/0Bh  DZTPRO    K    INLINE DATA LENGTH EXCEEDED
26h/0Ch  DZTPRO    K    INVALID OPERATION FOR COPY SOURCE OR DESTINATION
26h/0Dh  DZTPRO    K    COPY SEGMENT GRANULARITY VIOLATION
26h/0Eh  DZTPROMAEBK    INVALID PARAMETER WHILE PORT IS ENABLED
26h/0Fh              F  INVALID DATA-OUT BUFFER INTEGRITY CHECK VALUE
26h/10h    T            DATA DECRYPTION KEY FAIL LIMIT REACHED
26h/11h    T            INCOMPLETE KEY-ASSOCIATED DATA SET
26h/12h    T            VENDOR SPECIFIC KEY REFERENCE NOT FOUND
26h/13h  D              APPLICATION TAG MODE PAGE IS INVALID
26h/14h    T            TAPE STREAM MIRRORING PREVENTED
26h/15h    T            COPY SOURCE OR COPY DESTINATION NOT AUTHORIZED
27h/00h  DZT RO   BK    WRITE PROTECTED
27h/01h  DZT RO   BK    HARDWARE WRITE PROTECTED
27h/02h  DZT RO   BK    LOGICAL UNIT SOFTWARE WRITE PROTECTED
27h/03h    T R          ASSOCIATED WRITE PROTECT
27h/04h    T R          PERSISTENT WRITE PROTECT
27h/05h    T R          PERMANENT WRITE PROTECT
27h/06h      R       F  CONDITIONAL WRITE PROTECT
27h/07h  DZ       B     SPACE ALLOCATION FAILED WRITE PROTECT
27h/08h  DZ             ZONE IS READ ONLY
28h/00h  DZTPROMAEBKVF  NOT READY TO READY CHANGE, MEDIUM MAY HAVE CHANGED
28h/01h  DZT ROM  B     IMPORT OR EXPORT ELEMENT ACCESSED
28h/02h      R          FORMAT-LAYER MAY HAVE CHANGED
28h/03h        M        IMPORT/EXPORT ELEMENT ACCESSED, MEDIUM CHANGED
29h/00h  DZTPROMAEBKVF  POWER ON, RESET, OR BUS DEVICE RESET OCCURRED
29h/01h  DZTPROMAEBKVF  POWER ON OCCURRED
29h/02h  DZTPROMAEBKVF  SCSI BUS RESET OCCURRED
29h/03h  DZTPROMAEBKVF  BUS DEVICE RESET FUNCTION OCCURRED
29h/04h  DZTPROMAEBKVF  DEVICE INTERNAL RESET
29h/05h  DZTPROMAEBKVF  TRANSCEIVER MODE CHANGED TO SINGLE-ENDED
29h/06h  DZTPROMAEBKVF  TRANSCEIVER MODE CHANGED TO LVD
29h/07h  DZTPROMAEBKVF  I_T NEXUS LOSS OCCURRED
2Ah/00h  DZT ROMAEBKVF  PARAMETERS CHANGED
2Ah/01h  DZT ROMAEBKVF  MODE PARAMETERS CHANGED
2Ah/02h  DZT ROMAE K    LOG PARAMETERS CHANGED
2Ah/03h  DZTPROMAE K    RESERVATIONS PREEMPTED
2Ah/04h  DZTPROMAE      RESERVATIONS RELEASED
2Ah/05h  DZTPROMAE      REGISTRATIONS PREEMPTED
2Ah/06h  DZTPROMAEBKVF  ASYMMETRIC ACCESS STATE CHANGED
2Ah/07h  DZTPROMAEBKVF  IMPLICIT ASYMMETRIC ACCESS STATE TRANSITION FAILED
2Ah/08h  DZT ROMAEBKVF  PRIORITY CHANGED
2Ah/09h  DZ             CAPACITY DATA HAS CHANGED
2Ah/0Ah  DZT            ERROR HISTORY I_T NEXUS CLEARED
2Ah/0Bh  DZT            ERROR HISTORY SNAPSHOT RELEASED
2Ah/0Ch              F  ERROR RECOVERY ATTRIBUTES HAVE CHANGED
2Ah/0Dh    T            DATA ENCRYPTION CAPABILITIES CHANGED
2Ah/10h  DZT   M E  V   TIMESTAMP CHANGED
2Ah/11h    T            DATA ENCRYPTION PARAMETERS CHANGED BY ANOTHER I_T NEXUS
2Ah/12h    T            DATA ENCRYPTION PARAMETERS CHANGED BY VENDOR SPECIFIC EVENT
2Ah/13h    T            DATA ENCRYPTION KEY INSTANCE COUNTER HAS CHANGED
2Ah/14h  DZT R MAEBKV   SA CREATION CAPABILITIES DATA HAS CHANGED
2Ah/15h    T   M    V   MEDIUM REMOVAL PREVENTION PREEMPTED
2Ah/16h  DZ             ZONE RESET WRITE POINTER RECOMMENDED
2Bh/00h  DZTPRO    K    COPY CANNOT EXECUTE SINCE HOST CANNOT DISCONNECT
2Ch/00h  DZTPROMAEBKVF  COMMAND SEQUENCE ERROR
2Ch/01h                 TOO MANY WINDOWS SPECIFIED
2Ch/02h                 INVALID COMBINATION OF WINDOWS SPECIFIED
2Ch/03h      R          CURRENT PROGRAM AREA IS NOT EMPTY
2Ch/04h      R          CURRENT PROGRAM AREA IS EMPTY
2Ch/05h           B     ILLEGAL POWER CONDITION REQUEST
2Ch/06h      R          PERSISTENT PREVENT CONFLICT
2Ch/07h  DZTPROMAEBKVF  PREVIOUS BUSY STATUS
2Ch/08h  DZTPROMAEBKVF  PREVIOUS TASK SET FULL STATUS
2Ch/09h  DZTPROM EBKVF  PREVIOUS RESERVATION CONFLICT STATUS
2Ch/0Ah              F  PARTITION OR COLLECTION CONTAINS USER OBJECTS
2Ch/0Bh    T            NOT RESERVED
2Ch/0Ch  DZ             ORWRITE GENERATION DOES NOT MATCH
2Ch/0Dh  DZ             RESET WRITE POINTER NOT ALLOWED
2Ch/0Eh  DZ             ZONE IS OFFLINE
2Ch/0Fh  DZ             STREAM NOT OPEN
2Ch/10h  DZ             UNWRITTEN DATA IN ZONE
2Ch/11h  D              DESCRIPTOR FORMAT SENSE DATA REQUIRED
2Dh/00h    T            OVERWRITE ERROR ON UPDATE IN PLACE
2Eh/00h  DZ  ROM  B     INSUFFICIENT TIME FOR OPERATION
2Eh/01h  DZ   OM  B     COMMAND TIMEOUT BEFORE PROCESSING
2Eh/02h  DZ   OM  B     COMMAND TIMEOUT DURING PROCESSING
2Eh/03h  DZ   OM  B     COMMAND TIMEOUT DURING PROCESSING DUE TO ERROR RECOVERY
2Fh/00h  DZTPROMAEBKVF  COMMANDS CLEARED BY ANOTHER INITIATOR
2Fh/01h  DZ             COMMANDS CLEARED BY POWER LOSS NOTIFICATION
2Fh/02h  DZTPROMAEBKVF  COMMANDS CLEARED BY DEVICE SERVER
2Fh/03h  DZTPROMAEBKVF  SOME COMMANDS CLEARED BY QUEUING LAYER EVENT
30h/00h  DZT ROM  BK    INCOMPATIBLE MEDIUM INSTALLED
30h/01h  DZT RO   BK    CANNOT READ MEDIUM - UNKNOWN FORMAT
30h/02h  DZT RO   BK    CANNOT READ MEDIUM - INCOMPATIBLE FORMAT
30h/03h  DZT R M   K    CLEANING CARTRIDGE INSTALLED
30h/04h  DZT RO   BK    CANNOT WRITE MEDIUM - UNKNOWN FORMAT
30h/05h  DZT RO   BK    CANNOT WRITE MEDIUM - INCOMPATIBLE FORMAT
30h/06h  DZT RO   B     CANNOT FORMAT MEDIUM - INCOMPATIBLE MEDIUM
30h/07h  DZT ROMAEBKVF  CLEANING FAILURE
30h/08h      R          CANNOT WRITE - APPLICATION CODE MISMATCH
30h/09h      R          CURRENT SESSION NOT FIXATED FOR APPEND
30h/0Ah  DZT RO AEBK    CLEANING REQUEST REJECTED
30h/0Ch    T            WORM MEDIUM - OVERWRITE ATTEMPTED
30h/0Dh    T            WORM MEDIUM - INTEGRITY CHECK
30h/10h      R          MEDIUM NOT FORMATTED
30h/11h        M        INCOMPATIBLE VOLUME TYPE
30h/12h        M        INCOMPATIBLE VOLUME QUALIFIER
30h/13h        M        CLEANING VOLUME EXPIRED
31h/00h  DZT RO   BK    MEDIUM FORMAT CORRUPTED
31h/01h  DZ  RO   B     FORMAT COMMAND FAILED
31h/02h      R          ZONED FORMATTING FAILED DUE TO SPARE LINKING
31h/03h  DZ       B     SANITIZE COMMAND FAILED
32h/00h  DZ   O   BK    NO DEFECT SPARE LOCATION AVAILABLE
32h/01h  DZ   O   BK    DEFECT LIST UPDATE FAILURE
33h/00h    T            TAPE LENGTH ERROR
34h/00h  DZTPROMAEBKVF  ENCLOSURE FAILURE
35h/00h  DZTPROMAEBKVF  ENCLOSURE SERVICES FAILURE
35h/01h  DZTPROMAEBKVF  UNSUPPORTED ENCLOSURE FUNCTION
35h/02h  DZTPROMAEBKVF  ENCLOSURE SERVICES UNAVAILABLE
35h/03h  DZTPROMAEBKVF  ENCLOSURE SERVICES TRANSFER FAILURE
35h/04h  DZTPROMAEBKVF  ENCLOSURE SERVICES TRANSFER REFUSED
35h/05h  DZT ROMAEBKVF  ENCLOSURE SERVICES CHECKSUM ERROR
36h/00h                 RIBBON, INK, OR TONER FAILURE
37h/00h  DZT ROMAEBKVF  ROUNDED PARAMETER
38h/00h           B     EVENT STATUS NOTIFICATION
38h/02h           B     ESN - POWER MANAGEMENT CLASS EVENT
38h/04h           B     ESN - MEDIA CLASS EVENT
38h/06h           B     ESN - DEVICE BUSY CLASS EVENT
38h/07h  DZ             THIN PROVISIONING SOFT THRESHOLD REACHED
39h/00h  DZT ROMAE K    SAVING PARAMETERS NOT SUPPORTED
3Ah/00h  DZT ROM  BK    MEDIUM NOT PRESENT
3Ah/01h  DZT ROM  BK    MEDIUM NOT PRESENT - TRAY CLOSED
3Ah/02h  DZT ROM  BK    MEDIUM NOT PRESENT - TRAY OPEN
3Ah/03h  DZT ROM  B     MEDIUM NOT PRESENT - LOADABLE
3Ah/04h  DZT RO   B     MEDIUM NOT PRESENT - MEDIUM AUXILIARY MEMORY ACCESSIBLE
3Bh/00h    T            SEQUENTIAL POSITIONING ERROR
3Bh/01h    T            TAPE POSITION ERROR AT BEGINNING-OF-MEDIUM
3Bh/02h    T            TAPE POSITION ERROR AT END-OF-MEDIUM
3Bh/03h                 TAPE OR ELECTRONIC VERTICAL FORMS UNIT NOT READY
3Bh/04h                 SLEW FAILURE
3Bh/05h                 PAPER JAM
3Bh/06h                 FAILED TO SENSE TOP-OF-FORM
3Bh/07h                 FAILED TO SENSE BOTTOM-OF-FORM
3Bh/08h    T            REPOSITION ERROR
3Bh/09h                 READ PAST END OF MEDIUM
3Bh/0Ah                 READ PAST BEGINNING OF MEDIUM
3Bh/0Bh                 POSITION PAST END OF MEDIUM
3Bh/0Ch    T            POSITION PAST BEGINNING OF MEDIUM
3Bh/0Dh  DZT ROM  BK    MEDIUM DESTINATION ELEMENT FULL
3Bh/0Eh  DZT ROM  BK    MEDIUM SOURCE ELEMENT EMPTY
3Bh/0Fh      R          END OF MEDIUM REACHED
3Bh/11h  DZT ROM  BK    MEDIUM MAGAZINE NOT ACCESSIBLE
3Bh/12h  DZT ROM  BK    MEDIUM MAGAZINE REMOVED
3Bh/13h  DZT ROM  BK    MEDIUM MAGAZINE INSERTED
3Bh/14h  DZT ROM  BK    MEDIUM MAGAZINE LOCKED
3Bh/15h  DZT ROM  BK    MEDIUM MAGAZINE UNLOCKED
3Bh/16h      R          MECHANICAL POSITIONING OR CHANGER ERROR
3Bh/17h              F  READ PAST END OF USER OBJECT
3Bh/18h        M        ELEMENT DISABLED
3Bh/19h        M        ELEMENT ENABLED
3Bh/1Ah        M        DATA TRANSFER DEVICE REMOVED
3Bh/1Bh        M        DATA TRANSFER DEVICE INSERTED
3Bh/1Ch    T            TOO MANY LOGICAL OBJECTS ON PARTITION TO SUPPORT OPERATION
3Ch/00h
3Dh/00h  DZTPROMAE K    INVALID BITS IN IDENTIFY MESSAGE
3Eh/00h  DZTPROMAEBKVF  LOGICAL UNIT HAS NOT SELF-CONFIGURED YET
3Eh/01h  DZTPROMAEBKVF  LOGICAL UNIT FAILURE
3Eh/02h  DZTPROMAEBKVF  TIMEOUT ON LOGICAL UNIT
3Eh/03h  DZTPROMAEBKVF  LOGICAL UNIT FAILED SELF-TEST
3Eh/04h  DZTPROMAEBKVF  LOGICAL UNIT UNABLE TO UPDATE SELF-TEST LOG
3Fh/00h  DZTPROMAEBKVF  TARGET OPERATING CONDITIONS HAVE CHANGED
3Fh/01h  DZTPROMAEBKVF  MICROCODE HAS BEEN CHANGED
3Fh/02h  DZTPROM  BK    CHANGED OPERATING DEFINITION
3Fh/03h  DZTPROMAEBKVF  INQUIRY DATA HAS CHANGED
3Fh/04h  DZT ROMAEBK    COMPONENT DEVICE ATTACHED
3Fh/05h  DZT ROMAEBK    DEVICE IDENTIFIER CHANGED
3Fh/06h  DZT ROMAEB     REDUNDANCY GROUP CREATED OR MODIFIED
3Fh/07h  DZT ROMAEB     REDUNDANCY GROUP DELETED
3Fh/08h  DZT ROMAEB     SPARE CREATED OR MODIFIED
3Fh/09h  DZT ROMAEB     SPARE DELETED
3Fh/0Ah  DZT ROMAEBK    VOLUME SET CREATED OR MODIFIED
3Fh/0Bh  DZT ROMAEBK    VOLUME SET DELETED
3Fh/0Ch  DZT ROMAEBK    VOLUME SET DEASSIGNED
3Fh/0Dh  DZT ROMAEBK    VOLUME SET REASSIGNED
3Fh/0Eh  DZTPROMAE      REPORTED LUNS DATA HAS CHANGED
3Fh/0Fh  DZTPROMAEBKVF  ECHO BUFFER OVERWRITTEN
3Fh/10h  DZT ROM  B     MEDIUM LOADABLE
3Fh/11h  DZT ROM  B     MEDIUM AUXILIARY MEMORY ACCESSIBLE
3Fh/12h  DZTPR MAEBK F  iSCSI IP ADDRESS ADDED
3Fh/13h  DZTPR MAEBK F  iSCSI IP ADDRESS REMOVED
3Fh/14h  DZTPR MAEBK F  iSCSI IP ADDRESS CHANGED
3Fh/15h  DZTPR MAEBK    INSPECT REFERRALS SENSE DESCRIPTORS
3Fh/16h  DZTPROMAEBKVF  MICROCODE HAS BEEN CHANGED WITHOUT RESET
3Fh/17h  DZ             ZONE TRANSITION TO FULL
3Fh/18h  D              BIND COMPLETED
3Fh/19h  D              BIND REDIRECTED
3Fh/1Ah  D              SUBSIDIARY BINDING CHANGED
40h/00h  DZ             RAM FAILURE (SHOULD USE 40 NN)
40h/NNh  DZTPROMAEBKVF  DIAGNOSTIC FAILURE ON COMPONENT NN (80h-FFh)
41h/00h  DZ             DATA PATH FAILURE (SHOULD USE 40 NN)
42h/00h  DZ             POWER-ON OR SELF-TEST FAILURE (SHOULD USE 40 NN)
43h/00h  DZTPROMAEBKVF  MESSAGE ERROR
44h/00h  DZTPROMAEBKVF  INTERNAL TARGET FAILURE
44h/01h  DZTP  MAEBKVF  PERSISTENT RESERVATION INFORMATION LOST
44h/71h  DZT      B     ATA DEVICE FAILED SET FEATURES
45h/00h  DZTPROMAEBKVF  SELECT OR RESELECT FAILURE
46h/00h  DZTPROM  BK    UNSUCCESSFUL SOFT RESET
47h/00h  DZTPROMAEBKVF  SCSI PARITY ERROR
47h/01h  DZTPROMAEBKVF  DATA PHASE CRC ERROR DETECTED
47h/02h  DZTPROMAEBKVF  SCSI PARITY ERROR DETECTED DURING ST DATA PHASE
47h/03h  DZTPROMAEBKVF  INFORMATION UNIT iuCRC ERROR DETECTED
47h/04h  DZTPROMAEBKVF  ASYNCHRONOUS INFORMATION PROTECTION ERROR DETECTED
47h/05h  DZTPROMAEBKVF  PROTOCOL SERVICE CRC ERROR
47h/06h  DZT   MAEBKVF  PHY TEST FUNCTION IN PROGRESS
47h/7Fh  DZTPROMAEBK    SOME COMMANDS CLEARED BY ISCSI PROTOCOL EVENT
48h/00h  DZTPROMAEBKVF  INITIATOR DETECTED ERROR MESSAGE RECEIVED
49h/00h  DZTPROMAEBKVF  INVALID MESSAGE ERROR
4Ah/00h  DZTPROMAEBKVF  COMMAND PHASE ERROR
4Bh/00h  DZTPROMAEBKVF  DATA PHASE ERROR
4Bh/01h  DZTPROMAEBK    INVALID TARGET PORT TRANSFER TAG RECEIVED
4Bh/02h  DZTPROMAEBK    TOO MUCH WRITE DATA
4Bh/03h  DZTPROMAEBK    ACK/NAK TIMEOUT
4Bh/04h  DZTPROMAEBK    NAK RECEIVED
4Bh/05h  DZTPROMAEBK    DATA OFFSET ERROR
4Bh/06h  DZTPROMAEBK    INITIATOR RESPONSE TIMEOUT
4Bh/07h  DZTPROMAEBK F  CONNECTION LOST
4Bh/08h  DZTPROMAEBK F  DATA-IN BUFFER OVERFLOW - DATA BUFFER SIZE
4Bh/09h  DZTPROMAEBK F  DATA-IN BUFFER OVERFLOW - DATA BUFFER DESCRIPTOR AREA
4Bh/0Ah  DZTPROMAEBK F  DATA-IN BUFFER ERROR
4Bh/0Bh  DZTPROMAEBK F  DATA-OUT BUFFER OVERFLOW - DATA BUFFER SIZE
4Bh/0Ch  DZTPROMAEBK F  DATA-OUT BUFFER OVERFLOW - DATA BUFFER DESCRIPTOR AREA
4Bh/0Dh  DZTPROMAEBK F  DATA-OUT BUFFER ERROR
4Bh/0Eh  DZTPROMAEBK F  PCIE FABRIC ERROR
4Bh/0Fh  DZTPROMAEBK F  PCIE COMPLETION TIMEOUT
4Bh/10h  DZTPROMAEBK F  PCIE COMPLETER ABORT
4Bh/11h  DZTPROMAEBK F  PCIE POISONED TLP RECEIVED
4Bh/12h  DZTPROMAEBK F  PCIE ECRC CHECK FAILED
4Bh/13h  DZTPROMAEBK F  PCIE UNSUPPORTED REQUEST
4Bh/14h  DZTPROMAEBK F  PCIE ACS VIOLATION
4Bh/15h  DZTPROMAEBK F  PCIE TLP PREFIX BLOCKED
4Ch/00h  DZTPROMAEBKVF  LOGICAL UNIT FAILED SELF-CONFIGURATION
4Dh/NNh  DZTPROMAEBKVF  TAGGED OVERLAPPED COMMANDS (NN = TASK TAG)
4Eh/00h  DZTPROMAEBKVF  OVERLAPPED COMMANDS ATTEMPTED
4Fh/00h
50h/00h    T            WRITE APPEND ERROR
50h/01h    T            WRITE APPEND POSITION ERROR
50h/02h    T            POSITION ERROR RELATED TO TIMING
51h/00h  DZT RO         ERASE FAILURE
51h/01h  DZ  R          ERASE FAILURE - INCOMPLETE ERASE OPERATION DETECTED
52h/00h    T            CARTRIDGE FAULT
53h/00h  DZT ROM  BK    MEDIA LOAD OR EJECT FAILED
53h/01h    T            UNLOAD TAPE FAILURE
53h/02h  DZT ROM  BK    MEDIUM REMOVAL PREVENTED
53h/03h        M        MEDIUM REMOVAL PREVENTED BY DATA TRANSFER ELEMENT
53h/04h    T            MEDIUM THREAD OR UNTHREAD FAILURE
53h/05h        M        VOLUME IDENTIFIER INVALID
53h/06h        M        VOLUME IDENTIFIER MISSING
53h/07h        M        DUPLICATE VOLUME IDENTIFIER
53h/08h        M        ELEMENT STATUS UNKNOWN
53h/09h        M        DATA TRANSFER DEVICE ERROR - LOAD FAILED
53h/0Ah        M        DATA TRANSFER DEVICE ERROR - UNLOAD FAILED
53h/0Bh        M        DATA TRANSFER DEVICE ERROR - UNLOAD MISSING
53h/0Ch        M        DATA TRANSFER DEVICE ERROR - EJECT FAILED
53h/0Dh        M        DATA TRANSFER DEVICE ERROR - LIBRARY COMMUNICATION FAILED
54h/00h     P           SCSI TO HOST SYSTEM INTERFACE FAILURE
55h/00h     P           SYSTEM RESOURCE FAILURE
55h/01h  DZ   O   BK    SYSTEM BUFFER FULL
55h/02h  DZTPROMAE K    INSUFFICIENT RESERVATION RESOURCES
55h/03h  DZTPROMAE K    INSUFFICIENT RESOURCES
55h/04h  DZTPROMAE K    INSUFFICIENT REGISTRATION RESOURCES
55h/05h  DZTPROMAEBK    INSUFFICIENT ACCESS CONTROL RESOURCES
55h/06h  DZT ROM  B     AUXILIARY MEMORY OUT OF SPACE
55h/07h              F  QUOTA ERROR
55h/08h    T            MAXIMUM NUMBER OF SUPPLEMENTAL DECRYPTION KEYS EXCEEDED
55h/09h        M        MEDIUM AUXILIARY MEMORY NOT ACCESSIBLE
55h/0Ah        M        DATA CURRENTLY UNAVAILABLE
55h/0Bh  DZTPROMAEBKVF  INSUFFICIENT POWER FOR OPERATION
55h/0Ch  DZTP     B     INSUFFICIENT RESOURCES TO CREATE ROD
55h/0Dh  DZTP     B     INSUFFICIENT RESOURCES TO CREATE ROD TOKEN
55h/0Eh  DZ             INSUFFICIENT ZONE RESOURCES
55h/0Fh  DZ             INSUFFICIENT ZONE RESOURCES TO COMPLETE WRITE
55h/10h  DZ             MAXIMUM NUMBER OF STREAMS OPEN
55h/11h  D              INSUFFICIENT RESOURCES TO BIND
56h/00h
57h/00h      R          UNABLE TO RECOVER TABLE-OF-CONTENTS
58h/00h       O         GENERATION DOES NOT EXIST
59h/00h       O         UPDATED BLOCK READ
5Ah/00h  DZTPRO   BK    OPERATOR REQUEST OR STATE CHANGE INPUT
5Ah/01h  DZT ROM  BK    OPERATOR MEDIUM REMOVAL REQUEST
5Ah/02h  DZT RO A BK    OPERATOR SELECTED WRITE PROTECT
5Ah/03h  DZT RO A BK    OPERATOR SELECTED WRITE PERMIT
5Bh/00h  DZTPROM   K    LOG EXCEPTION
5Bh/01h  DZTPROM   K    THRESHOLD CONDITION MET
5Bh/02h  DZTPROM   K    LOG COUNTER AT MAXIMUM
5Bh/03h  DZTPROM   K    LOG LIST CODES EXHAUSTED
5Ch/00h  DZ   O         RPL STATUS CHANGE
5Ch/01h  DZ   O         SPINDLES SYNCHRONIZED
5Ch/02h  DZ   O         SPINDLES NOT SYNCHRONIZED
5Dh/00h  DZTPROMAEBKVF  FAILURE PREDICTION THRESHOLD EXCEEDED
5Dh/01h      R    B     MEDIA FAILURE PREDICTION THRESHOLD EXCEEDED
5Dh/02h      R          LOGICAL UNIT FAILURE PREDICTION THRESHOLD EXCEEDED
5Dh/03h      R          SPARE AREA EXHAUSTION PREDICTION THRESHOLD EXCEEDED
5Dh/10h  DZ       B     HARDWARE IMPENDING FAILURE GENERAL HARD DRIVE FAILURE
5Dh/11h  DZ       B     HARDWARE IMPENDING FAILURE DRIVE ERROR RATE TOO HIGH
5Dh/12h  DZ       B     HARDWARE IMPENDING FAILURE DATA ERROR RATE TOO HIGH
5Dh/13h  DZ       B     HARDWARE IMPENDING FAILURE SEEK ERROR RATE TOO HIGH
5Dh/14h  DZ       B     HARDWARE IMPENDING FAILURE TOO MANY BLOCK REASSIGNS
5Dh/15h  DZ       B     HARDWARE IMPENDING FAILURE ACCESS TIMES TOO HIGH
5Dh/16h  DZ       B     HARDWARE IMPENDING FAILURE START UNIT TIMES TOO HIGH
5Dh/17h  DZ       B     HARDWARE IMPENDING FAILURE CHANNEL PARAMETRICS
5Dh/18h  DZ       B     HARDWARE IMPENDING FAILURE CONTROLLER DETECTED
5Dh/19h  DZ       B     HARDWARE IMPENDING FAILURE THROUGHPUT PERFORMANCE
5Dh/1Ah  DZ       B     HARDWARE IMPENDING FAILURE SEEK TIME PERFORMANCE
5Dh/1Bh  DZ       B     HARDWARE IMPENDING FAILURE SPIN-UP RETRY COUNT
5Dh/1Ch  DZ       B     HARDWARE IMPENDING FAILURE DRIVE CALIBRATION RETRY COUNT
5Dh/20h  DZ       B     CONTROLLER IMPENDING FAILURE GENERAL HARD DRIVE FAILURE
5Dh/21h  DZ       B     CONTROLLER IMPENDING FAILURE DRIVE ERROR RATE TOO HIGH
5Dh/22h  DZ       B     CONTROLLER IMPENDING FAILURE DATA ERROR RATE TOO HIGH
5Dh/23h  DZ       B     CONTROLLER IMPENDING FAILURE SEEK ERROR RATE TOO HIGH
5Dh/24h  DZ       B     CONTROLLER IMPENDING FAILURE TOO MANY BLOCK REASSIGNS
5Dh/25h  DZ       B     CONTROLLER IMPENDING FAILURE ACCESS TIMES TOO HIGH
5Dh/26h  DZ       B     CONTROLLER IMPENDING FAILURE START UNIT TIMES TOO HIGH
5Dh/27h  DZ       B     CONTROLLER IMPENDING FAILURE CHANNEL PARAMETRICS
5Dh/28h  DZ       B     CONTROLLER IMPENDING FAILURE CONTROLLER DETECTED
5Dh/29h  DZ       B     CONTROLLER IMPENDING FAILURE THROUGHPUT PERFORMANCE
5Dh/2Ah  DZ       B     CONTROLLER IMPENDING FAILURE SEEK TIME PERFORMANCE
5Dh/2Bh  DZ       B     CONTROLLER IMPENDING FAILURE SPIN-UP RETRY COUNT
5Dh/2Ch  DZ       B     CONTROLLER IMPENDING FAILURE DRIVE CALIBRATION RETRY COUNT
5Dh/30h  DZ       B     DATA CHANNEL IMPENDING FAILURE GENERAL HARD DRIVE FAILURE
5Dh/31h  DZ       B     DATA CHANNEL IMPENDING FAILURE DRIVE ERROR RATE TOO HIGH
5Dh/32h  DZ       B     DATA CHANNEL IMPENDING FAILURE DATA ERROR RATE TOO HIGH
5Dh/33h  DZ       B     DATA CHANNEL IMPENDING FAILURE SEEK ERROR RATE TOO HIGH
5Dh/34h  DZ       B     DATA CHANNEL IMPENDING FAILURE TOO MANY BLOCK REASSIGNS
5Dh/35h  DZ       B     DATA CHANNEL IMPENDING FAILURE ACCESS TIMES TOO HIGH
5Dh/36h  DZ       B     DATA CHANNEL IMPENDING FAILURE START UNIT TIMES TOO HIGH
5Dh/37h  DZ       B     DATA CHANNEL IMPENDING FAILURE CHANNEL PARAMETRICS
5Dh/38h  DZ       B     DATA CHANNEL IMPENDING FAILURE CONTROLLER DETECTED
5Dh/39h  DZ       B     DATA CHANNEL IMPENDING FAILURE THROUGHPUT PERFORMANCE
5Dh/3Ah  DZ       B     DATA CHANNEL IMPENDING FAILURE SEEK TIME PERFORMANCE
5Dh/3Bh  DZ       B     DATA CHANNEL IMPENDING FAILURE SPIN-UP RETRY COUNT
5Dh/3Ch  DZ       B     DATA CHANNEL IMPENDING FAILURE DRIVE CALIBRATION RETRY COUNT
5Dh/40h  DZ       B     SERVO IMPENDING FAILURE GENERAL HARD DRIVE FAILURE
5Dh/41h  DZ       B     SERVO IMPENDING FAILURE DRIVE ERROR RATE TOO HIGH
5Dh/42h  DZ       B     SERVO IMPENDING FAILURE DATA ERROR RATE TOO HIGH
5Dh/43h  DZ       B     SERVO IMPENDING FAILURE SEEK ERROR RATE TOO HIGH
5Dh/44h  DZ       B     SERVO IMPENDING FAILURE TOO MANY BLOCK REASSIGNS
5Dh/45h  DZ       B     SERVO IMPENDING FAILURE ACCESS TIMES TOO HIGH
5Dh/46h  DZ       B     SERVO IMPENDING FAILURE START UNIT TIMES TOO HIGH
5Dh/47h  DZ       B     SERVO IMPENDING FAILURE CHANNEL PARAMETRICS
5Dh/48h  DZ       B     SERVO IMPENDING FAILURE CONTROLLER DETECTED
5Dh/49h  DZ       B     SERVO IMPENDING FAILURE THROUGHPUT PERFORMANCE
5Dh/4Ah  DZ       B     SERVO IMPENDING FAILURE SEEK TIME PERFORMANCE
5Dh/4Bh  DZ       B     SERVO IMPENDING FAILURE SPIN-UP RETRY COUNT
5Dh/4Ch  DZ       B     SERVO IMPENDING FAILURE DRIVE CALIBRATION RETRY COUNT
5Dh/50h  DZ       B     SPINDLE IMPENDING FAILURE GENERAL HARD DRIVE FAILURE
5Dh/51h  DZ       B     SPINDLE IMPENDING FAILURE DRIVE ERROR RATE TOO HIGH
5Dh/52h  DZ       B     SPINDLE IMPENDING FAILURE DATA ERROR RATE TOO HIGH
5Dh/53h  DZ       B     SPINDLE IMPENDING FAILURE SEEK ERROR RATE TOO HIGH
5Dh/54h  DZ       B     SPINDLE IMPENDING FAILURE TOO MANY BLOCK REASSIGNS
5Dh/55h  DZ       B     SPINDLE IMPENDING FAILURE ACCESS TIMES TOO HIGH
5Dh/56h  DZ       B     SPINDLE IMPENDING FAILURE START UNIT TIMES TOO HIGH
5Dh/57h  DZ       B     SPINDLE IMPENDING FAILURE CHANNEL PARAMETRICS
5Dh/58h  DZ       B     SPINDLE IMPENDING FAILURE CONTROLLER DETECTED
5Dh/59h  DZ       B     SPINDLE IMPENDING FAILURE THROUGHPUT PERFORMANCE
5Dh/5Ah  DZ       B     SPINDLE IMPENDING FAILURE SEEK TIME PERFORMANCE
5Dh/5Bh  DZ       B     SPINDLE IMPENDING FAILURE SPIN-UP RETRY COUNT
5Dh/5Ch  DZ       B     SPINDLE IMPENDING FAILURE DRIVE CALIBRATION RETRY COUNT
5Dh/60h  DZ       B     FIRMWARE IMPENDING FAILURE GENERAL HARD DRIVE FAILURE
5Dh/61h  DZ       B     FIRMWARE IMPENDING FAILURE DRIVE ERROR RATE TOO HIGH
5Dh/62h  DZ       B     FIRMWARE IMPENDING FAILURE DATA ERROR RATE TOO HIGH
5Dh/63h  DZ       B     FIRMWARE IMPENDING FAILURE SEEK ERROR RATE TOO HIGH
5Dh/64h  DZ       B     FIRMWARE IMPENDING FAILURE TOO MANY BLOCK REASSIGNS
5Dh/65h  DZ       B     FIRMWARE IMPENDING FAILURE ACCESS TIMES TOO HIGH
5Dh/66h  DZ       B     FIRMWARE IMPENDING FAILURE START UNIT TIMES TOO HIGH
5Dh/67h  DZ       B     FIRMWARE IMPENDING FAILURE CHANNEL PARAMETRICS
5Dh/68h  DZ       B     FIRMWARE IMPENDING FAILURE CONTROLLER DETECTED
5Dh/69h  DZ       B     FIRMWARE IMPENDING FAILURE THROUGHPUT PERFORMANCE
5Dh/6Ah  DZ       B     FIRMWARE IMPENDING FAILURE SEEK TIME PERFORMANCE
5Dh/6Bh  DZ       B     FIRMWARE IMPENDING FAILURE SPIN-UP RETRY COUNT
5Dh/6Ch  DZ       B     FIRMWARE IMPENDING FAILURE DRIVE CALIBRATION RETRY COUNT
5Dh/FFh  DZTPROMAEBKVF  FAILURE PREDICTION THRESHOLD EXCEEDED (FALSE)
5Eh/00h  DZTPRO A  K    LOW POWER CONDITION ON
5Eh/01h  DZTPRO A  K    IDLE CONDITION ACTIVATED BY TIMER
5Eh/02h  DZTPRO A  K    STANDBY CONDITION ACTIVATED BY TIMER
5Eh/03h  DZTPRO A  K    IDLE CONDITION ACTIVATED BY COMMAND
5Eh/04h  DZTPRO A  K    STANDBY CONDITION ACTIVATED BY COMMAND
5Eh/05h  DZTPRO A  K    IDLE_B CONDITION ACTIVATED BY TIMER
5Eh/06h  DZTPRO A  K    IDLE_B CONDITION ACTIVATED BY COMMAND
5Eh/07h  DZTPRO A  K    IDLE_C CONDITION ACTIVATED BY TIMER
5Eh/08h  DZTPRO A  K    IDLE_C CONDITION ACTIVATED BY COMMAND
5Eh/09h  DZTPRO A  K    STANDBY_Y CONDITION ACTIVATED BY TIMER
5Eh/0Ah  DZTPRO A  K    STANDBY_Y CONDITION ACTIVATED BY COMMAND
5Eh/41h           B     POWER STATE CHANGE TO ACTIVE
5Eh/42h           B     POWER STATE CHANGE TO IDLE
5Eh/43h           B     POWER STATE CHANGE TO STANDBY
5Eh/45h           B     POWER STATE CHANGE TO SLEEP
5Eh/47h           BK    POWER STATE CHANGE TO DEVICE CONTROL
5Fh/00h
60h/00h                 LAMP FAILURE
61h/00h                 VIDEO ACQUISITION ERROR
61h/01h                 UNABLE TO ACQUIRE VIDEO
61h/02h                 OUT OF FOCUS
62h/00h                 SCAN HEAD POSITIONING ERROR
63h/00h      R          END OF USER AREA ENCOUNTERED ON THIS TRACK
63h/01h      R          PACKET DOES NOT FIT IN AVAILABLE SPACE
64h/00h      R          ILLEGAL MODE FOR THIS TRACK
64h/01h      R          INVALID PACKET SIZE
65h/00h  DZTPROMAEBKVF  VOLTAGE FAULT
66h/00h                 AUTOMATIC DOCUMENT FEEDER COVER UP
66h/01h                 AUTOMATIC DOCUMENT FEEDER LIFT UP
66h/02h                 DOCUMENT JAM IN AUTOMATIC DOCUMENT FEEDER
66h/03h                 DOCUMENT MISS FEED AUTOMATIC IN DOCUMENT FEEDER
67h/00h         A       CONFIGURATION FAILURE
67h/01h         A       CONFIGURATION OF INCAPABLE LOGICAL UNITS FAILED
67h/02h         A       ADD LOGICAL UNIT FAILED
67h/03h         A       MODIFICATION OF LOGICAL UNIT FAILED
67h/04h         A       EXCHANGE OF LOGICAL UNIT FAILED
67h/05h         A       REMOVE OF LOGICAL UNIT FAILED
67h/06h         A       ATTACHMENT OF LOGICAL UNIT FAILED
67h/07h         A       CREATION OF LOGICAL UNIT FAILED
67h/08h         A       ASSIGN FAILURE OCCURRED
67h/09h         A       MULTIPLY ASSIGNED LOGICAL UNIT
67h/0Ah  DZTPROMAEBKVF  SET TARGET PORT GROUPS COMMAND FAILED
67h/0Bh  DZT      B     ATA DEVICE FEATURE NOT ENABLED
67h/0Ch  D              COMMAND REJECTED
67h/0Dh  D              EXPLICIT BIND NOT ALLOWED
68h/00h         A       LOGICAL UNIT NOT CONFIGURED
68h/01h  DZ             SUBSIDIARY LOGICAL UNIT NOT CONFIGURED
69h/00h         A       DATA LOSS ON LOGICAL UNIT
69h/01h         A       MULTIPLE LOGICAL UNIT FAILURES
69h/02h         A       PARITY/DATA MISMATCH
6Ah/00h         A       INFORMATIONAL, REFER TO LOG
6Bh/00h         A       STATE CHANGE HAS OCCURRED
6Bh/01h         A       REDUNDANCY LEVEL GOT BETTER
6Bh/02h         A       REDUNDANCY LEVEL GOT WORSE
6Ch/00h         A       REBUILD FAILURE OCCURRED
6Dh/00h         A       RECALCULATE FAILURE OCCURRED
6Eh/00h         A       COMMAND TO LOGICAL UNIT FAILED
6Fh/00h      R          COPY PROTECTION KEY EXCHANGE FAILURE - AUTHENTICATION FAILURE
6Fh/01h      R          COPY PROTECTION KEY EXCHANGE FAILURE - KEY NOT PRESENT
6Fh/02h      R          COPY PROTECTION KEY EXCHANGE FAILURE - KEY NOT ESTABLISHED
6Fh/03h      R          READ OF SCRAMBLED SECTOR WITHOUT AUTHENTICATION
6Fh/04h      R          MEDIA REGION CODE IS MISMATCHED TO LOGICAL UNIT REGION
6Fh/05h      R          DRIVE REGION MUST BE PERMANENT/REGION RESET COUNT ERROR
6Fh/06h      R          INSUFFICIENT BLOCK COUNT FOR BINDING NONCE RECORDING
6Fh/07h      R          CONFLICT IN BINDING NONCE RECORDING
6Fh/08h      R          INSUFFICIENT PERMISSION
6Fh/09h      R          INVALID DRIVE-HOST PAIRING SERVER
6Fh/0Ah      R          DRIVE-HOST PAIRING SUSPENDED
70h/NNh    T            DECOMPRESSION EXCEPTION SHORT ALGORITHM ID OF NN
71h/00h    T            DECOMPRESSION EXCEPTION LONG ALGORITHM ID
72h/00h      R          SESSION FIXATION ERROR
72h/01h      R          SESSION FIXATION ERROR WRITING LEAD-IN
72h/02h      R          SESSION FIXATION ERROR WRITING LEAD-OUT
72h/03h      R          SESSION FIXATION ERROR - INCOMPLETE TRACK IN SESSION
72h/04h      R          EMPTY OR PARTIALLY WRITTEN RESERVED TRACK
72h/05h      R          NO MORE TRACK RESERVATIONS ALLOWED
72h/06h      R          RMZ EXTENSION IS NOT ALLOWED
72h/07h      R          NO MORE TEST ZONE EXTENSIONS ARE ALLOWED
73h/00h      R          CD CONTROL ERROR
73h/01h      R          POWER CALIBRATION AREA ALMOST FULL
73h/02h      R          POWER CALIBRATION AREA IS FULL
73h/03h      R          POWER CALIBRATION AREA ERROR
73h/04h      R          PROGRAM MEMORY AREA UPDATE FAILURE
73h/05h      R          PROGRAM MEMORY AREA IS FULL
73h/06h      R          RMA/PMA IS ALMOST FULL
73h/10h      R          CURRENT POWER CALIBRATION AREA ALMOST FULL
73h/11h      R          CURRENT POWER CALIBRATION AREA IS FULL
73h/17h      R          RDZ IS FULL
74h/00h    T            SECURITY ERROR
74h/01h    T            UNABLE TO DECRYPT DATA
74h/02h    T            UNENCRYPTED DATA ENCOUNTERED WHILE DECRYPTING
74h/03h    T            INCORRECT DATA ENCRYPTION KEY
74h/04h    T            CRYPTOGRAPHIC INTEGRITY VALIDATION FAILED
74h/05h    T            ERROR DECRYPTING DATA
74h/06h    T            UNKNOWN SIGNATURE VERIFICATION KEY
74h/07h    T            ENCRYPTION PARAMETERS NOT USEABLE
74h/08h  DZT R M E  VF  DIGITAL SIGNATURE VALIDATION FAILURE
74h/09h    T            ENCRYPTION MODE MISMATCH ON READ
74h/0Ah    T            ENCRYPTED BLOCK NOT RAW READ ENABLED
74h/0Bh    T            INCORRECT ENCRYPTION PARAMETERS
74h/0Ch  DZT R MAEBKV   UNABLE TO DECRYPT PARAMETER LIST
74h/0Dh    T            ENCRYPTION ALGORITHM DISABLED
74h/10h  DZT R MAEBKV   SA CREATION PARAMETER VALUE INVALID
74h/11h  DZT R MAEBKV   SA CREATION PARAMETER VALUE REJECTED
74h/12h  DZT R MAEBKV   INVALID SA USAGE
74h/21h    T            DATA ENCRYPTION CONFIGURATION PREVENTED
74h/30h  DZT R MAEBKV   SA CREATION PARAMETER NOT SUPPORTED
74h/40h  DZT R MAEBKV   AUTHENTICATION FAILED
74h/61h             V   EXTERNAL DATA ENCRYPTION KEY MANAGER ACCESS ERROR
74h/62h             V   EXTERNAL DATA ENCRYPTION KEY MANAGER ERROR
74h/63h             V   EXTERNAL DATA ENCRYPTION KEY NOT FOUND
74h/64h             V   EXTERNAL DATA ENCRYPTION REQUEST NOT AUTHORIZED
74h/6Eh    T            EXTERNAL DATA ENCRYPTION CONTROL TIMEOUT
74h/6Fh    T            EXTERNAL DATA ENCRYPTION CONTROL ERROR
74h/71h  DZT R M E  V   LOGICAL UNIT ACCESS NOT AUTHORIZED
74h/79h  DZ             SECURITY CONFLICT IN TRANSLATED DEVICE
75h/00h
76h/00h
77h/00h
78h/00h
79h/00h
7Ah/00h
7Bh/00h
7Ch/00h
7Dh/00h
7Eh/00h
7Fh/00h


byte byte
12   13
ASC ASCQ Description  SenseKey
=======================================
00 00 No Additional Sense Information 0
01 00 No Index/Logical Block Signal 4
02 00 No SEEK Complete 4
03 00 Peripheral Device Write Fault 1, 3, 4
03 86 Write Fault Data Corruption
04 00 Logical Unit Not Ready, Cause Not Reportable 2
04 01 Logical Unit Not Ready, Becoming Ready 2
04 02 Logical Unit Not Ready, SMART UNIT Required 2
04 03 Logical Unit Not Ready, Manual Intervention Required 2
04 04 Logical Unit Not Ready, Format in Progress 2
04 09 Logical Unit Not Ready, Self Test in Progress 2
04 0A Logical Unit Not Ready, NVC recovery in progress after and exception event 2
04 11 Logical Unit Not Ready, Notify (Enable Spinup) required 2
04 F0 Logical unit not ready, super certify in progress 2
05 00 ILLEGAL REQUEST 5
06 00 UNIT ATTENTION 6
07 00 Data Protect 7
08 00 Logical Unit Communication Failure 9, B
08 01 Logical Unit Communication Time-Out B
08 02 Logical Unit Communication Parity Error
09 00 Track Following Error 1, 3, 4
09 01 Servo Fault 1, 4
09 04 Head Select Fault 3, 4
09 0D Write to at least one copy of a redundant file failed 1
09 0E Redundant files have < 50% good copies 1
09 F8 Calibration is needed but the QST is set without the Recal Only bit 1
09 FF Servo Cal completed as part of self-test 1
0A 00 Error Log Overflow
0A 01 Failed to write super certify log file 3
0A 02 Failed to read super certify log file 3
0B 00 Aborted Command B
0B 01 WarningSpecified Temperature Exceeded 1, 6
0B 02 Warning, Enclosure Degraded 1
0C 00 Write Error 3
0C 01 Write Error Recovered With Auto-Reallocation 1
0C 02 Write ErrorAuto Reallocation Failed 3
0C 03 Write ErrorRecommend Reassignment 3
0C FF Write ErrorToo many error recovery revs 3
0D 00 Volume Overflow Constants D
0E 00 Data Miscompare E
10 00 ID CRC Or ECC Error
11 00 Unrecovered Read Error 1, 3
11 01 Read Retries Exhausted
11 02 Error Too Long To Correct
11 04 Unrecovered Read ErrorAuto Reallocation Failed 3
11 FF Unrecovered Read ErrorToo many error recovery revs 3
12 00 Address Mark Not Found For ID Field
12 01 Recovered Data Without ECC Using Previous Logical Block ID
12 02 Recovered Data With ECC Using Previous Logical Block ID
14 00 Logical Block Not Found
14 01 Record Not Found 3
15 00 Random Positioning Error
15 01 Mechanical Positioning Error 1, 3, 4
15 02 Positioning Error Detected By Read Of Medium
16 00 Data Synchronization Mark Error 1, 3, 4
17 00 Recovered Data With No Error Correction Applied
17 01 Recovered Data Using Retries 1
17 02 Recovered Data Using Positive Offset 1
17 03 Recovered Data Using Negative Offset 1
17 05 Recovered Data Using Previous Logical Block ID
17 06 Recovered Data Without ECCData Auto Reallocated
18 00 Recovered Data With ECC 1
18 01 Recovered Data With ECC And Retries Applied 1
18 02 Recovered Data With ECC And/Or Retries, Data Auto-Reallocated 1
18 05 Recovered DataRecommand Reassignment
18 06 Recovered Data Using ECC and Offsets
18 07 Recovered Data With ECCData Rewritten 1
19 00 Defect List Error 1, 4
19 01 Defect List Not Available
19 02 Defect List Error In Primary List
19 03 Defect List Error in Grown List
19 0E Fewer than 50% Defect List Copies
1A 00 Parameter List Length Error 5
1B 00 Synchronous Data Transfer Error
1C 00 Defect List Not Found 1, 4
1C 01 Primary Defect List Not Found
1C 02 Grown Defect List Not Found
1C 83 Seagate Unique Diagnostic Code
1D 00 Miscompare During Verify Operation E
1F 00 Number of Defects Overflows the Allocated Space That The Read Defect Command Can Handle 1
20 00 Invalid Command Operation Code 5
20 F3 Invalid linked command operation code 5
21 00 Logical Block Address Out Of Range D
24 00 Invalid Field In CDB 5
24 01 Illegal Queue Type for CDB (Low priority commands must be SIMPLE queue) 5
24 F0 Invalid LBA in linked command 5
24 F2 Invalid linked command operation code 5
24 F3 Illegal G->P operation request 5
25 00 Logical Unit Not Supported 5
26 00 Invalid Field In Parameter List 5
26 01 Parameter Not Supported 5
26 02 Parameter Value Invalid 5
26 03 Invalid Field ParameterThreshold Parameter 5
26 04 Invalid Release of Active Persistent Reserve 5
26 05 Fail to read valid log dump data 5
26 97 Invalid Field ParameterTMS Firmware Tag
26 98 Invalid Field ParameterCheck Sum
26 99 Invalid Field ParameterFirmware Tag
27 00 Write Protected 7
29 00 Flashing LED occurred 4
29 00 Power On, Reset, Or Bus Device Reset Occurred 6
29 01 Power-On Reset Occurred 6
29 02 SCSI Bus Reset Occurred 6
29 03 Bus Device Reset Function Occurred 6
29 04 Internal Reset Occurred 6
29 05 Transceiver Mode Changed To Single-Ended 6
29 06 Transceiver Mode Changed To LVD 6
29 07 Write Log Dump data to disk successful OR IT Nexus Loss 6
29 08 Write Log Dump data to disk fail 6
29 09 Write Log Dump Entry information fail 6
29 0A Reserved disc space is full 6
29 0B SDBP test service contained an error, examine status packet(s) for details 6
29 0C SDBP incoming buffer overflow (incoming packet too big) 6
29 CD Flashing LED occurred. (Cold reset) 6
29 CE Flashing LED occurred. (Warm reset) 6
2A 01 Mode Parameters Changed 6
2A 02 Log Parameters Changed 6
2A 03 Reservations preempted 6
2A 04 Reservations Released 6
2A 05 Registrations Preempted 6
2C 00 Command Sequence Error 5
2F 00 Tagged Commands Cleared By Another Initiator 6
31 00 Medium Format Corrupted 3
31 01 Corruption in R/W format request 3
31 91 Corrupt World Wide Name (WWN) in drive information file 3
32 00 No Defect Spare Location Available 4
32 01 Defect List Update Error 3, 4, 5
32 02 No Spares AvailableToo Many Defects On One Track
32 03 Defect list longer than allocated memory 3
33 00 Flash not ready for access 3
35 00 Unspecified Enclosure Services Failure 4
35 01 Unsupported Enclosure Function 5
35 02 Enclosure Services Unavailable 2
35 03 Enclosure Transfer Failure 4
35 04 Enclosure Transfer Refused 4
37 00 Parameter Rounded 1
3D 00 Invalid Bits In Identify Message
3E 03 Logical Unit Failed Self Test 4
3E 00 Logical Unit Has Not Self Configured Yet
3F 00 Target Operating Conditions Have Changed 6
3F 01 Device internal reset occurred 6
3F 02 Changed Operating Definition 6
3F 05 Device Identifier Changed 6
3F 0F Echo buffer overwritten B
3F 80 Buffer contents have changed 1
3F 90 Invalid APM Parameters
3F 91 World Wide Name (WWN) Mismatch 6
40 01 DRAM Parity Error 1, 4
40 02 Spinup Error recovered with retries 1
42 00 Power-On Or Self-Test Failure 4
42 0A Port A failed loopback test 4
42 0B Port B failed loopback test 4
43 00 Message Reject Error B
44 00 Internal Target Failure 1, 3, 4
44 F2 Data Integrity Check Failed on verify 4
44 F6 Data Integrity Check Failed during write 4
44 FF XOR CDB check error 4
45 00 Select/Reselection Failure B
47 00 SCSI Parity Error B
47 03 Information Unit CRC Error B
47 80 Fibre Channel Sequence Error B
48 00 Initiator Detected Error Message Received B
49 00 Invalid Message Received B
4B 00 Data Phase Error B
4B 01 Invalid transfer tag B
4B 02 Too many write data B
4B 03 ACK NAK Timeout B
4B 04 NAK received B
4B 05 Data Offset error B
4B 06 Initiator response timeout B
4C 00 Logical Unit Failed Self-Configuration
4E 00 Overlapped Commands Attempted B
55 01 XOR Cache is Not Available
55 04 PRKT table is full 5
5B1 00 Log Exception
5B* 01 Threshold Condition Met
5B* 02 Log Counter At Maximum
5B* 03 Log List Codes Exhausted
5C 00 RPL Status Change 6
5C 01 Spindles Synchronized
5C 02 Spindles Not Synchronized
5D 00 Failure Prediction Threshold Exceeded 1, 6
5D FF False Failure Prediction Threshold Exceeded 1, 6
65 00 Voltage Fault 4
80 00 General Firmware Error Qualifier 9
80 86 IOEDC Error on Read 9
80 87 IOEDC Error on Write 9
80 88 Host Parity Check Failed 9
80 89 IOEDC Error on Read Detected by Formatter 9
80 8A Host FIFO Parity Error detected by Common Buffer 9
80 8B Host FIFO Parity Error detected by frame buffer logic 9
80 8C Host Data Frame Buffer Parity Error 9
81 00 Reassign Power Fail Recovery Failed
81 00 LA Check Error, LCM bit = 0 4
81 00 LA Check Error B
B4 00 Unreported Deferred Errors have been logged on log page 34h 6

-------------------------------------------
c++filt C++FILT  tools to resolve c++ function overload
same function name
-------------------------------------------
VALGRIND MALLOC FREE MEMORY NEW DELETE valgrind malloc free memory new delete 
valgrind ./mytest
==17390== 
==17390== HEAP SUMMARY:
==17390==     in use at exit: 10 bytes in 1 blocks
==17390==   total heap usage: 1 allocs, 0 frees, 10 bytes allocated
==17390== 
==17390== LEAK SUMMARY:
==17390==    definitely lost: 10 bytes in 1 blocks
==17390==    indirectly lost: 0 bytes in 0 blocks
==17390==      possibly lost: 0 bytes in 0 blocks
==17390==    still reachable: 0 bytes in 0 blocks
==17390==         suppressed: 0 bytes in 0 blocks
==17390== Rerun with --leak-check=full to see details of leaked memory
==17390== 
==17390== For counts of detected and suppressed errors, rerun with: -v
==17390== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 6 from 6)
-------------------------------------------

#define MS_VS_2010 1600
#if defined(_MSC_VER) 
#if (_MSC_VER == MS_VS_2010)
#pragma pack(push,1)
typedef struct
{
    uint32_t size;
    uint8_t compression_level;

} lzps_header_t;
#pragma pack(pop)
#endif /* _MSC_VER == MS_VS_2010 */
#else  /* defined(_MSC_VER) */
typedef struct
{
    uint32_t size;
    uint8_t compression_level;
} lzps_header_t __attribute__((aligned(8)));
#endif /* defined(_MSC_VER) */

-------------------------------------------


If you use vim, then here is how to integrate it (assuming your vim was compiled with the cscope option):
 
add the cscope database:
:cs add cscope.out
open a file
:cs find f <file-fragment> -- can abridge "find" to "f"
grep for text
:cs find t <string>
use the cscope.out as tag database:
:set cscopetag
get help
:cs help
 
Or, to automate, add that stuff to your .vimrc:
 
if has("cscope")
    " use both cscope and ctag for 'ctrl-]', ':ta', and 'vim -t'
    set cscopetag
    " check cscope for definition of a symbol before checking ctags
    set csto=0
    " add any cscope database in current directory
    if filereadable("cscope.out")
        cs add cscope.out 
endif
 
you can also map keys to grep for stuff under the cursor, or go from match to match:
 
  :map <F6> *:cs find t <C-R>=expand("<cword>")<CR><CR> -- grep text (and highlight)
  :map <F5> *:cs find s <C-R>=expand("<cword>")<CR><CR> -- grep c symbols (and highlight)
  :map <F1> :tnext<CR>    -- next match   
  :map <F2> :tprev<CR>   -- previous match
While we are at it, make sure you don't add tabs into source code:
  :set expandtab    -- don't add tabs to source code!!!
  :set scrolloff=5  -- start scrolling 5 lines before bottom/top
 
To create your own cscope database (more restricted -> less hits, faster; add non-c file types...)
find . \( -path './third-party' -prune -o \
          -path './build' -prune \
       \) -o \
       \( -name "*.[ch]" -o -name "*.cc" -o -name "*.cmd" -o \
          -name "*.cmds" -o -name "*.xml" -o -name "*.mk" \
       \) -print > fl
find ./build/defs -name "*.mk" -print >> fl
find ./build/config.files -name "*" -print >> fl
echo "routing-sw/infra/clis/component_list.cfg" >> fl
echo "routing-sw/infra/clis/modes.defs" >> fl
echo "include/isan/mts_opc.def" >> fl
echo "feature/vsh/demo/cbe/cbe_README.txt" >> fl
cscope -b -i fl -q

-------------------------------------------
show something | grep -A 5 -B 2 -i myGREPtextHERE
-------------------------------------------
awk AWK
kill -9 `ps -afe | grep MYTEXT | awk '{print $2}' `

-------------------------------------------
in vi to delete blank lines   :%g/^$/d

in vi to search blank lines
:%s/oldpatern/newpatern/g
:%g/oldpatern/newpatern/d

vim search    SAME as just commandline grep.....
:lvimgrep mySearchPattern   MyFile | lopen
:lvimgrep /myclass::myfunction/j work/src/mytree/*.[ch]*  |  lopen
------------------------------------------- /**/

http://www.softwareinterview.com/

set reset 1 bit
union  code for access as 4 char, 2 words, 1 int  union

code big-endian or little-endian checker

stack, grow or decrease

string-reverse

bubble-sort

two code paths incrementing same variable, how to protect
  mutex   pthread_mutex_init pthread_mutex_lock  pthread_mutex_unlock
  or
  semaphore  sem_init  sem_wait  sem_post

signal
    pthread_cond_wait reciprocal pthread_cond_signal
    or
    sem_wait          reciprocal sem_post

Ask GDB: command for thread debugging: thread apply all bt
How does gdb breakpoint at your function

How does user application enter kernel mode
    1. system call  (read, write, ioctl)
    2. hardware interrupt from disk/network
    3. Illegal pointer access.

Code to insert 1 element into right/left binary single link-list



-------------------------------------------
set_reset_one_bit( int reset_flag, int bitnum )
{
    if ( reset_flag ) {
        /* reset */
        variable_name &= ( ~(1<< bitnum));
    } else {
        /* set */
        variable_name |= (1<< bitnum );
    }
}

-------------------------------------------
ldd Linux Device Drivers,Jonathan Corbet, Alessandro Rubini, Greg Kroah-Hartman
pdf PDF http://lwn.net/Kernel/LDD3/  PDF pdf 
html HTML http://www.makelinux.net/ldd3/  html HTML

Understanding linux kernel Daniel Bovet & Marco Cesati
Linux kernel by Robert Love


#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,10) // x86 newer kernels
because LINUX_VERSION_CODE 2.6.10 is #define 0x02060a (in decimal it is 132618)
/* do coding for new kernel */
#else
/* code for old kernel */
#endif
-------------------------------------------
#if defined( SUP2 ) || defined (ISOLA )
#endif

ALSO

#ifdef
#elif defined( SUP2S_BOOT )
#elif defined( SUP2S )
#endif

ALSO:

#if !defined( SUPDC3 )    SAMEAS  #ifndef SUPDC3

#endif
-------------------------------------------
LINUX NETWORK  IFCONFIG linux network  ifconfig
vi /etc/sysconfig/network
NETWORKING=yes
HOSTNAME=localhost.localdomain
GATEWAY=172.23.148.1
---AND THEN----
vi /etc/sysconfig/network-scripts/ifcfg-eth0
DEVICE=eth0
BOOTPROTO=static
ONBOOT=yes
IPADDR=172.23.148.165
NETMASK=255.255.255.0
---AND THEN----
vi /etc/resolv.conf
search cisco.com
nameserver 171.69.2.133
---AND THEN----
# service network restart
-------------------------------------------
SNOOP
1. become super-root on server-machine-A and give
snoop -o filename.bin -d hme0 machine-B
 
2. go to other machine-B and invoke ftp/telnet to server-machine-A
ftp or telnet server-machine-A
 
3. Go to server-machine-A and give
snoop -i filename.bin -x 0  -v  >  file.txt
                        ^^^ZERO
 
===================================================================
#define MIN( _x, _y) ( ( _x < _y ) ? _x : _y)
#define MAX( _x, _y) ( ( _x > _y ) ? _x : _y)
===================================================================
__builtin_return_address( 0 )  to get address of caller 1 previous
__builtin_return_address( 1 )  to get address of caller 2 previous
__builtin_return_address( 2 )  to get address of caller 3 previous

in Linux driver, to print the name of process
printk("<1> RAVII=%s setting BAUD to %d\n", current->comm);

===================================================================
THEORY OF T10DIF
T10 DIF t10 dif Martin K Petersen martin.petersen@oracle.com

SCSI spec is at: SBC3 sbc3r36.pdf section_4.22  and appendix C has the CRC algorithm

typedef struct block_with_t10dif_
{
   uint8_t  data[ 512 ];
   uint16_t guardCRC;   /* half-word (short) 16bit CRC checksum */
   uint16_t appTag;     /* half-word (short) 16bit OS opague unused */
   uint32_t refTagLBA;  /* 32bit uint LBA */

} block_with_t10dif_t ;

 ___________________________________________
|                   511 |512 |514 |516..... |
|                       |513 |515 | .....519|
|                       |crc |app |LBA/Ref  |
|                       |gurd|    |         |
|_______________________|____|____|_________|

 512+8 =  520  SAN IO block size
4096+8 = 4104 less than 4160  NAS filesystem block size
we loose 56 bytes extra per 4k
But disks are not formatted to 4k blocksize, why? Answer is simple:
to support both 512_SAN & 4k_NAS at the same time.
we Simulated 4k using 520 This result in extra wasted 64bytes
8bytes per 520 block, 8 such blocks make 4k. 8bytes per each
520 block, we end up with 64 wasted bytes, but we only need 8bytes
for guardCRC+appTag+refTagLBA

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

===================================================================

// RAVIII downloaded by RSIII on Wed Jan  7 16:19:43 PST 2015
// from http://www.t10.org/drafts.htm and SBC-3 section 4.22
// and Appendix C

// gcc -o t10dif t10dif.c
// $ ./t10dif
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



===================================================================
SAS 10K RPM 3.5 Inch 4teraByte sequential 180MB/s (ie, in 1 second
it can read sequential 360,000 blocks sequentially
===================================================================

#define ASSERT(_x) {                                                  \
    if (!(_x)) {                                                      \
        printf("Assertion failed in %s: %s:%d\n", __FUNCTION__,       \
                                                 __FILE__, __LINE__); \
        /*  1/0;    cause panic */                                    \
    }                                                                 \
}

===================================================================
/* packed PACKED */
typedef struct lc_online_
{
    uint8             mod_num                PACKED; 
    uint8             module_type            PACKED;
    uint8             module_state           PACKED;
    uint8             logical_node_index     PACKED;
    uint16	          n_procs                PACKED;
    uint16            Pad0                   PACKED;
    uint32            lc_node                PACKED;
    uint16            node_id                PACKED; 
}lc_online_t;

/* specific bit fields */
typedef struct sys_serial_param_s {
    unsigned long baudrate:4;       // BITS[00-03] = baud rate
    unsigned long parity:2;         // BITS[04-05] = parity
    unsigned long data_width:2;     // BITS[06-07] = data-width
    unsigned long stop_bits:2;      // BITS[08-09] = stop-bit
    unsigned long flow_ctrl:2;      // BITS[10-11] = flow-control
    unsigned long rsvd:20;          // BITS[12-31] = reserved
} __attribute__ ((packed)) sys_serial_param_t;

struct GenDiagnosticPage
{
    UINT8   pageCode;
    UINT8   Brix_type;
    UINT16  length;
} __attribute__ ((packed));


===================================================================
clock_nanosleep is better than old nanosleep because clock_nanosleep gives two choices, either
relative time, or absolute time.
clock_gettime  and clock_nanosleep

           struct timespec {
               time_t tv_sec;        /* seconds */
               long   tv_nsec;       /* nanoseconds [0 .. 999999999] */
           };

/* timer sleep for 1s  */
struct timespec mytimespec; mytimespec.tv_sec = 1; mytimespec.tv_nsec = 0; nanosleep(&mytimespec, NULL);

/* timer sleep for 1nanos  */
struct timespec mytimespec; mytimespec.tv_sec = 0; mytimespec.tv_nsec = 1; nanosleep(&mytimespec, NULL);

/* timer sleep for 1micro-second (ie. 1000nano) */
struct timespec mytimespec; mytimespec.tv_sec = 0; mytimespec.tv_nsec = 1 * 1000; nanosleep(&mytimespec, NULL);

/* timer sleep for 1milli-second (ie. 1000*1000nano) */
struct timespec mytimespec; mytimespec.tv_sec = 0; mytimespec.tv_nsec = 1 * 1000 * 1000; nanosleep(&mytimespec, NULL);

/* timer sleep for 500ms  */
struct timespec mytimespec; mytimespec.tv_sec = 0; mytimespec.tv_nsec = 500 * 1000 * 1000; nanosleep(&mytimespec, NULL);

GETTIMEOFDAY
    #include <sys/time.h>
    struct timeval tv;
	static  char        time_string[ 30 ] ;
    uint32   timestamp_jiffy;
    long  time_in_secs; 
    long  time_in_usecs;
    FILE *myfp;  myfp = fopen("/tmp/test", "a");
    gettimeofday(&tv, 0);
    fprintf( myfp, "%s:%d  Time:%s and %lu usecs \n", __FUNCTION__, __LINE__,
                  asctime(localtime(&tv.tv_sec)), tv.tv_usec );
	strftime(time_string,TIME_STRING_SIZE,"%m-%d-%Y  %T",localtime(&tv.tv_sec));
	printf(" %s and %ul usec \n", time_string,  tv.tv_usec );
    /**** or us can use it by yourself as
    time_in_secs = tv.tv_sec;
    time_in_usecs = tv.tv_usec;
    timestamp_jiffy = tv.tv_sec;
    ****/

    fflush(myfp);

===================================================================

how to use VA_ARG

"..." is same as __VA_ARGS__

#define my_printf(...)        \
   ({  \
       char temp_buf[ 4096 ];        \
       int retval = snprintf( temp_buf,  4096 , __VA_ARGS__);        \
       PrtF("%s",  temp_buf);        \
       retval;     \
   })
  


#define PFM_SPROM_INFO_GET_FLD(...)  pfm_sprom_info_get_field(__FUNCTION__,__LINE__,__VA_ARGS__)
retval = PFM_SPROM_INFO_GET_FLD( SPROM_TYPE_LCARD, sprom_inst,
                    &pfm_sprom_info.lc_sprom[module_no][sprom_inst],
                    cmn_snum, &spfld_cb_serial_number);
and actual function is:
pfm_sprom_info_get_field(
    const char *func_name, int line_num,
    sprom_type_t type, uint8 inst_no, void *sprom_data,
    dc_sprom_field_t sprom_field, dc_sprom_get_field_params_t *p_get_params)
{
 blah, balh
}

#define MYPRINT(param, args...) printf(param" of %s\n",##args, __FUNCTION__)

#define QENG_SENSOR_STR(qeng_inst_, sensor_)  "QEng" #qeng_inst_ "Sensor" #sensor_
main() {
 QENG_SENSOR_STR(1,2);
 will result in macro-expansion  "QEng1Sensor2
}


#define MYPRINT(param, args...) printf(param" of %s\n",##args, __FUNCTION__)
see also __VA_ARGS__


#define DISPLAY()  printf("DISPLAY %s: %s:%d\n", __FUNCTION__,\
                                            __FILE__, __LINE__)

#define DEV_LOG_SUP_DEBUGTMP(_fmt...) \
{\
   char _buf[DEV_LOG_SUP_DEBUGTMP_BUF_SIZE]; \
   snprintf(_buf, DEV_LOG_SUP_DEBUGTMP_BUF_SIZE, "Func: %s Line:%d ",\
                                            __FUNCTION__, __LINE__ ); \
   snprintf(_buf+strlen(_buf), DEV_LOG_SUP_DEBUGTMP_BUF_SIZE, ##_fmt); \
   if (FP!=NULL) {\
       fprintf(FP, _buf); \
       fflush(FP); \
   } else {\
       printf("%s", _buf); \
   }\
}
DEV_LOG_SUP_DEBUGTMP("skip=%d\n", dev_log_skip_first_two);
===================================================================

typedef enum MIGR_FUNC_STATE_ENUM
{
    MIGR_NEWCMD=1,
    MIGR_SAVE_INITWM,
    MIGR_DO_RWCT,
    MIGR_SAVE_GETPERCENT,
} MIGR_FUNC_STATE_ENUM_t;

===================================================================
DTR DSR TX RX DCD

computerDTE         DCE MODEM or TTY
tx out ---------->  rx in
rx in  <----------  tx out
DTR out --------->  DSR in
DSR in  <--------   DTR out
RTS out --------->  CTS in
CTS in <----------  RTS out

DCD in <----------- Data Carrier detect
RI  in <----------- Ring indicator

pin4   Modem TxD   Output     Transmit data to modem. connected to modem Rx
pin5   Modem RxD   Input      Received data from modem, connected to modem Tx
pin6   Modem RTS   Output     Request to send and wait for DCE(Modem) CTS
pin7   Modem CTS   Input      Clear to send to ack the DTE RTS
pin8   Modem DCD   Input      Data Carrier detect
pin9   Modem DSR   Input      DCE(Modem) ready
pin10  Modem DTR   Output     DTE(Isola) ready
pin11  Modem  RI   Input      Ring Indicator

===================================================================
pointer function
    void    (*action_fn)(int signo);


//For sighandlers install.
MAIN thing is "        struct sigaction myaction" see further below
    struct sigaction action;
    action.sa_flags = 0;
    sigemptyset(&action.sa_mask);
    action.sa_handler = ttyd_sigterm_handler;
    sigaction(SIGTERM, &action, (struct sigaction *)NULL);
    // Thats it done  ttyd_sigterm_handler() is just printf or whatever
----alternate fancy implementation-------------------
struct xyz
{
    int     signo;
    char    *signame;
    int     sa_flags;
    void    (*action_fn)(int signo);
    struct sigaction    oldsigact;
} master_sighandler_list[] = {
    {SIGTERM, "SIGTERM", 0, ttyd_sigterm_handler},
    {SIGABRT, "SIGABRT", 0, ttyd_sigabrt_handler},
    {0, NULL, 0, NULL}
};
/**
 ** ttyd_sigterm_handler()
 ** @arg - Signal number.
 ** Description: This function handles SIGTERM.
 **              It sets ttyd_done to TRUE such that the
 **              ttyd comes out of the main while loop.
 ** Returns:     Nothing.
 **/
void
ttyd_sigterm_handler (int arg)
{
    ttyd_done = TRUE;
}
/**
 ** ttyd_sigabrt_handler()
 ** @arg - Signal number.
 ** Description: This function handles SIGABRT.
 **              It sets ttyd_done to TRUE such that the
 **              ttyd comes out of the main while loop.
 ** Returns:     Nothing.
 **/
void
ttyd_sigabrt_handler (int arg)
{
    ttyd_done = TRUE;
}
/**
 ** ttyd_sighandlers_install() - Installs a handler for all supported signals.
 ** Description: This function installs a handler for all supported signals.
 ** Returns:     0 upon success, else -1.
 **/
int
ttyd_sighandlers_install (void)
{
    int ret_val, i = 0;

    while(master_sighandler_list[i].signame != NULL) {
        struct sigaction act;
        bzero(&act, sizeof(act));
        act.sa_handler = master_sighandler_list[i].action_fn;

        sigemptyset(&(act.sa_mask));

        act.sa_flags = master_sighandler_list[i].sa_flags;

        ret_val = sigaction(master_sighandler_list[i].signo, &(act),
                                &(master_sighandler_list[i].oldsigact));

        if (ret_val < 0) {
            return ret_val;
        }

        i++;
    }

    return 0;
}
int ttyd_exit = FALSE;
main()
{
    ttyd_sighandlers_install();
    while ( ttyd_exit == FALSE ) {
    }
}

===================================================================
 
main()
{
unsigned int lgcl_strtblk;
unsigned int lgcl_endblk;
unsigned int mrst_strtblk;
unsigned int mrst_endblk;
 
mrst_strtblk = 200;
mrst_endblk = mrst_strtblk + 100;
 
while (1) {
 
printf("\nlgcl_strtblk: "); scanf("%d", &lgcl_strtblk);
printf("lgcl_len: "); scanf("%d", &lgcl_endblk);
lgcl_endblk += lgcl_strtblk;
printf("mrst_strtblk=%d\tmrst_endblk=%d\n", mrst_strtblk,mrst_endblk);
printf("lgcl_strtblk=%d\tlgcl_endblk=%d\n", lgcl_strtblk,lgcl_endblk);
 
        if (((lgcl_strtblk >= mrst_strtblk) && (lgcl_strtblk < mrst_endblk)) ||
((lgcl_endblk > mrst_strtblk) && (lgcl_endblk < mrst_endblk)) || ((lgcl_strtblk
< mrst_strtblk) && (lgcl_endblk > mrst_endblk))) {
                /*
                ** we found conflicting range; return true.
                */
                printf("CONFLICT\n");
                continue;
        }
        printf("No cnflct\n");
}
 
}



chksum()
{
	int retval = 0;

	retval ^= dram_p->field1;
	retval ^= dram_p->field2;
	retval ^= dram_p->field3;
	retval ^= 0x1234; /* some additional offset for safety */
	return (retval);
}

=====================================================================
XOR-concept
 
main()
{
 
unsigned int a;
unsigned int b;
unsigned int c;
unsigned int d;
unsigned int p;
unsigned int a1;
unsigned int b1;
unsigned int c1;
unsigned int d1;
 
a = 0x12345678;
b = 0xfedcba98;
c = 0xff0000ff;
d = 0x000fe000;
 
p = (((a ^ b) ^ c ) ^d );
 
 
a1 = (((p ^ b) ^ c ) ^ d );
b1 = (((a ^ p) ^ c ) ^ d );
c1 = (((a ^ b) ^ p ) ^ d );
d1 = (((a ^ b) ^ c ) ^ p );
 
printf("a= %x  b= %x  c= %x  d= %x\n", a, b, c, d);
printf("p= %x\n", p);
printf("a= %x  b= %x  c= %x  d= %x\n", a1, b1, c1, d1);
 
 
}
 
 
====================================================================


/***** CAUTION: DO NOT PUT BRACKET around the following MACRO define ***/
#define U64_GET_HI_LO( _xx)  (u32)((_xx >> 32)  & 0xFFFFFFFF), (u32)(_xx & 0xFFFFFFFF)
long long u64_variable_xx;
printf("Hi32bytes=%x low32bytes=%x\n", U64_GET_HI_LO( u64_variable_xx);
/***** CAUTION: DO NOT PUT BRACKET around the following MACRO define ***/

OR  OR  OR
#include <asm/byteorder.h>
uint64 var;
var = __be64_to_cpu( var);


====================================================================

#define reg_read32 (_addr, _val) \
  { uint32 a = addr; uint32 *p = _val; \
    __asm__ __volatile__ ( "lwz %0,0(%1)\n\t" "eieio\n\t" : 
"=r"(*p) : "r"(a) : "memory") \
  }

#define reg_write32 (_addr, _val) \
  { uint32 a = addr; uint32 p = _val; \
    __asm__ __volatile__ ( "stw %0,0(%1)\n\t" "eieio\n\t" : : 
"r"(p), "r"(a) : "memory") \
  }

====================================================================
MRESTORE percentage complete
main()
{

int vp_size, vp_lba;

double max, cur, ans;
unsigned int in_ans;


vp_size = 2147483647;
vp_size = 61439952;

printf("cur = ");
scanf("%d", &vp_lba);

max = (double) vp_size;
cur = (double) vp_lba;

ans = cur * 100;
printf("mul %lf\n", ans);

ans = ans/max;
in_ans = (int)ans;
printf("div %u\n", in_ans);

}

/******
main()
{

unsigned int max, cur, ans;


max = 61439952;

printf("cur = ");
scanf("%u", &cur);

ans = cur * 100;
printf("mul %u 0x%x\n", ans, ans);

ans = ans/max;
printf("div %u 0x%x\n", ans, ans);

}
****/
====================================================================
SET_RESET_macro
 
typedef unsigned long u_long;
typedef unsigned int u_int;
typedef unsigned char u_char;
#ifndef BBSIZE
#define BBSIZE          (8*1024) /* from <auspex/fp/fs.h> */
#endif
 
#define VD_NONE         0       /* Not defined */
#define VD_CONCAT       1       /* Concatenated partition */
#define VD_STRIPE       2       /* Striped partition */
#define VD_MIRROR       3       /* Mirrored partition */
#define VD_BAD          VD_NONE
 
#define CLEAN           0x01    /* different partition status */
#define ACTIVE          0x02
#define DIRTY           0x04
#define RESTORING       0x08
#define DAMAGED         0x10
#define CHECKPOINTED    0x20
#define FSP_MAX_CHANNELS        8       /* max SCSI channels per FSP */
#define FSP_MAX_TARG            7       /* max targets per adapter */
#define FSP_MAX_DISKS           (FSP_MAX_CHANNELS * FSP_MAX_TARG)
#define FSP_MAX_PARTITIONS      8
#define MAX_VDISK_PARTS 16
#define SP_MAX_VPARTS   256
 
/*
 * A few general useful macros and defines
 */
#define OPEN_FLAG               1
#define MOUNT_FLAG              OPEN_FLAG
#define CLOSE_FLAG              0
#define UMOUNT_FLAG             CLOSE_FLAG
#define BITS(_type)             (8 * (int)sizeof(_type))
#define MIN_STRIPE_SZ           (8 * 1024)      /* 8K i.e. 16 sectors */
#define SKIP_START_BLK          16              /* 8K i.e. 16 sectors */
#define START_BLK_NO            0
#define BLK2SGPAGE(_x)  \
        ((_x>0) ? ((_x>MRESTORE_NBLKS) ?0: ((((_x*BDEV_SIZE)-1)/BBSIZE)+1)) :0)

#define LASTSGPGLEN(_blk) ((((_blk * BDEV_SIZE) -1) % BBSIZE) +1)
 
#define VP_SET(_arry, _indx)    \
                        (vpflg_ptr->_arry[_indx/BITS(vpflg_ptr->_arry[0])]) \
                                |= (1<<(_indx % BITS(vpflg_ptr->_arry[0])))
#define VP_RESET(_arry, _indx)  \
                        (vpflg_ptr->_arry[_indx/BITS(vpflg_ptr->_arry[0])]) \
                                &= ~(1<<(_indx % BITS(vpflg_ptr->_arry[0])))
#define VP_TEST(_arry, _indx)   \
                        (vpflg_ptr->_arry[_indx/BITS(vpflg_ptr->_arry[0])]) \
                                & (1<<(_indx % BITS(vpflg_ptr->_arry[0])))
 
typedef struct {                /* virtual partition statistical data */
    u_long sectors_read;
    u_long sectors_written;
    struct {
        u_long io_count;
    } member_part[MAX_VDISK_PARTS];
} VPAR_STATS;
 
typedef struct {
        u_long  overlap[FSP_MAX_DISKS][FSP_MAX_PARTITIONS];
        u_long  pp_inuse[FSP_MAX_DISKS];                /*      ::32PP:: */
        u_long  vp_inuse[SP_MAX_VPARTS/BITS(u_long)];
        u_long  vp_ok[SP_MAX_VPARTS/BITS(u_long)];
} vp_state_flags_t;
 
 
typedef struct vpart {
    long        nparts;         /* Number of partitions in vdisk. */
    long        status;         /* partition status. (DIRTY etc) */
    long        oflags;         /* new flag: open for writing */
    long        vp_type;        /* vpart type. */
    long        vp_size;        /* total number of sectors */
    long        stripe_size;        /* Stripe size in 512 byte blocks. */
    long   part_desc[MAX_VDISK_PARTS]; /* Partition descriptions. */
} VPART;
 
main()
{
int i;
VPAR_STATS vps[SP_MAX_VPARTS];
vp_state_flags_t vpf;
vp_state_flags_t *vpflg_ptr = (vp_state_flags_t *)&vpf;
int vpnn = 6;
(vpf.vp_ok[vpnn/BITS(vpflg_ptr->vp_ok[0])]) |= (1<<(vpnn % BITS(vpf.vp_ok[0])));
printf("%x\n",vpf.vp_ok[0]);
VP_RESET( vp_ok, vpnn);
printf("%x\n",vpf.vp_ok[0]);
VP_SET( vp_ok, vpnn);
printf("%x\n",vpf.vp_ok[0]);
printf("vps=%d   vpfla=%d \n", sizeof(vps), sizeof(vp_state_flags_t));
printf("vps=%d   vpfla=%d \n", (sizeof(VPAR_STATS)* SP_MAX_VPARTS), sizeof(vp_state_flags_t));
 
printf("vpfull=%d   vpptr=%d \n", (sizeof(VPART) * SP_MAX_VPARTS), (sizeof(VPART *) * SP_MAX_VPARTS));
printf("VPART=%d\n",sizeof(VPART));
printf("flg_ptr->Ok=%d\n",sizeof( vpflg_ptr->vp_ok));
printf("flg_ptr->vp_inuse=%d\n",sizeof( vpflg_ptr->vp_inuse));
printf("flg_ptr->pp_inuse=%d\n",sizeof( vpflg_ptr->pp_inuse));
}
===================================================================
SIZEOF struct
 
struct xx {
int a1;
int b1;
int c1;
int d1;
int a2;
int b2;
int c2;
int d2;
} xx;
 
 
#define SZ (sizeof(xx) * 20)
 
main()
{
unsigned int valu, blk;
int arr[SZ ] ;
 
struct xx {
int a1;
int b1;
int c1;
int d1;
int a2;
int b2;
int c2;
int d2;
} xx;
 
printf("\n szof=%d\n", sizeof(xx));
printf("\n SZ=%d arr=%d\n", SZ, sizeof(arr));
 
}
 
/*
fun(2);
printf("x= %x\n",x);
*/
 
#ifdef  VP_STRATEGY

The main concept is give here...... look for detail code further down.....
 
                case VD_CONCAT: {
                        for ( vp_indx = 0; vp_indx < (vp->nparts); vp_indx++) {
                               /*
                                ** get correct skip_adjusted len of this phypart
                                */
                                lrq->lr_errno = DEV_TO_PSIZE2(
                                        vp->part_desc[vp_indx],&ad_partsz_blk);
                               if (lrq->lr_errno)
                                        goto done;
 
                                if (v_addr < ad_partsz_blk) break;
                                else v_addr -=ad_partsz_blk;
                        }
                        break;
                }
 
                case VD_STRIPE: {
                        stripe_no = v_addr / vp->stripe_size;
                        stripe_offset = v_addr % vp->stripe_size;
                        stripe_group = stripe_no / vp->nparts;
                        vp_indx = stripe_no % vp->nparts;
                        v_addr =((stripe_group*vp->stripe_size)+stripe_offset);
                        break;
                }
 
/*
** Main VP routing module
*/
void
vp_strategy(lrq)
	FSP_LOGRQ_T *lrq;
{
	VPART		*vp;
	FSP_TRANSCTL_T	*tctl;	
	struct fsp_physrequest	**last_p;
	int		tot_prqs = 0;
	int 		errno = 0;

	vp = dev_to_vpart(lrq->lr_dev);
	if ((vp==NULL) || (vp->vp_type == VD_NONE)) {
		errno = EVP_NODEVTAB;
		glb_errdev = lrq->lr_dev;
		glb_errfun = (u_int) vp_strategy;
		goto done;
	}

	/*
	** check for overun
	*/
	if ((lrq->lr_blockno + lrq->lr_nblocks) > vp->vp_size) {
		errno = EFBIG;
		glb_errdev = lrq->lr_dev;
		glb_errfun = (u_int) vp_strategy;
		goto done;
	}

	/*
	 *  Fill in the transaction control fields to link it all together.
	 */
	tctl = &u.u_tctl;
	tctl->tc_physrqsts = NULL;
	last_p = &(tctl->tc_physrqsts);

	/*
	** Call the appropriate routines. They return the total number of phys
	** requests composed ready to be sent down. In case of error, they
	** return NULL, with the appropriate error codes stuffed in lrq->errno
	*/
	switch( vp->vp_type) {

		case VD_STRIPE:
		case VD_CONCAT:
			{
			tot_prqs = catstripe( lrq, vp, last_p);
			break;
		}

		case VD_MIRROR: {
			tot_prqs = mirror_rw( lrq, vp, last_p);
			break;
		}

		default: {
			tot_prqs = 0;
			lrq->lr_errno = EVP_XTYPE;
			break;
		}
	}

	if (tot_prqs == 0) {
		free_prqs( VD_NONE);	/* drop the errno_retval of free_prqs*/
		errno = lrq->lr_errno;	/* on floor, use lr_erno instead */
		goto done;
	}

	/*
	 *  Send the physical request down and Wait for completion.
	 */
	tctl->tc_nphys = tctl->tc_nwaiting = tot_prqs;
	vp_dispatch(tctl->tc_physrqsts);
	errno = free_prqs( VD_NONE);

done:
	lrq->lr_errno = errno;
	if (errno)
		log(LOG_ERR, "WARN!! Phys-ERROR: lr_dev=0x%x lr_errno=0x%x\n",
					lrq->lr_dev, lrq->lr_errno);
	return;
}


/*
** Routine to process concat or stripe vp. It returns the number of phys_reqs
** it composed which can be sent down to physical layer. If there is some error
** encountered it returns 0, with the error code stuffed inside lrq->lr_errno.
*/
static int
catstripe( lrq, vp, lpc)
	FSP_LOGRQ_T	*lrq;
	VPART		*vp;
	struct fsp_physrequest	**lpc;
{
	FSP_TRANSCTL_T	*tctl;	
	FSP_PHYSRQ_T 	*prq = NULL;
	FSP_PHYPART_T	*phys_part;
	int i, vp_indx, sg_indx, sg_ofst_byt, retval, lcl_nsg;
	int v_addr, block_left, phys_blk_addr, phys_xfer_blk;
	int ad_partsz_blk, ad_sgpagesz_byt;
	int stripe_no, stripe_offset, stripe_group;

	retval = vp_indx = sg_indx = sg_ofst_byt = lcl_nsg = 0;
	stripe_no = stripe_offset = stripe_group = 0;
	v_addr = lrq->lr_blockno;
	block_left = lrq->lr_nblocks;
	tctl = &u.u_tctl;

	/*
	** Get to the start of the required partition. Locate v_addr & vp_indx
	*/
	switch( vp->vp_type) {

		case VD_CONCAT: {
			for ( vp_indx = 0; vp_indx < (vp->nparts); vp_indx++) {
				/*
				** get correct skip_adjusted len of this phypart
				*/
				lrq->lr_errno = DEV_TO_PSIZE2(
					vp->part_desc[vp_indx],&ad_partsz_blk);
				if (lrq->lr_errno)
					goto done;

				if (v_addr < ad_partsz_blk) break;
				else v_addr -=ad_partsz_blk;
			}
			break;
		}

		case VD_STRIPE: {
			stripe_no = v_addr / vp->stripe_size;
			stripe_offset = v_addr % vp->stripe_size;
			stripe_group = stripe_no / vp->nparts;
			vp_indx = stripe_no % vp->nparts;
			v_addr =((stripe_group* vp->stripe_size)+stripe_offset);
			break;
		}

		default:
			retval = 0;
			lrq->lr_errno = EVP_XTYPE;
			glb_errdev = lrq->lr_dev;
			glb_errfun = (u_int) catstripe;
			goto done;
	}

	/*
	** Now that we have v_addr & vp_indx Generate phys_req
	*/
	while (block_left) {

		if ((vp_indx < 0) || (vp_indx >= vp->nparts)) {
			retval = 0;
			glb_errdev = lrq->lr_dev;
			glb_errfun = (u_int) catstripe;
			lrq->lr_errno = EVP_NXIO;	/* No such phys_part */
			goto done;
		}

		prq = (FSP_PHYSRQ_T *)k_malloc(sizeof(FSP_PHYSRQ_T),0,CPU_MEM);
		if (!prq) {
			retval = 0;
			lrq->lr_errno = ENOMEM;
			glb_errdev = lrq->lr_dev;
			glb_errfun = (u_int) catstripe;
			goto done;
		}

		retval++;
		lcl_nsg = 0;
		*lpc = prq;
		lpc = &(prq->pr_link);
		prq->pr_link = NULL;
		prq->pr_transctl = tctl;
		prq->pr_vpdev = lrq->lr_dev;

		switch(lrq->lr_opcode) {

			case SPL_READ:
			case SPL_RAW_READ:
#if junk_commented
				if (vp->oflags & FSP_WCACHE_ENABLED)
					prq->pr_opcode = SPP_READWBUF;
#endif /* junk_commented */

				prq->pr_opcode = SPP_READ;
				break;


			case SPL_WRITE:
			case SPL_RAW_WRITE:
#if junk_commented
				if (vp->oflags & FSP_WCACHE_ENABLED)
					prq->pr_opcode = SPP_WRITEBUF;
#endif /* junk_commented */

				prq->pr_opcode = SPP_WRITE;
				break;


			default:
				retval = 0;
				lrq->lr_errno = EINVAL;	/* E_BAD_ARGUMENT */
				glb_errdev = lrq->lr_dev;
				glb_errfun = (u_int) catstripe;
				goto done;
		}
		prq->pr_errno = 0;
		prq->pr_dev = vp->part_desc[vp_indx];
		prq->pr_scsi_channel = FSP_DEV_TO_CHAN( prq->pr_dev);
		prq->pr_target_id = FSP_DEV_TO_SCSIID( prq->pr_dev);

		/*
		** Now before we fill-in the remaining fields, there is some
		** work to do; Calculate the phys_block and the phys_lenght
		** And beware that the phys_lenght may overflow into next part
		*/

		/*
		** get *phys_part to check if it is first skip reserved and
		** compute "ad_partsz_blk" and "phys_blk_addr" appropriately.
		*/
		phys_part = DEV_TO_PPART( prq->pr_dev);
		if (phys_part == NULL) {
			retval = 0;
			lrq->lr_errno = EVP_NXIO;	/* No such phys_part */
			goto done;
		}

		if (phys_part->pp_base == LABEL_BLK_NO) {
			phys_blk_addr = (phys_part->pp_base+ v_addr +
								SKIP_LABEL_BLK);
			ad_partsz_blk = (phys_part->pp_sectors- SKIP_LABEL_BLK);
		} else {
			phys_blk_addr = ((phys_part->pp_base) + v_addr);
			ad_partsz_blk = phys_part->pp_sectors;
		}

		/*
		** We just calculated the "phys_blk_addr". Now we no longer
		** need "v_addr" and "ad_partsz_blk". So in case of Stripe,
		** v_addr is overloaded with stripe_offset and ad_partsz_blk is
		** overloaded with stripe_size.
		** RSIII. Mon Aug 26 11:02:08 PDT 1996
		*/
		if ( vp->vp_type == VD_STRIPE) {
			v_addr = stripe_offset;
			ad_partsz_blk = vp->stripe_size;
		}
		if ((v_addr + block_left) <= ad_partsz_blk ) {
			/*
			** The request is SMALL; and it fits within this part.
			** Most simple case; Just copy the sg_list over.
			*/
			for (i=sg_indx;i< lrq->lr_nsg;i++,sg_indx++,lcl_nsg++){
				prq->pr_sglist[lcl_nsg].sg_laddr =
					lrq->lr_sglist[i].sg_laddr+sg_ofst_byt;
				prq->pr_sglist[lcl_nsg].sg_m16_node =
					lrq->lr_sglist[i].sg_m16_node;
				prq->pr_sglist[lcl_nsg].sg_len =
					lrq->lr_sglist[i].sg_len - sg_ofst_byt;
				sg_ofst_byt = 0;
			}
			phys_xfer_blk = block_left;
			block_left = 0;
		} else {
			/*
			** The request is BIG and it spans into another
			** disk so split the SG list. CAUTION!! overloading of
			** v_addr and ... RSIII. Mon Aug 26 11:02:08 PDT 1996
			*/
			int phys_xfer_bytes = 0;

			phys_xfer_blk = ad_partsz_blk - v_addr;
			phys_xfer_bytes = (phys_xfer_blk * (BDEV_SIZE));
			block_left -= phys_xfer_blk;
			vp_indx++;
			if (vp->vp_type == VD_STRIPE) {
				if (vp_indx == vp->nparts) {
					vp_indx = 0;
					stripe_group++;
				}
				stripe_offset = 0;
				v_addr = ((stripe_group * vp->stripe_size) +
								stripe_offset);
			} else v_addr = 0;
			for (i=sg_indx;i< lrq->lr_nsg;i++,sg_indx++,lcl_nsg++){
				if (phys_xfer_bytes == 0) break;
				ad_sgpagesz_byt = ((lrq->lr_sglist[i].sg_len) -
								sg_ofst_byt);
				if ( phys_xfer_bytes >= ad_sgpagesz_byt) {
					/*
					** sg_page size is smaller or exact =to
					** Transfered_Bytes; so copy the entire
					** sg_page over to phys_req;
					*/
					prq->pr_sglist[lcl_nsg].sg_laddr =
					lrq->lr_sglist[i].sg_laddr+sg_ofst_byt;
					prq->pr_sglist[lcl_nsg].sg_m16_node =
						lrq->lr_sglist[i].sg_m16_node;
					prq->pr_sglist[lcl_nsg].sg_len =
								ad_sgpagesz_byt;
					sg_ofst_byt = 0;
					phys_xfer_bytes -= ad_sgpagesz_byt;
				} else {
					/*
					** sg_page size is Bigger than
					** Transfered_Bytes; so split it and
					** use whatever is needed
					*/
					prq->pr_sglist[lcl_nsg].sg_laddr =
					lrq->lr_sglist[i].sg_laddr+sg_ofst_byt;
					prq->pr_sglist[lcl_nsg].sg_m16_node =
						lrq->lr_sglist[i].sg_m16_node;
					prq->pr_sglist[lcl_nsg].sg_len =
							phys_xfer_bytes;
					sg_ofst_byt += phys_xfer_bytes;
					phys_xfer_bytes = 0;
					lcl_nsg++; /* incr for the early brk*/
					break; /* early break */
				}
			}
		}
		prq->pr_blockno = phys_blk_addr;
		prq->pr_nblocks = phys_xfer_blk;
		prq->pr_nsg = lcl_nsg;
	}

	/*
	** Now update the statstics
	*/
	update_vpstats( lrq);

done:
	tctl->tc_nwaiting = (int)lpc;	/* meaningful only for mirror */
	return ( retval);
}


/*
** Routine to process mirror vp. Process reads and writes seperately.
** This function always returns 0.
** In case of a write: the logical request is decomposed into physical req 
** for all the active disks, All these phys_reqs are then tied together into
** one single transaction and sent down.
** In case of a read: the logical request is decomposed into physical req 
** to only one disk which is active (If both disks are active, then pick one
** arbitrarly). Read from the next disk only if the previous active read fails
** In any case (read OR write) the return error processing is done in this
** function itself. This routine always returns total_number of prqs as 0,
** because it does not rely on return error processing from/in vp_strategy().
*/
static int 
mirror_rw( lrq, vp, lpm)
	FSP_LOGRQ_T	*lrq;
	VPART		*vp;
	struct fsp_physrequest	**lpm;
{
	FSP_TRANSCTL_T	*tctl;	
	VPART		*child_vp;
	fsp_dev_t save_oldev;
	int retval, i, nlcl, ntot;

	ntot = nlcl = 0;
	tctl = &u.u_tctl;
	switch(lrq->lr_opcode) {

		case SPL_READ:
		case SPL_RAW_READ:
		{
			int which_mmbr;

			glb_indx = (glb_indx+1)%(vp->nparts);
			which_mmbr = i = glb_indx;
			do {
				child_vp = dev_to_vpart(vp->part_desc[i]);
				if ((child_vp == NULL) || (child_vp->vp_type
					== VD_NONE)){
					retval = 0;
					lrq->lr_errno = EVP_NODEVTAB_MBR;
					glb_errdev = vp->part_desc[i];
					glb_errfun = (u_int) mirror_rw;
					goto done;
				}
				if ((child_vp->status == ACTIVE) || 
						(child_vp->status == CLEAN)) {
					save_oldev = lrq->lr_dev; /* save */
					lrq->lr_dev = vp->part_desc[i];/*mdfy*/
					nlcl = catstripe(lrq,child_vp, lpm);
					lrq->lr_dev = save_oldev; /* restore*/
					if (nlcl == 0) {
						warn_vp( vp->part_desc[i]);
						free_prqs( VD_NONE);
						goto nxt;
					}
					tctl->tc_nphys =tctl->tc_nwaiting=nlcl;
					update_vpstats( lrq);
					vp_dispatch(tctl->tc_physrqsts);
					retval = free_prqs( VD_NONE);
					if (retval == 0) {
						retval = 0;
						lrq->lr_errno = 0;/*RD_SUCCESS*/
						goto done;
					} else {
						log(LOG_ERR,
			"WARNING!! VP Mrr_read error 0x%x from mmbr=0x%x\n",
						retval, vp->part_desc[i] );
						warn_vp( vp->part_desc[i]);
					}
nxt:
				}
				i = (i+1)%(vp->nparts);
			} while ( i != which_mmbr);

			/*
			** the fact that we reached here means there was read
			** error encountered on all child members. Send a
			** RD_FAIL error to user, as the read failed completly
			*/
			retval = 0;
			lrq->lr_errno = EIO;	/* RD_FAIL */
			glb_errdev = lrq->lr_dev;
			glb_errfun = (u_int) mirror_rw;
			goto done;
		}


		case SPL_WRITE:
		case SPL_RAW_WRITE:
		{
			for (i = 0; i < (vp->nparts); i++) {

				child_vp = dev_to_vpart(vp->part_desc[i]);
				if ((child_vp == NULL) || (child_vp->vp_type
					== VD_NONE)){
					retval = 0;
					lrq->lr_errno = EVP_NODEVTAB_MBR;
					glb_errdev = vp->part_desc[i];
					glb_errfun = (u_int) mirror_rw;
					goto done;
				}
				/*
				** Perform a write to the member only if it is
				** Active/clean or Restoring.
				*/
				if ((child_vp->status == ACTIVE) ||
					(child_vp->status == CLEAN) ||
					(child_vp->status == RESTORING)) {

					/*
					** Caution while write to rstr`ng mmbr
					*/
					if (child_vp->status == RESTORING) {
						caddr_t sleep_addr;
						sleep_addr = \
						mrestore_write_conflict(vp,lrq);

						while(sleep_addr) {
						k_sleep((sleep_addr),(K_PRI)0);
						sleep_addr = \
						mrestore_write_conflict(vp,lrq);
						}
					}

					save_oldev = lrq->lr_dev; /* save */
					lrq->lr_dev = vp->part_desc[i];/*mdfy*/
					nlcl = catstripe(lrq,child_vp, lpm);
					lrq->lr_dev = save_oldev; /* restore*/

					if (nlcl == 0) {
						warn_vp( vp->part_desc[i]);
						free_prqs( VD_NONE);
					} else lpm = (struct
					fsp_physrequest **)tctl->tc_nwaiting;

					ntot +=nlcl;
				}
			}

			if ( ntot == 0) {
				retval = 0;
				lrq->lr_errno = EIO;	/* WR_FAIL */
				glb_errdev = lrq->lr_dev;
				glb_errfun = (u_int) mirror_rw;
				goto done;
			}

			tctl->tc_nphys = tctl->tc_nwaiting = ntot;
			update_vpstats( lrq);
			vp_dispatch(tctl->tc_physrqsts);
			retval = free_prqs( VD_MIRROR);

			/*
			** After free_prqs has processed the return errors,
			** decide what return value to send back Up, based on
			** the new status of the child member (which gets 
			** modified to Damaged only in case of an error.)
			** Go thro all the child members and check if there is
			** atleast one non-Damaged child member.
			*/
			for (i = 0; i < (vp->nparts); i++) {

				child_vp = dev_to_vpart(vp->part_desc[i]);
				if ((child_vp == NULL) || (child_vp->vp_type
					== VD_NONE)){
					retval = 0;
					lrq->lr_errno = EVP_NODEVTAB_MBR;
					glb_errdev = vp->part_desc[i];
					glb_errfun = (u_int) mirror_rw;
					goto done;
				}
				/*
				** The fact that we found a non-damaged child
				** indicates that atleast one of the childmembr
				** mirror-write was  successful; So return a 
				** good status to user;
				** Warn-vp would have done its job of warning
				** -if- any member experienced write-error.
				*/
				if ((child_vp->status == ACTIVE) ||
						(child_vp->status == CLEAN)) {
					retval = 0;
					lrq->lr_errno = 0;	/* WR_SUCCESS*/
					goto done;
				}
			}
			/*
			** the fact that we reached here means there was write
			** error encountered on all good child members. Send a
			** WR_FAIL error to user, as the read failed completly
			*/
			log(LOG_ERR, "WARNING!! VP Mrr_write error 0x%x\n",
								retval);
			retval = 0;
			lrq->lr_errno = EIO;	/* WR_FAIL */
			glb_errdev = lrq->lr_dev;
			glb_errfun = (u_int) mirror_rw;
			goto done;
			break;
		}


		default:
			retval = 0;
			lrq->lr_errno = EINVAL;	/* E_BAD_ARGUMENT */
			glb_errdev = lrq->lr_dev;
			glb_errfun = (u_int) mirror_rw;
			goto done;
			break;
	}
done:
	return( retval);
}

sample_vpstripe_main()
{

    unsigned int stripe_no = 0;
    unsigned int v_lba = 0;
    unsigned int stripe_size = 0;
    unsigned int stripe_offset = 0;
    unsigned int stripe_group = 0;
    unsigned int nparts = 0;
    unsigned int vp_indx = 0;

    printf("enter v_lba=");scanf("%d", &v_lba);
    printf("enter stripe_size=");scanf("%d", &stripe_size);
    printf("enter nparts=");scanf("%d", &nparts);

    stripe_no = v_lba / stripe_size;
    stripe_offset = v_lba % stripe_size;
    stripe_group = stripe_no / nparts;
    vp_indx = stripe_no % nparts;
    v_lba =((stripe_group* stripe_size)+stripe_offset);
    printf("stripe_no=%d 0x%x\n", stripe_no, stripe_no);
    printf("stripe_offset=%d 0x%x\n", stripe_offset, stripe_offset);
    printf("stripe_group=%d 0x%x\n", stripe_group, stripe_group);
    printf("vp_indx=%d 0x%x\n", vp_indx, vp_indx);
    printf("phys_lba=%d 0x%x\n", v_lba, v_lba);

    /***
    enter v_lba=90
    enter stripe_size=16
    enter nparts=4
    
    Output:
    stripe_no=5 0x5
    stripe_offset=10 0xa
    stripe_group=1 0x1
    vp_indx=1 0x1
    phys_lba=26 0x1a
    ***/
}


/*
** Helper routine to free the physical requests. It returns the last error
** if there is any stored in the prq_struct
** RSIII might want to do some sort of precedence-of-severity stuff here later.
*/
static int
free_prqs( mirror_flag)
	int mirror_flag;
{
	int retval;
	FSP_TRANSCTL_T	*tctl;	
	FSP_PHYSRQ_T 	*prq_p, *nxt_prqp;

	retval = 0;
	tctl = &u.u_tctl;
	prq_p = tctl->tc_physrqsts;

	/*
	** Traverse the tctl->physrq_link and free all the phys_req
	** mallocs, that could have been alloced.
	*/
	while (prq_p) {
		if (prq_p->pr_errno) {
			retval = prq_p->pr_errno;
			log(LOG_ERR,
			"WARNING!! VP SCSI error 0x%x for vp=0x%x clvp=0x%x\n",
			prq_p->pr_errno, prq_p->pr_vpdev, prq_p->pr_dev );
			if (mirror_flag) warn_vp( prq_p->pr_vpdev);
		}
		nxt_prqp = prq_p->pr_link;
		k_free((char*)prq_p);
		prq_p = nxt_prqp;
	}
	tctl->tc_physrqsts = NULL;
	return( retval);
}


/*
** Helper routine for sending a warning for a failed/dirty mirror vp member
*/
static void
warn_vp( cld_vpdev)
	fsp_dev_t	cld_vpdev;
{
	VPART		*cld_vpart, *cld_vpart_nv;
	int tmp;

	log(LOG_ERR, "WARNING!!! vp_strategy: vp disk dev 0x%x DAMAGED\n",
			cld_vpdev);

	tmp = FSP_DEV_TO_VPNUM(cld_vpdev);
	if ((tmp <0) || (tmp >= SP_MAX_VPARTS))
		goto done;

	cld_vpart = dev_to_vpart( cld_vpdev);
	cld_vpart_nv = dev_to_vpart_nv( cld_vpdev);
	if ((cld_vpart == NULL) || (cld_vpart->vp_type == VD_NONE))
		goto done;

	cld_vpart->status = DAMAGED;
	cld_vpart_nv->status = DAMAGED;
	/* no need for fresh checksum */

done:
	return;
}



#endif /*  VP_STRATEGY */

RAID6 RAID_6  Galois field algebra (pronounced as Galwar )


#ifdef  RAID_STRATEGY

#define WAXOR_GET_MRR_PAR(addr)	((addr) ^ 0x08000000)	/* toggle bit 27 */
#define WAXOR_DUP_WRITE(addr)	((addr) | 0x10000000)	/* set hi bit 28 */
#define SET_XOR_BIT(addr)       ((addr) | 0x20000000)	/* set hi bit 29 */
#define RESET_XOR_BIT(addr)	((addr) & (~(0x20000000))) /* reset bit 29 */
#define WAXOR_PRIMARY		0x40000000		/*chipsel bit 30 */
#define WAXOR_SECONDARY		0x80000000		/*chipsel bit 31 */

/*
 * RAID Array Control structure.
 * This structure contains the information that describes an active
 * RAID array where as RAID_T contains RAID array information that
 * is either received from/sent to host.
 *
 * A three member RAID-5 disk array looks as follows:
 *
 *                  disk1        disk2         disk3
 *             +=============+=============+=============+
 *             |   PARITY    | data block1 | data block2 | stripegroup0
 *             +-------------+-------------+-------------+
 *             | data block3 |   PARITY    | data block4 | stripegroup1
 *             +-------------+-------------+-------------+
 *             | data block5 | data block6 |   PARITY    | stripegroup2
 *             +=============+=============+=============+
 *             |   PARITY    | data block7 | data block8 | stripegroup3
 *             +-------------+-------------+-------------+
 *             | data block9 |   PARITY    | data block10| stripegroup4
 *             +-------------+-------------+-------------+
 *             | data block11| data block12|   PARITY    | stripegroup5
 *             +=============+==============+============+
 *             |             |             |             |
 *             ~             ~             ~             ~
 *             ~             ~             ~             ~
 *
 * stripe size = one data block length on one member
 * stripe group = data block1 length + data block2 length
 *
 * see the macro MAP_RQ for more details.
 */

/*
 * Map request to physical location, and compute stripe group hash key.
 */
#define MAP_RQ(rq)							\
{      									\
        RAID_ARRAY_CNTL *raid_cntl_;					\
        u_int blockno_;							\
        u_int devcnt_;							\
        u_int stripe_serialnum;						\
        u_int stripe_group_no;						\
        u_int offset_within_stripe;					\
									\
									\
        raid_cntl_ = (rq)->raid_cntl;					\
        blockno_ = (rq)->start_lba;					\
        devcnt_ = raid_cntl_->device_cnt;				\
									\
   /*   stripe_serialnum = blockno_  /  raid_cntl_->stripe_size; */	\
        stripe_serialnum = (blockno_ >> raid_cntl_->stripe_shift);	\
									\
        stripe_group_no  = stripe_serialnum / ( devcnt_ - 1);		\
									\
   /*   offset_within_stripe = blockno_ &(raid_cntl_->stripe_size-1)*/	\
        offset_within_stripe = blockno_  % raid_cntl_->stripe_size;	\
									\
									\
        (rq)->stripeno = stripe_group_no;				\
        (rq)->data_relno = stripe_serialnum % (devcnt_ - 1);		\
        (rq)->par_relno = stripe_group_no % raid_cntl_->device_cnt;	\
        (rq)->start_physblk = ((stripe_group_no*(raid_cntl_->stripe_size)) + \
					 offset_within_stripe);		\
   /*   (rq)->start_physblk = ((rq)->stripeno << raid_cntl_->stripe_shift)*/ \
   /*			+ (blockno_ & (raid_cntl_->stripe_size -1));*/	\
									\
									\
        if (  (rq)->data_relno >= (rq)->par_relno  )			\
					(rq)->data_relno++;		\
									\
        (rq)->data_dev   = raid_cntl_->device[(rq)->data_relno];	\
        (rq)->parity_dev = raid_cntl_->device[(rq)->par_relno];		\
									\
        /* set hash_key for stripe group hash lookups */		\
        (rq)->hash_key = (rq)->start_physblk >> raid_cntl_->sg_shift;	\
									\
        /* After hashing is done; offset SKIP_LABEL_BLK 8k 16blks */	\
        (rq)->start_physblk += DISKOFF;					\
									\
        (rq)->end_physblk = (rq)->start_physblk + (rq)->block_cnt;	\
}


crash recovery OBJECTIVE:

RAID software uses write cache (WC or NVRAM) for its I/O. When there is
a system crash due to power failure or any other reason it leaves
some data in WC. Upon reboot, the left-over data in NVRAM
from the previous session needs to be written to RAID array(s).

Who starts RAID WC recovery?

During boot time, ax_write_cache command tries to enable
WC. If WC is in already initialized state
then WC recovery for non-raid data is attempted followed
by WC recovery for raid data is attempted.
During WC checking process_nv_bufs() will link all WC 
pages of raid data in the list raid_data_buf which will used
by raid_wc_recover().

Dependency on Write Cache (NVRAM):

The WAXOR contains battery backed low powered DRAM memory modules. The
maximum addressable amount of non-volatile write buffer in the system
is 256 Mbytes since the upper 2 bits (28 and 29) of the address field
are used for various XOR modes.

In a non-RAID operation, the entire WC memory space can be
used for staging write data. For RAID operations, the write buffer is
configured as two separate but logically paired buffers. One of the
logically paired buffers is used to store new data (data buffer) while
the other is used for storing the XORed data (XOR buffer). Each buffer
can be accessed via a separate address space.

In the XOR-write example given below, the 256MB gets divided to logically
paired 128MB of buffers. The addresses 6000 0000 - 6FFF FFFF are via the
primary PCI bus. The same buffer could be accessed at A000 0000 - AFFF FFFF
via the secondary PCI bus.

60000000 +---------+ +---------+ 68000000
         |         | |         |
 |       | Data    | | XOR     |
128MB    | Buffer  | | Buffer  |
 |       |         | |         |
         |         | |         |
         |         | |         |
67FFFFFF +---------+ +---------+ 6FFFFFFF

The description below shows the address bits and various XOR modes for
accesses through the primary and secondary PCI bus.

31   30      29      28    27    -     0
^    ^       ^       ^     ^           ^
|    |       |       |     |           |
|    |       |       |     |<- 256MB ->|
|    |       |       |
|    |       0   -   0 - Transparent read/write
|    |       0   -   1 - Mirror Write
|    |       1   -   0 - XOR
|    |
|    0 - Secondary PCI
|    1 - Primary PCI
|
0 - Primary
1 - Secondary PCI

Of interest is the mode 'XOR': a write to the data buffer with bits
29/28 set to 1/0 generates a read-modify-write. The data in the XOR
buffer is XORed with the data being written and the result is written
back to the XOR buffer.

The PLX 9080 DMA engine is used for memory-to-memory data transfers between
the write buffer and the CPU memory. Local DMA within the WAXOR is not
supported. The 9080 can not be used over SCI because it does not support
64 bit addresses.

NVBUF is a WC page (buffer) descriptor maintained in NVRAM
itself. It is a static structure that will not get lost in case of power
failure.

NVBUF2 is a kind of NVBUF but maintained in main memory.
NVBUF2 points to NVBUF.

NVRAM size will be waxor_mem/2. The other half (secondary area)
of NVRAM holds the shadow (mirror image) of it. Secondary
 regions like 'DMA descriptors', NVCNTL and NVBUF are not used.

                      ------------------- 0000
		      | DMA descriptors |
		      |      4K         |
                      -------------------
		      |   WC Page 8K    |
		      |   WC Page 8K    |
		      |      ...        |
		      |   WC Page 8K    |
		      |                 |           
                      -------------------  DATA
		      |   WC Page 512   |
		      |   WC Page 512   |
		      |      ...        |
		      |   WC Page 512   |
		      |                 |           
                      -------------------
            	      |   NVBUF         |
		      |   NVBUF         |  DATA WC Page descriptors
                      |    ...          |  
		      |   NVBUF         |
                      -------------------
		      |   NVCNTL        |
                      ------------------- waxor_mem/2


The following are the different states a NVBUF would go through:

NV_VALID

	WC buffer contains non-raid data.

NV_RAID_DATA

	WC buffer contains valid raid data that needs to written
	to data disk.

NV_RAID_PARITY

	Parity update in WC secondary buffer has completed successfully.
	It needs to be written to parity disk.


How WC is invloded with RAID I/O in terms of data structures?

A WC page is allocated using alloc_nvbuf() and its shadow
(mirror image)  is automatically accessible. When data is DMAed
from SCI to WC page, it will be copied to the shadow page also.
After the data is successfully transfered NVBUF state would
be NV_RAID_DATA in primary as well as secondary areas.

Now, new parity for this data will be generated by WAXOR when
old data (ROD) and old parity (ROP) are read as one
atomic operation.  This ROD+ROP with new data (ND) already
residing in secondary area will result in new parity (NP).
Once new parity is calculated successfully, NVBUF state of
the secondary buffer or parity buffer will be set to
NV_VALID_PARITY.

New data and new parity are chained together in PRQs sent
in one attempt to spp_strategy() to update on RAID array.

RAID WC recovery:
================

The list of data buffers initialized in wb_manager.c and pointed
to by raid_data_buf. The following are the cases where the system
could crash and leave data and parity in WC buffers.

1. DMA from SCI to WC completed

	Read old parity and read old data update the new parity
	with new data residing in secondary WC data buffer.

	Mark secondary NVBUF state as NV_RAID_PARITY.

	Goto 'Parity updated'

2. Parity updated

	Write new parity and new data to raid array.

	Free NVBUFs.

3. Parity and Data are written to array but WC buffers are not relased.

	Goto 'Parity updated'

4. Data & Parity are valid and array is in degraded mode because
   of I/O ahead of the current request.

   4a. Data drive is down
   4b. Parity drive is down

#endif  /*  RAID_STRATEGY */


r0(int BlkNum)
{

int BlksInStripe = 16;
int cvd_numuseddevices = 6;
int BlksInStripeGrp, StripeGOff, StripeGroup, dDNo, pDNo, phys;


BlksInStripeGrp = BlksInStripe * cvd_numuseddevices;
StripeGOff = BlkNum % BlksInStripeGrp;
StripeGroup = BlkNum / BlksInStripeGrp;

dDNo = StripeGOff / BlksInStripe;
//for right-slant parity
pDNo = StripeGroup % cvd_numuseddevices;

// left-slant: pDNo = StripeGroup % cvd_numuseddevices; then pDNo = numdev-pDNo
phys = (StripeGroup * BlksInStripe) + (StripeGOff % BlksInStripe);


printf("dDNo = %02d  pDNo = %02d  phys = %02d\n", dDNo, pDNo, phys);

if (dDNo >= pDNo) {
    /* Increment Data Drive Number. */
    dDNo++;
    //printf("newD = %02d  pDNo = %02d  phys = %02d\n", dDNo, pDNo, phys);
}

}


old_r50(int BlkNum)
{

int BlksInStripe = 16;
int cvd_numuseddevices = 9;
int naxle = 3;
int BlksInStripeGrp, StripeGOff, StripeGroup, dDNo, pDNo, phys;
int BlksInStripeGrp_peraxle;
int ano, pd_peraxle, stripe_off, stripe_srno;

BlksInStripeGrp = BlksInStripe * (cvd_numuseddevices - naxle);
BlksInStripeGrp_peraxle = BlksInStripeGrp / naxle ;
StripeGOff = BlkNum % BlksInStripeGrp;   // 100%64  = 36
StripeGroup = BlkNum / BlksInStripeGrp;   // 100/64  = 1
ano = StripeGOff / BlksInStripeGrp_peraxle;

pd_peraxle = cvd_numuseddevices / naxle; // TBD wrong for unbalanced
pDNo = StripeGroup % pd_peraxle ;

stripe_srno = StripeGOff / BlksInStripe ;
stripe_off  = StripeGOff % BlksInStripe ;
dDNo = stripe_srno % ( pd_peraxle - 1);

phys = (StripeGroup * BlksInStripe) + stripe_off;


printf("dDNo = %02d  pDNo = %02d  phys = %02d axle = %02d\n", dDNo,
							pDNo, phys, ano);

if (dDNo >= pDNo) {
    /* Increment Data Drive Number. */
    dDNo++;
    printf("NewD = %02d  pDNo = %02d  phys = %02d axle = %02d\n", dDNo,
							pDNo, phys, ano);
}

}


#define MAX_AXLES 16
typedef struct _logical {
	int BlksInStripe;
	int cvd_numuseddevices;
	int naxle;
	char cvd_num_drives_in_axle[MAX_AXLES]; 
	int cvd_numblksinstripegroupaxle[MAX_AXLES];
} cvd_t;
cvd_t cvd0;

#define GETVOLUMESTRIPEGRPAXSIZEINBLKS(VolSeqNum, axle) \
        (cvd0.cvd_numblksinstripegroupaxle[axle])
#define SETVOLUMESTRIPEGRPAXSIZEINBLKS(VolSeqNum, axle, Value) \
        cvd0.cvd_numblksinstripegroupaxle[axle] = Value

r50(int BlkNum)
{
	cvd_t *cvd;

	int i, j, num_str_in_grp, BlksInStripe, BlksInStripeAxle;
	int cvd_numuseddevices ;
	int naxle ;
	int BlksInStripeGrp, StripeGOff, StripeGroup, dDNo, pDNo, phys;
	int ano, stripe_off, stripe_srno;
	int StartBlkInSGrp;


	cvd = &cvd0;
	cvd->BlksInStripe = 16;

	/* balanced drives with 2 axles
	cvd->cvd_numuseddevices = 6;
	cvd->naxle = 2;
	cvd->cvd_num_drives_in_axle[0] = 3;
	cvd->cvd_num_drives_in_axle[1] = 3;
	*/

	/* balanced drives with 3 axles 
	cvd->cvd_numuseddevices = 9;
	cvd->naxle = 3;
	cvd->cvd_num_drives_in_axle[0] = 3;
	cvd->cvd_num_drives_in_axle[1] = 3;
	cvd->cvd_num_drives_in_axle[2] = 3;
	*/

	/* UNbalanced drives with 2 axles 
	cvd->cvd_numuseddevices = 7;
	cvd->naxle = 2;
	cvd->cvd_num_drives_in_axle[0] = 3;
	cvd->cvd_num_drives_in_axle[1] = 4;
	*/

	/* UNbalanced drives with 3 axles */
	cvd->cvd_numuseddevices = 11;
	cvd->naxle = 3;
	cvd->cvd_num_drives_in_axle[0] = 3;
	cvd->cvd_num_drives_in_axle[1] = 4;
	cvd->cvd_num_drives_in_axle[2] = 4;


	for (i=0; i<cvd->naxle; i++) {
		SETVOLUMESTRIPEGRPAXSIZEINBLKS(0, i, (cvd->BlksInStripe *
			(cvd->cvd_num_drives_in_axle[i]-1)));
	}

	BlksInStripe = cvd->BlksInStripe;
	cvd_numuseddevices = cvd->cvd_numuseddevices;
	naxle = cvd->naxle;

	BlksInStripeGrp = BlksInStripe * (cvd_numuseddevices - naxle);
	StripeGOff = BlkNum % BlksInStripeGrp;   

	// NOw lookup the axle number from the StripeGOff
	i=0; j=StripeGOff;
	BlksInStripeAxle = GETVOLUMESTRIPEGRPAXSIZEINBLKS(0, i);
	while (j > (BlksInStripeAxle-1) ) {
		j -= BlksInStripeAxle;
		i++;
		if (i>=naxle)
			printf("SHOULD not happen, no axle lookup found\n");
		BlksInStripeAxle = GETVOLUMESTRIPEGRPAXSIZEINBLKS(0, i);
	}
	ano = i;

	// calc parity_num
	stripe_srno = BlkNum / BlksInStripe ;
	num_str_in_grp = cvd_numuseddevices - naxle ;
	StripeGroup = stripe_srno / num_str_in_grp ;
	pDNo = StripeGroup % cvd->cvd_num_drives_in_axle[ano] ;

	// calc phys_lba
	stripe_off  = StripeGOff % BlksInStripe ;
	phys = (StripeGroup * BlksInStripe) + stripe_off;

	// calc data_dr_num
	dDNo = (StripeGOff / BlksInStripe) + ano;
	if (ano) {
		int rm_dr_offset = 0;
		for ( i=0; i<ano; i++) {
			rm_dr_offset += cvd->cvd_num_drives_in_axle[i];
		}
		dDNo -= rm_dr_offset;
	}


	printf("dDNo = %02d  pDNo = %02d  phys = %02d axle = %02d\n", dDNo,
							pDNo, phys, ano);

	if (dDNo >= pDNo) {
    		/* Increment Data Drive Number. */
    		dDNo++;
    		printf("NewD = %02d  pDNo = %02d  phys = %02d axle = %02d\n",
							dDNo, pDNo, phys, ano);
	}

   StartBlkInSGrp = ((BlkNum / BlksInStripeGrp) * BlksInStripeGrp);
	printf("GlbStart=%d 0x%x\n", StartBlkInSGrp, StartBlkInSGrp);
   for (i=0; i<ano; i++)
   {
       StartBlkInSGrp += (GETVOLUMESTRIPEGRPAXSIZEINBLKS(0, i));
   }
	printf("NewStart=%d 0x%x\n", StartBlkInSGrp, StartBlkInSGrp);


}






main()
{
	int BlkNum;
	printf("BlkNum = "); scanf("%d", &BlkNum );
/*
	r0(BlkNum);
	printf("-------------------R50--------------------\n");
*/
	r50(BlkNum);
	printf("------------------------------------------\n");
}

-----------------------------------------------------

PC LAPTOP

c: on /cygdrive/c
l: on /cygdrive/l
m: on /cygdrive/m
n: on /cygdrive/n
o: on /cygdrive/o
p: on /cygdrive/p
q: on /cygdrive/q
r: on /cygdrive/r
s: on /cygdrive/s
t: on /cygdrive/t

THEN  Map drive
 /nonamej/applications -> /cygdrive/l
 /nonamej/functional_groups -> /cygdrive/m
 /nonamej/NETLOGON -> /cygdrive/n
 /nonamej/projects -> /cygdrive/o
 /nonamej/share -> /cygdrive/p
 /nonamej/sysvol -> /cygdrive/q
 /nonamej/user_folders -> /cygdrive/r
 /nonamej/vphome -> /cygdrive/s
 /nonamej/vplogon -> /cygdrive/t


LINUX:
mount -t smbfs -o username=ravii "//nonamej/Applications" /nonamej/applications
mount -t smbfs -o username=ravii "//nonamej/Functional Groups" /nonamej/functional_groups
mount -t smbfs -o username=ravii "//nonamej/NETLOGON" /nonamej/NETLOGON
mount -t smbfs -o username=ravii "//nonamej/Projects" /nonamej/projects
mount -t smbfs -o username=ravii "//nonamej/Share" /nonamej/share
mount -t smbfs -o username=ravii "//nonamej/SYSVOL"  /nonamej/sysvol
mount -t smbfs -o username=ravii "//nonamej/User Folders" /nonamej/user_folders
mount -t smbfs -o username=ravii "//nonamej/VPHOME"  /nonamej/vphome
mount -t smbfs -o username=ravii "//nonamej/VPLOGON" /nonamej/vplogon


-----------------------------------------------------

$ echo $CVSROOT
:pserver:ravii@192.168.1.57:/advstgdsk/cvsrepos

$ cvs login
give the password.


CLONE THE ENTIRE TREE
---------------------
$ cvs co IslaVista   ( or     cvs co -r phase0_xscale IslaVista)

$ cvs edit  my_file.c

$ vi my_file.c   ( make changes  and compile.. just type make)

$ cvs commit my_file.c


To UPDATE the tree
-------------------
$ cvs update


CSCOPE:
----------
cd ~/work/src/IslaVista/firmware
find . -name "*.[ch]" -print >> cscope.files
find . -name "*.asm" -print >> cscope.files
ctags -L cscope.files
cscope


MAKE / BUILD
--------------
cd ~/work/src/IslaVista/firmware
make > my_output 2>&1  &
tail -f my_output


LOAD DRIVER
--------------
insmod raid_core.o   OR
insmod raid_core.o MemStart=0x8000000 MemSize=128
insmod Marvell.o
mknod /dev/islavista  c  127  0


MSFT INITIATOR Login:
-----------------------
iscsicli AddTargetPortal 10.0.0.234 3260
iscsicli LoginTarget iqn.2000-04.com.qlogic.qla4010.ts20315a00094 T * * * * * * * * * * * * * * * 0
iscsicli sessionlist
iscsicli LogoutTarget sessionID
iscsicli RemoveTargetPortal 10.0.0.234 3260
iscsicli ListTargetPortals


UNLOAD DRIVER
--------------
killall i2
rmmod Marvell
rmmod raid_core


GENERAL GDB on cygwin
---------------------
gcc -g -o test test.c
Invoke gdb with no args: just simply, gdb
at the gdb prompt type "file test.exe"
(gdb) file test.exe



linux environ
-----------
Removed the NOFILLLD in raid_core/mdd/mddftend.c 
In Makefile add -DRAID50_51DEBUG and also in raid_core/main/main.c define it.
In raid_core/mdd/mddbkend.c  Do_Not_Install_MDD
In the makefile commented -DQLOGIC_TARGET_DRIVER to run iotest.
In iscsi/qlogic/qla4xxx/Makefile  modify Makefile and define -DFLASHLESS_. and
-DDHCP_ENABLE

to generate .i expand macro goto linux machine
create a new fiel /tmp/new
set -x
gcc -c -E -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -D__KERNEL__
-DMODULE -DRLINUX -DQLOGIC_TARGET_DRIVER -DPRO_ARCH_X86 -DMODVERSIONS -DEXPORT_SYMTAB -include /usr/src/linux/include/linux/modversions.h -DRAID50_51DEBUG -I/work/ravii/07282003_jul28/IslaVista/firmware/raid_core/include -I/work/ravii/07282003_jul28/IslaVista/firmware/common/include -I/usr/src/linux/include rwprocess.c
> ./MY_RWPROCESS.i

disable CRON:
-------------
mv /usr/sbin/crond /usr/sbin/crond.ORIG

Make linux Kernel:
------------------
make menuconfig
make dep
make clean
make bzImage
make modules
make modules_install
cp /usr/src/linux/arch/i386/boot/bzImage /boot
cp /usr/src/linux/System.map /boot
cp /usr/src/linux/include/linux/kernel.h /boot
vi /etc/lilo.conf
lilo

Mount a CD: mount -t iso9660  /dev/hdc  /mnt/cdrom
Mount DOS floppy: mount -t msdos /dev/fd0 /mnt

Linux- MAN DOC:
functional_group/3rdParty/OSVendor/Linux/Kernel/LinuxDeviceDriver2ndEd/ *.pdf

LINUX KERNEL linux kernel
spinlock_t    pfm_drv_spinlock;
    spin_lock_init(&pfm_drv_spinlock);
    spin_lock_irqsave(&pfm_drv_spinlock, flags);
    spin_unlock_irqrestore(&pfm_drv_spinlock, flags);

struct semaphore pfm_drv_sem;  same as DECLARE_MUTEX(pfm_drv_sem);
    down_interruptible(&pfm_drv_sem)   after wakeup must check for INTR wakeup
    up(&pfm_drv_sem)

wait_event_interruptible
wake_up_interruptible(&idehs_info->wait_q);

int register_chrdev(unsigned int major, const char *name);
int unregister_chrdev(unsigned int major, const char *name);
file_operations 

int register_blkdev(unsigned int major, const char *name);
int unregister_blkdev(unsigned int major, const char *name);
struct block_device_operations

probe_irq_on()
probe_irq_off(  mask /* returned from probe_irq_on*/ )

request_irq( IRQ_NUM, irq_func, FLAG, dev_instance);
free_irq(CARD_STATUS_IRQ, idehs_dev_instance_t );


for finding IRQ: probe_irq
    unsigned long mask = probe_irq_on(  );

    outb_p(0x10,short_base+2); /* enable reporting */
    outb_p(0x00,short_base);   /* clear the bit */
    outb_p(0xFF,short_base);   /* set the bit: interrupt! */
    outb_p(0x00,short_base+2); /* disable reporting */
    udelay(5);  /* give it some time */

    your_irq = probe_irq_off(mask);


result = request_irq( 31 /*IRQ31*/,
             idehs_card_isr,
             SA_INTERRUPT | SA_SHIRQ, // SA_INTERRUPT disables other intrs
             "idehs_card_event",
             idehs_dev_instance_t);
free_irq(CARD_STATUS_IRQ, idehs_dev_instance_t );

idehs_card_isr (int irq, void *dev_id, struct pt_regs *reg)
{
    /*  Mask interrupts if required */

    /* Read Interrupt Status Register */
    /* We may use different call if memory mapped */
    reg_status = inb(REG_BASE_ADD + CARD_STATUS_OFFSET);

    /* Schedule the bottom half to run */
    tasklet_schedule(&idehs_swap_event_tasklet);
    return IRQ_HANDLED;
}
DECLARE_TASKLET(idehs_swap_event_tasklet, idehs_swap_event_fn,
    (unsigned long) &reg_status);
static void idehs_swap_event_fn (unsigned long unused)
{
    spin_lock(&idehs_info->lock);
    *ptr = (int) *reg_status & INT_DATA_MASK;
    spin_unlock(&idehs_info->lock);
    wake_up_interruptible(&idehs_info->wait_q);
}


========================================
#define NUM_PHILOSOPHERS 5    //SEMAPHORE
semaphore_t chopstick_semap [NUM_PHILOSOPHERS];

void init(){
    for (i=0; i< NUM_PHILOSOPHERS; i++) {
        chopstick[i].value = 1;
    }
}
bad_design_dining( int person_number) 
{
    int rightchopst, leftchopst;

    while (1) {

        think_for_ramdomtime();

        rightchopst = person_number;
        leftchopst = person_number + (NUM_PHILOSOPHERS-1)  % NUM_PHILOSOPHERS;

        down( chopstick_semap[ rightchopst ]);
        down( chopstick_semap[ leftchopst ]);

        eat();

        up( chopstick_semap[ rightchopst ]);
        up( chopstick_semap[ leftchopst ]);

    }
}

better_design_dining()
{
    int rightchopst, leftchopst;

    while (1) {

        think_for_ramdomtime();

        rightchopst = person_number;
        leftchopst = person_number + (NUM_PHILOSOPHERS-1)  % NUM_PHILOSOPHERS;

        if ( some_condition do radical; else do normal )
        if ( rightchopst < leftchopst ) {
            down( chopstick_semap[ leftchopst ]);
            down( chopstick_semap[ rightchopst ]);
        } else {
            down( chopstick_semap[ rightchopst ]);
            down( chopstick_semap[ leftchopst ]);
        }

        eat();

        up( chopstick_semap[ rightchopst ]);
        up( chopstick_semap[ leftchopst ]);

    }
}

deadlock occurs when
1. Need exclusive access to certain resource
2. Need more than 1 shared resource exclusively
3. No one givesup (no premption)
4. circular dependancy. I need your fork, but you need my fork
========================================




ADJUST and CRAMFS
-------------
Goto xsdev and give make
copy *.o to /work/xmount/targetX
mkcramfs <lsrc-directory> myflash.img
cp <lsrc-directory>/myflash.img /tftpboot/myflash.img
xscale_le-objdump --adjust-vma=0xC9828060 -S raid_core.o > my_map_file.map
[pc] - start_addr( c9864060 )
For example pc=c9883448 then do c9883448 - c9864060 = 1F3E8  look for 1F3E8 in
the map file

Debugging:
----------
echo 8 > /proc/sys/kernel/printk     to print on screen and var/log/messages
echo 0 > /proc/sys/kernel/printk     to disable print on screen 
ksyms | more  to see address of loded module

To debug crash we need:
1. oops stack crash dump
2. cat /proc/ksyms   OR OR OR ivdump  (to get load address c9864060, C9828060)
3. map file from compile-time OR OR OR raid_core.o

=======================

|000 nul|001 soh|002 stx|003 etx|004 eot|005 enq|006 ack|007 bel|
|010 bs |011 ht |012 nl |013 vt |014 np |015 cr |016 so |017 si |
|020 dle|021 dc1|022 dc2|023 dc3|024 dc4|025 nak|026 syn|027 etb|
|030 can|031 em |032 sub|033 esc|034 fs |035 gs |036 rs |037 us |
|040 sp |041  ! |042  " |043  # |044  $ |045  % |046  & |047  ' |
|050  ( |051  ) |052  * |053  + |054  , |055  - |056  . |057  / |
|060  0 |061  1 |062  2 |063  3 |064  4 |065  5 |066  6 |067  7 |
|070  8 |071  9 |072  : |073  ; |074  < |075  = |076  > |077  ? |
|100  @ |101  A |102  B |103  C |104  D |105  E |106  F |107  G |
|110  H |111  I |112  J |113  K |114  L |115  M |116  N |117  O |
|120  P |121  Q |122  R |123  S |124  T |125  U |126  V |127  W |
|130  X |131  Y |132  Z |133  [ |134  \ |135  ] |136  ^ |137  _ |
|140  ` |141  a |142  b |143  c |144  d |145  e |146  f |147  g |
|150  h |151  i |152  j |153  k |154  l |155  m |156  n |157  o |
|160  p |161  q |162  r |163  s |164  t |165  u |166  v |167  w |
|170  x |171  y |172  z |173  { |174  | |175  } |176  ~ |177 del|


| 00 nul| 01 soh| 02 stx| 03 etx| 04 eot| 05 enq| 06 ack| 07 bel|
| 08 bs | 09 ht | 0a nl | 0b vt | 0c np | 0d cr | 0e so | 0f si |
| 10 dle| 11 dc1| 12 dc2| 13 dc3| 14 dc4| 15 nak| 16 syn| 17 etb|
| 18 can| 19 em | 1a sub| 1b esc| 1c fs | 1d gs | 1e rs | 1f us |
| 20 sp | 21  ! | 22  " | 23  # | 24  $ | 25  % | 26  & | 27  ' |
| 28  ( | 29  ) | 2a  * | 2b  + | 2c  , | 2d  - | 2e  . | 2f  / |
| 30  0 | 31  1 | 32  2 | 33  3 | 34  4 | 35  5 | 36  6 | 37  7 |
| 38  8 | 39  9 | 3a  : | 3b  ; | 3c  < | 3d  = | 3e  > | 3f  ? |
| 40  @ | 41  A | 42  B | 43  C | 44  D | 45  E | 46  F | 47  G |
| 48  H | 49  I | 4a  J | 4b  K | 4c  L | 4d  M | 4e  N | 4f  O |
| 50  P | 51  Q | 52  R | 53  S | 54  T | 55  U | 56  V | 57  W |
| 58  X | 59  Y | 5a  Z | 5b  [ | 5c  \ | 5d  ] | 5e  ^ | 5f  _ |
| 60  ` | 61  a | 62  b | 63  c | 64  d | 65  e | 66  f | 67  g |
| 68  h | 69  i | 6a  j | 6b  k | 6c  l | 6d  m | 6e  n | 6f  o |
| 70  p | 71  q | 72  r | 73  s | 74  t | 75  u | 76  v | 77  w |
| 78  x | 79  y | 7a  z | 7b  { | 7c  | | 7d  } | 7e  ~ | 7f del|

"
======================================


In vi To match #ifdef   [#  or ]#
in vi  to split   :split  and to toggle CTRLW-CTRLW
-------------------------------------------
indent INDENT cbeautify  CBEAUTIFY
indent file.c   and the options are in ~/.indent.pro
-------------------------------------------
show something | grep -A 5 -B 2 -i myGREPtextHERE
-------------------------------------------
awk AWK
kill -9 `ps -afe | grep MYTEXT | awk '{print $2}' `

-------------------------------------------
in vi to search blank lines
:%s/oldpatern/newpatern/g
:%g/oldpatern/newpatern/d
-------------------------------------------
alias scattach="screen -D -r "
alias scnew="screen -SR "
alias scnt="screen -t "
alias scls="screen -ls"
-------------------------------------------
gdb GDB thread debugging

set solib-search-path lib64/
set solib-absolute-prefix ./axnp_root_shadow

thread apply all bt  (to print all threads) but first give "set height 0"
info thread
then see what all threads are doing, and switch to any thread by its number
example "thread 3"

to semi-automate gdb:
gdb ./myexecutable -x myinput.txt
myinput.txt:  "run arg1 arg2 "

in code: just like PID, each thread has TID aka LWP which is pthread_self()
store it internally along with your thread handle.
pthread_t mythread;    retval = pthread_create( &mythread, NULL, myfunc, NULL)
in gdb, if there are thousands of threads, then how do you switch to your
thread example "thread 3" ...in gdb print mythread and also print "info thread"
and search for mythread in "info thread" and get the serial sequential number
NOT the LWP. use that serial/sequential number to "thread x"

-------------------------------------------

define tmp_raviii_tgts_one
    set $tgtn = $arg0
    printf "Target:%d = %p\n", $tgtn, Target::targets[$tgtn]
    p/x (*Target::targets[$tgtn])->currWWN
end

define raviii_tgts_all
    set $tgtn = 0
    while ($tgtn < 30)
        if Target::targets[$tgtn] != 0
            tmp_raviii_tgts_one $tgtn
        end
        set $tgtn = $tgtn + 1
    end
end


-------------------------------------------
RMD BOOTSTAMP COD 
COD MAU COD MAU SIZE cod mau cod mau size

One MAU is roughly 27M; 24MAU for COD; so roughly 27M * 24 = 640M per drive for COD;  RMD is 2M  (2000K, ie4000blks)
We use 24 MAUs for COD on HDD  and 12 MAUS for COD on SSD

So for HDD:
COD needs 24 MAUs per HDD. Each MAU has 420 stripes. Each stripe has 128 blocks. This gives us:
24_maus * 420_stripes * 128_blocks = 1290240_blocks ie. 645120K 640M )

Likewise if we consider SSD, then:
COD needs 12 MAUs per SSD. Each MAU has 420 stripes. Each stripe has 256 blocks. This gives us:
12_maus * 420_stripes * 256_blocks = 1290240_blocks

Irrespective of HDD/SSD, the physical real-estate space occupied by COD is the same for both SSD/HDD.
COD stretches from LBA 0 thru LBA 1290240 on each physical drive irrespective of SSD/HDD.

MAU C    128_blocks * 420_stripes =       53760_blocks (2blks is 1k, so  26880K, ie.  27M )
MAU 5S/6 128_blocks * 420_stripes * 10 = 537600_blocks (2blks is 1k, so 268800k, ie. 260M )
MAU 5ssd 128_blocks * 420_stripes * 6 =
MAU 10
MAU 10S


on each disk, First 640M is COD and last 2M is RMD

K M G
K 1,000
M 1,000,000
G 1,000,000,000
T 1,000,000,000,000

From each 1Tera disk, we use less than 1G (640M + 2M) for COD+RMD
From each 1/2Tera disk (500G), we use less than 1G (640M + 2M) for COD+RMD

-------------------------------------------
in gdb GDB  scripts: jesses   traversing RMD_Infos on all targets

define traverse_rmdci
	set $MAX_BRIX_TARGETS = 30
	set $tgtCnt = 0
	set $psFcTgt = Target::targets[0]
	while($tgtCnt != $MAX_BRIX_TARGETS)
		set $psFcTgt = Target::targets[$tgtCnt]
		if ($psFcTgt != 0)
			set $psCI = (RMD_Info *)$psFcTgt->ci_Done.psFirst
			while($psCI != &$psFcTgt->ci_Done)
				printf "target %u port %u psCI %p idrw %p\n", $tgtCnt, $psCI->portNum, $psCI, &$psCI->idrw
				set $psCI = (RMD_Info *) $psCI->psNext
			end
		end
		set $tgtCnt = $tgtCnt + 1
	end
end

-------------------------------------------
two code paths incrementing same variable, how to protect
  1. either semaphore  sem_init
  or
  2. mutex   pthread_mutex_init

signal:
    1. cond_wait - cond_signal  (pthread_cond_wait and signal)
    or
    2. sem_wait - sem_post

-------------------------------------------
example of pthread_cont_wait/signal
EXAMPLE OF PTHREAD_CONT_WAIT/SIGNAL

in common/main code
{

    /* define variables*/
    pthread_mutex_t myLockVar;
    pthread_cond_t  myCondVar;

    /* initialize */
    pthread_mutex_init(&myLockVar, NULL);
    pthread_cond_init(&myCondVar, NULL);

    /* fork thread */
    pthread_create(&childThreadHandle, NULL, childThreadFunc, NULL);

    /* now just wait for child thread to wake us */
    pthread_cond_wait(&myCondVar, &myLockVar);
    .....
}
childThreadFunc()
{
    do work, at end, signal waiting parent
    pthread_cond_signal(&myCondVar);
}
-------------------------------------------
search for more semaphore  SEMAPHORE   at the top

#include <semaphore.h>
sem_t ConsoleSema;
Init()
{
    sem_init(&ConsoleSema, 0, 0);
}
Start()
{
        sem_wait(&ConsoleSema);
}
Done()
{
        sem_post(&ConsoleSema);
}
-------------------------------------------

How does user application enter kernel mode
    1. system call  (read, write, ioctl)
    2. hardware interrupt from disk/network
    3. Illegal pointer access.

Write Code to insert 1 element into right/left binary single link-list

-------------------------------------------

If you use vim, then here is how to integrate it (assuming your vim was compiled with the cscope option):
 
add the cscope database:
:cs add cscope.out
open a file
:cs find f <file-fragment> -- can abridge "find" to "f"
grep for text
:cs find t <string>
use the cscope.out as tag database:
:set cscopetag
get help
:cs help
 
Or, to automate, add that stuff to your .vimrc:
 
if has("cscope")
    " use both cscope and ctag for 'ctrl-]', ':ta', and 'vim -t'
    set cscopetag
    " check cscope for definition of a symbol before checking ctags
    set csto=0
    " add any cscope database in current directory
    if filereadable("cscope.out")
        cs add cscope.out 
endif
 
you can also map keys to grep for stuff under the cursor, or go from match to match:
 
  :map <F6> *:cs find t <C-R>=expand("<cword>")<CR><CR> -- grep text (and highlight)
  :map <F5> *:cs find s <C-R>=expand("<cword>")<CR><CR> -- grep c symbols (and highlight)
  :map <F1> :tnext<CR>    -- next match   
  :map <F2> :tprev<CR>   -- previous match
While we are at it, make sure you don't add tabs into source code:
  :set expandtab    -- don't add tabs to source code!!!
  :set scrolloff=5  -- start scrolling 5 lines before bottom/top
 
To create your own cscope database (more restricted -> less hits, faster; add non-c file types...)
find . \( -path './third-party' -prune -o \
          -path './build' -prune \
       \) -o \
       \( -name "*.[ch]" -o -name "*.cc" -o -name "*.cmd" -o \
          -name "*.cmds" -o -name "*.xml" -o -name "*.mk" \
       \) -print > fl
find ./build/defs -name "*.mk" -print >> fl
find ./build/config.files -name "*" -print >> fl
echo "routing-sw/infra/clis/component_list.cfg" >> fl
echo "routing-sw/infra/clis/modes.defs" >> fl
echo "include/isan/mts_opc.def" >> fl
echo "feature/vsh/demo/cbe/cbe_README.txt" >> fl
cscope -b -i fl -q




vimdiff
or
vim -d 


and
/bin/merge


to match #ifdef   [#  or ]#


to open two files  :split
to switch between two split files    CTRLW-CTRLW


In vi To match #ifdef   [#  or ]#
in vi  to split   :split  and to toggle CTRLW-CTRLW
-------------------------------------------
indent INDENT cbeautify  CBEAUTIFY
indent file.c   and the options are in ~/.indent.pro
-------------------------------------------
date|cut -c 12-13
-------------------------------------------
show something | grep -A 5 -B 2 -i myGREPtextHERE
-------------------------------------------
awk AWK
kill -9 `ps -afe | grep MYTEXT | awk '{print $2}' `
-------------------------------------------
in vi to search blank lines
:%s/oldpatern/newpatern/g
:%g/oldpatern/newpatern/d
-------------------------------------------


