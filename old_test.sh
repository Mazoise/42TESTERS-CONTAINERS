#!/bin/bash

# VARIABLES

MAINS_DIR=mains
HPP_PATH=../

cd ressources

rm -rf output bin diff

RUN="yes"

for VAR in "$@"
do
	if [ "$VAR" = "clean" ]
	then
		RUN="no"
	fi
	#other arguments
done

if [ $RUN = "no" ]
then
	exit
fi

mkdir output
mkdir diff
mkdir bin

MAINS=($(ls $MAINS_DIR | cut -f1 -d'_'))

for M in "${MAINS[@]}"
do
	if [ "$M" != "empty" ]
	then
		clang++ -Werror -Wextra -Werror -I $HPP_PATH \
				$MAINS_DIR/"$M"_main.cpp -o bin/"$M"_ft
		clang++ -Werror -Wextra -Werror -D STD -I $HPP_PATH \
				$MAINS_DIR/"$M"_main.cpp -o bin/"$M"_std

		./bin/"$M"_std > output/"$M"_std.log
		./bin/"$M"_ft > output/"$M"_ft.log

		diff output/"$M"_std.log output/"$M"_ft.log > diff/"$M".diff
		if [ $(cat diff/"$M".diff | wc -l) -eq 0 ]
		then
			echo "$M" 'test passed!'
		fi
	fi

done

