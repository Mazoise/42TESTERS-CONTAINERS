#!/bin/zsh

DIR=($(ls ))

for I in "${DIR[@]}"
do
    if [[ -d "$I" ]]
    then
        echo "$I"
        cd "$I"/mains/
        FILE=($(ls | grep .cpp))
        rm *_new.cpp
        for F in "${FILE[@]}"
        do
            echo "$F"
            sed "s/hbaudet_utils/test_utils/" "$F" > "$F"_new.cpp
            mv "$F"_new.cpp "$F"
        done
        cd ../..
    fi
done
