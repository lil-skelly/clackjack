#ifndef HAND_H
#define HAND_H

#include <stdio.h>
#include <stdlib.h>
#include "currency.h"
#include "deck.h"

#define MAX_HAND_SIZE 7

int evaluateHand(Card hand[]);
void addCardToHand(Card **hand, Card new_card);
int getHandSize(Card hand[]);
#endif // HAND_H
