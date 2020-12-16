#!/bin/bash

# SETUP

TEST_DIR=ressources
BIN="$TEST_DIR"/bin
DIFF="$TEST_DIR"/diff
OUT="$TEST_DIR"/output
MAINS_DIR="$TEST_DIR"/mains
HPP_PATH=./
MAINS=($(ls $MAINS_DIR | cut -f1 -d'_'))
RUN="yes"
OK="\xE2\x9C\x85"
DEAD="\xE2\x98\xA0"
NOPE="\xE2\x9D\x8C"
WARNING="\xE2\x9A\xA0"
CONT="$(pwd | rev | cut -f1 -d'/' | rev)"

rm -rf "$OUT" "$BIN" "$DIFF"

# FUNCTIONS

run_tests ()
{
	touch .error.log .main_error.log
	if [ "$M" != "empty" ]
	then
		clang++ -Werror -Wextra -Werror -I $HPP_PATH \
				$MAINS_DIR/"$M"_main.cpp -o "$BIN"/"$M"_ft 2> .error.log
		clang++ -Werror -Wextra -Werror -D STD -I $HPP_PATH \
				$MAINS_DIR/"$M"_main.cpp -o "$BIN"/"$M"_std 2> .main_error.log

		if [ "$(cat .main_error.log | wc -c)" != "0" ]
		then
			echo -e "\e[31m\e[5m$WARNING""\t\e[0m\e[35m""$M""_main.cpp seems to be invalid!\e[0m"
		else
			if [ "$(cat .error.log | wc -c)" != "0" ]
			then
				echo -e "\e[1\e[31m\e[25m""$DEAD""\t""$M" "test does not compile!\e[0m"
			else
				./"$BIN"/"$M"_std > "$OUT"/"$M"_std.log 2> /dev/null
				./"$BIN"/"$M"_ft > "$OUT"/"$M"_ft.log 2> /dev/null
				diff "$OUT"/"$M"_std.log "$OUT"/"$M"_ft.log > "$DIFF"/"$M".diff
				if [ $(cat "$DIFF"/"$M".diff | wc -l) -eq 0 ]
				then
					echo -e "$OK""\e[1m\e[32m""\t""$M" 'test passed!'"\e[0m"
				else
					echo -e "\e[31m""$NOPE""\t""$M" "test outputs differ. Check logs\e[0m"
				fi
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

if [ $RUN = "no" ]
then
	exit
fi

# RUN

mkdir "$OUT"
mkdir "$DIFF"
mkdir "$BIN"

echo -e "\e[34m\e[1m-" $CONT ":\n\e[0m"
echo -e "\e[33mFound ${#MAINS[@]} tests in" "$CONT"/"$MAINS_DIR", running tests :"\n\e[0m"

for M in "${MAINS[@]}"
do
	run_tests $M 2> /dev/null
done
echo
