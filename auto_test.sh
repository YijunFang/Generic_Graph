#!/bin/bash

compiler="g++ -std=c++14 -Wall -Werror -O2 -o"

num=1

for file in test{1..19}.cpp
do
	filename=`basename $file`
	echo "testing test case $num and testing file is $filename------------------"
	
	target=`echo "$filename" | cut -d '.' -f1`

	test_file="result$num.txt"
	echo "test compiler-------------------------------------------------------"
	command_line="$compiler $target $filename"
	$command_line
	run="./$target"
	$run>res$num
	if diff -w "res$num" "$test_file"
	then
		echo "test case $num pass!!!!!"
	else
		echo "test case $num fail :("
	fi
	rm $target res$num
	num=`expr $num + 1`
done
