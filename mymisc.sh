#!/bin/sh

abcd=0
echo $abcd
for i in `cat ./input.txt`
do
    echo $i
    abcd=`expr $abcd + $i`
    echo $abcd 
    read xxx
done


##    X=0
##    while [ $X -le 20 ]
##    do
##    echo $X
##    X=$((X+1))
##    done

