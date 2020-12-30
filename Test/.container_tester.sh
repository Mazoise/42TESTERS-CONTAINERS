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
	touch .error.log .main_error.log
	clang++ -Werror -Wextra -Werror -I "$INCLUDES" -I "$INCLUDES"/EMPTY -I ../"$2" -I "$INCLUDES"/EMPTY/JUST_IN_CASE \
			mains/"$1"_main.cpp -o bin/"$1"_ft 2> .error.log
	clang++ -Werror -Wextra -Werror -D STD -I "$INCLUDES" -I "$INCLUDES"/EMPTY \
			-I "$INCLUDES/EMPTY/JUST_IN_CASE" -I ../"$2" mains/"$1"_main.cpp -o bin/"$1"_std #2> .main_error.log

	if [ "$(cat .main_error.log | wc -c)" != "0" ]
	then
		echo -e "\e[31m\e[5m$WARNING""\t\e[0m\e[35m\e[1m""$1""_main.cpp seems to be invalid!\e[0m"
	else
		if [ "$(cat .error.log | wc -c)" != "0" ]
		then
			echo -e "\e[1m\e[31m\e[25m""$DEAD""\t""$1" "test does not compile!\e[0m"
		else
			./bin/"$1"_std > out/"$1"_std.log 2> /dev/null
			./bin/"$1"_ft > out/"$1"_ft.log 2> /dev/null
			diff out/"$1"_std.log out/"$1"_ft.log > diff/"$1".diff
			if [ $(cat diff/"$1".diff | wc -l) -eq 0 ]
			then
				valgrind ./bin/"$1"_ft > /dev/null 2> leak/"$1"_leak
				if [ "$(grep "All heap blocks were freed -- no leaks are possible" leak/"$1"_leak)" = "" ]
				then
					echo -e "\e[31m""$NOPE""\t""$1" "test seems to leak (shame!), or it crashed (shame shame!)"
				else
					if [ "$(grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" leak/"$1"_leak)" = "" ]
					then
						echo -e "\e[31m""$NOPE""\t""$1" "Valgrind detected some errors"
					else
						echo -e "$OK""\e[1m\e[32m""\t""$1" 'test passed!'"\e[0m"
					fi
				fi
			else
				echo -e "\e[31m""$NOPE""\t""$1" "test outputs differ. Check logs\e[0m"
			fi
		fi
	fi
	rm .error.log .main_error.log 2> /dev/null
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

rm -rf out bin diff leak
if [ $RUN = "no" ]
then
	exit
fi

mkdir out
mkdir diff
mkdir bin
mkdir leak

echo -e "\e[34m\e[1m-" $CONT ":\n\e[0m"
echo -en "\e[33mFound ${#MAINS[@]} tests for $CONT, "
if (( ${#MAINS[@]} > 0 ))
then
	echo -e running tests :"\n\e[0m"
else
	echo -e jumping to next container."\n\e[0m"
fi

for M in "${MAINS[@]}"
do
	run_tests $M $1 #2> /dev/null
done
echo
