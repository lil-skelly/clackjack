#!/bin/bash

gcc -c currency.c -o currency.o
gcc -c deck.c -o deck.o
gcc -c main.c -o main.o
gcc -c hand.c -o hand.o
gcc -c actions.c -o actions.o
gcc -c player.c -o player.o
gcc -c dealer.c -o dealer.o
gcc -c round.c -o round.o

gcc deck.o currency.o round.o dealer.o player.o hand.o actions.o main.o -o out
