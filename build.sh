#!/bin/bash

gcc -c currency.c -o currency.o
gcc -c deck.c -o deck.o
gcc -c main.c -o main.o
gcc -c hand.c -o hand.o

gcc deck.o currency.o hand.o main.o -o out
