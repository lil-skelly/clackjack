#ifndef HAND_H
#define HAND_H

#include "deck.h"

#define HAND_BUST -1
#define HAND_BLACKJACK 21

int evaluateHand(Card hand[], int hand_size);
#endif // HAND_H 
