#ifndef HAND_H
#define HAND_H

#include <stdlib.h>
#include <stdio.h>

#include "deck.h"
#include "currency.h"

#define MAX_HAND_SIZE 7

int evaluateHand(Card hand[]);
void addCardToHand(Card** hand, Card new_card);
int getHandSize(Card hand[]);
#endif // HAND_H 
