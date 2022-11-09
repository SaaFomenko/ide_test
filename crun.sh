#!/bin/bash
# Compile and run c++ program

#rm $1
gcc -ggdb $1.cpp filein.cpp fileout.cpp arrinit.cpp handlerarr.cpp -lm -lstdc++ -o $1.out && ./$1.out
#gcc $1.cpp -o $1 && ./$1
