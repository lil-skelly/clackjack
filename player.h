#ifndef PLAYER_H
#define PLAYER_H
#include "currency.h"
#include "deck.h"
#include "hand.h"

typedef struct {
    Currency currency;
    Card* hand;
} Player;

Player* createPlayers(int num_players);
void initializePlayer(Player* player);
#endif // PLAYER_H