#!/bin/zsh

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
	#add other options if need
done

if [ "$CLEAN" != "clean" ]  && [ "$(cat path 2> /dev/null)" = "" ]
then
	echo -e "\e[1m\e[34m"'Please enter the path (absolute or relative) to you ft_container repository, with no / at the end por favor'
	read PATH_TO_REPO
	echo "$PATH_TO_REPO" > path
	cp "$PATH_TO_REPO"/**/*.hpp INCLUDES 2> /dev/null
	for file in INCLUDES/*.hpp
	do
		cp $file ${file:u} 2> /dev/null
	done
	echo "Enter your Include path if needed"
	read INCLUDE_PATH
	echo "$INCLUDE_PATH" > includes
else
	PATH_TO_REPO="$(cat path)"
	INCLUDE_PATH="$(cat includes)"
fi

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
	if [[ -d "$I" ]] && [[ -f INCLUDES/"$I".hpp ]]
	then
		cd "$I"
		../.container_tester.sh "$INCLUDE_PATH" "$CLEAN" 2> /dev/null
		cd ../
	fi
done

rm INCLUDES/* 2> /dev/null
