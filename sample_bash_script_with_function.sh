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
pwd
echo "^C   ^C    Are you in test0, 1 or 2 ?   ^C   ^C    "
read xxx
if [ $# != 0 ] ; then
   # invoke_gdb /home/mkirby/bin/debug_desktop.sh ../bin/raidfmtest $1 ../lib64/
   echo "No need to specify any arguments"
else
   invoke_gdb ../bin/raidfmtest ./raidfmtest.core ../lib64/
fi

