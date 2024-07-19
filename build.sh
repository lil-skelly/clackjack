#!/bin/bash

gcc -c currency.c -o currency.o
gcc -c deck.c -o deck.o
gcc -c main.c -o main.o

gcc deck.o currency.o main.o -o out
