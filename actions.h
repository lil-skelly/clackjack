#ifndef ACTIONS_H
#define ACTIONS_H

#include "deck.h"
#include "currency.h"
#include "hand.h"
#include "player.h"

void hit(Deck *deck, Player *player);

void stand(Deck *deck, Player *player);
void double_down(Deck *deck, Player *player);
void split(Deck *deck, Player *player);
void surrender();
#endif // ACTIONS_H 
