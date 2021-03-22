#!/bin/zsh

DIR=($(ls))
CLEAN=""
COUNT=$#

mkdir -p .INCLUDES/EMPTY/JUST_IN_CASE 2> /dev/null

for ARG in "$@"
do
	if [ "$ARG" = "clean" ]
	then
		CLEAN="clean"
		COUNT=$((COUNT-1))
		break
	else
		CLEAN=""
	fi
	#add other options if need
done

if [ "$CLEAN" != "clean" ]
then
	if [ "$(cat .path 2> /dev/null)" = "" ]
	then
		echo -e "\033[1m\033[34m"'Please enter the path (absolute or relative) to you ft_container repository, with no / at the end por favor'
		read PATH_TO_REPO
		echo "$PATH_TO_REPO" > .path
		echo "Enter your Include path if needed"
		read INCLUDE_PATH
		echo "$INCLUDE_PATH" > .include_path
	else
		PATH_TO_REPO="$(cat .path 2> /dev/null)"
		INCLUDE_PATH="$(cat .include_path 2> /dev/null)"
	fi
	cp "$PATH_TO_REPO"/**/*.hpp .INCLUDES 2> /dev/null
	for file in .INCLUDES/*.hpp
	do
		NAME="${file%.*}"
		mkdir -p tmp/.INCLUDES 2> /dev/null
		cp $file tmp/${NAME:u}_UC.HPP 2> /dev/null
	done
	mv tmp/.INCLUDES/* .INCLUDES/
	rm -rf tmp
else
	rm .include_path .path 2> /dev/null
fi

for I in "${DIR[@]}" 
do
	if (( $COUNT > 0 ))
	then
		CHECK="no"
		for ARG in "$@"
		do
			ARG=${ARG:u}
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
	if [[ -d "$I" ]] && [[ -f .INCLUDES/"$I"_UC.HPP ]]
	then
		cd "$I"
		../.container_tester.sh "$INCLUDE_PATH" "$CLEAN" #2> /dev/null
		cd ../
	else if [[ "$CLEAN" = "clean" ]] && [[ -d "$1" ]]
		cd "$I" 2> /dev/null && ../.container_tester.sh 2> /dev/null " " clean && cd ../
	fi
done



if [ "$CLEAN" = "clean" ]
then
	rm .path .include_path 2> /dev/null
elif [[ "$OSTYPE" == "darwin"* ]]
then
	echo "Valgrind deprecated on MacOS, please check leaks yourself"
fi
rm -rf .INCLUDES 2> /dev/null
