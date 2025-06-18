#ifndef ACTIONS_H
#define ACTIONS_H

#include "currency.h"
#include "deck.h"
#include "hand.h"
#include "player.h"

void hit(Deck *deck, Card **hand);
void stand(Deck *deck, Card **hand);
void double_down(Deck *deck, Card **hand);
void split(Deck *deck, Card **hand);
void surrender();
#endif // ACTIONS_H
