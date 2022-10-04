#!/bin/bash

g++ MemSysPerformanceEval.cpp

./a.out –m RAM –b 8 Mb –l 10
./a.out –m SSD –b 4 Mb –l 20


