#!/bin/bash

# VARIABLES

MAINS_DIR=mains
HPP_PATH=../

cd ressources

rm -rf output bin diff

if [ $# -gt 0 ]
then
	if [ $1 = "clean" ]
	then
		exit
	fi
	#other arguments
fi

mkdir output
mkdir diff
mkdir bin

MAINS=($(ls $MAINS_DIR | cut -f1 -d'_'))

for m in "${MAINS[@]}"
do

clang++ -Werror -Wextra -Werror -I $HPP_PATH $MAINS_DIR/"$m"_main.cpp -o bin/"$m"_ft
clang++ -Werror -Wextra -Werror -D STD -I $HPP_PATH $MAINS_DIR/"$m"_main.cpp -o bin/"$m"_std

./bin/"$m"_std > output/"$m"_std.log
./bin/"$m"_ft > output/"$m"_ft.log

diff output/"$m"_std.log output/"$m"_ft.log > diff/"$m".diff
if [ $(cat diff/"$m".diff | wc -l) -eq 0 ]
then
	echo "$m" 'test passed!'
fi

done

