#!/bin/bash

for f in ./*.cpp ;
do
    echo "$f":
    g++ -std=c++11 $f && ./a.out
    rm -f ./a.out
done
