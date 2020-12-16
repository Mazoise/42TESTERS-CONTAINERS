#!/bin/bash

DIR=($(ls))
CLEAN=""
COUNT=$#

for ARG in "$@"
do
	if [ "$ARG" = "clean" ]
	then
		CLEAN="clean"
		COUNT=$((COUNT-1))
		break
	fi
done

for I in "${DIR[@]}" 
do
	if (( $COUNT > 0 ))
	then
		CHECK="no"
		for ARG in "$@"
		do
			if [ "$ARG" = "$I" ]
			then
				CHECK="yes"
				break
			fi
		done
		if [ "$CHECK" = "no" ]
		then
			continue
		fi
	fi
	if [[ -d "$I" ]] && [[ -f "$I"/test.sh ]]
	then
		cd "$I"
		./test.sh $CLEAN
		cd ../
	fi
done
