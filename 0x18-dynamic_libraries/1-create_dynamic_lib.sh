#!/bin/bash
gcc -Wall -Wextra - Warrior -pedantic -c -fPIC *.c
gcc -shared -o libdynamic.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
