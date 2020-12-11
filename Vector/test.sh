#!/bin/bash

cd ressources

rm -rf output int.out string.out

mkdir output

declare -a mains=("int" "string" "other" "inception")

for m in "${mains[@]}"
do

clang++ -Werror -Wextra -Werror "$m"_main.cpp -o output/"$m"_ft
clang++ -Werror -Wextra -Werror -D STD "$m"_main.cpp -o output/"$m"_std

./output/"$m"_std > output/"$m"_std.log
./output/"$m"_ft > output/"$m"_ft.log

diff output/"$m"_std.log output/"$m"_ft.log > "$m".diff
if [ $(cat "$m".diff | wc -l) -eq 0 ]
then
	echo "$m" 'test passed!'
fi

done

