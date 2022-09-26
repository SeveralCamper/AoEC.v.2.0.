#!/bin/bash

g++ *.cpp -std=c++17 -o memory_test

for ((idx=1;idx<5;idx++)) do
    echo ./memory_test -m RAM -b 10Mb -l ${idx} 
    echo $(./memory_test -m RAM -b 10Mb -l ${idx} ) 
done