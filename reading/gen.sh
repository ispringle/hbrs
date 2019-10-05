#!/bin/bash

days=365
years=4

count=$(($days * $years))

for day in $( seq 1 $count )
do
	# ./hbrs $day >> 4yhbrs.properties
	reading=$(./hbrs $day)
	echo "$day=$reading"
done
