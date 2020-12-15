#!/bin/bash

DIR=($(ls))

for I in "${DIR[@]}" 
do
	if [[ -d "$I" ]] && [[ -f "$I"/test.sh ]]
	then
		cd "$I"
		./test.sh $1 $2 $3
		cd ../
	fi
done
