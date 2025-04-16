#ifndef DEALER_H
#define DEALER_H

#include "actions.h"
#include "deck.h"
#include "player.h"
#include <stdlib.h>

void dealInitialCards(Player *players, int num_players, Deck *deck);
#endif // DEALER_H