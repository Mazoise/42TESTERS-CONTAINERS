#!/bin/bash

# SETUP


INCLUDES=../.INCLUDES
MAINS=($(ls mains | cut -f1 -d'_'))
RUN="yes"
OK="\xE2\x9C\x85"
DEAD="\xE2\x98\xA0"
NOPE="\xE2\x9D\x8C"
WARNING="\xE2\x9A\xA0"
CONT="$(pwd | rev | cut -f1 -d'/' | rev)"

# FUNCTIONS

run_tests ()
{
	rm logs/"$1"_ft.error.log
	rm logs/"$1"_std.error.log
	clang++ -Werror -Wextra -Werror -std=c++98 -I . -I "$INCLUDES" -I "$INCLUDES"/EMPTY -I ../"$2" -I "$INCLUDES"/EMPTY/JUST_IN_CASE \
			mains/"$1"_main.cpp -o bin/"$1"_ft 2> logs/"$1"_ft.error.log
	clang++ -Werror -Wextra -Werror -std=c++98 -D STD -I . -I "$INCLUDES" -I "$INCLUDES"/EMPTY \
			-I "$INCLUDES"/EMPTY/JUST_IN_CASE -I ../"$2" mains/"$1"_main.cpp -o bin/"$1"_std 2> logs/"$1"_std.error.log

	if [ $(cat logs/"$1"_std.error.log | wc -c) != "0" ]
	then
		echo -e "\033[31m\033[5m$WARNING""\t\033[0m\033[35m\033[1m""$1""_main.cpp seems to be invalid!\033[0m"
	else
		if [ "$(cat logs/"$1"_ft.error.log | wc -c | rev | cut -f1 -d' ')" != "0" ]
		then
			echo -e "\033[1m\033[31m\033[25m""$NOPE""\t""$1" "test does not compile!\033[0m"
		else
			./bin/"$1"_std > out/"$1"_std.log 2> /dev/null
			./bin/"$1"_ft > out/"$1"_ft.log 2> /dev/null
			diff out/"$1"_std.log out/"$1"_ft.log > diff/"$1".diff
			if [ $(cat diff/"$1".diff | wc -l) -eq 0 ]
			then
				if [[ "$OSTYPE" == "linux-gnu"* ]]
				then
					valgrind ./bin/"$1"_ft > /dev/null 2> leak/"$1"_leak
					if [ "$(grep "All heap blocks were freed -- no leaks are possible" leak/"$1"_leak)" = "" ]
					then
						echo -e "\033[31m""$NOPE""\t""$1" "test seems to leak (shame!), or it crashed (shame shame!)"
					elif [ "$(grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" leak/"$1"_leak)" = "" ]
					then
						echo -e "\033[31m""$NOPE""\t""$1" ": Valgrind detected some errors"
					else
						echo -e "$OK""\033[1m\033[32m""\t""$1" 'test passed!'"\033[0m"
					fi
				else
					echo -e "$OK""\033[1m\033[32m""\t""$1" 'test passed!'"\033[0m"
				fi
			else
				echo -e "\033[31m""$NOPE""\t""$1" "test outputs differ. Check logs\033[0m"
			fi
		fi
	fi
}

# CHECK OPTIONS


for VAR in "$@"
do
	if [ "$VAR" = "clean" ]
	then
		RUN="no"
	fi
	#other arguments
done


# RUN

rm -rf out bin diff leak logs
if [ $RUN = "no" ]
then
	exit
fi

mkdir out
mkdir diff
mkdir bin
mkdir leak
mkdir logs

echo -e "\033[34m\033[1m-" $CONT ":\n\033[0m"
echo -en "\033[33mFound ${#MAINS[@]} tests for $CONT, "
if (( ${#MAINS[@]} > 0 ))
then
	echo -e running tests :"\n\033[0m"
else
	echo -e jumping to next container."\n\033[0m"
fi

for M in "${MAINS[@]}"
do
	run_tests $M $1 2> /dev/null
done
echo
