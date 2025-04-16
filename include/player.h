#ifndef PLAYER_H
#define PLAYER_H
#include "deck.h"
#include "hand.h"
#include <stdbool.h>

#include "currency.h"

typedef enum { HUMAN = true, DEALER = false } PLAYER_TYPE;

#define DEALER_ID 0xb01dface

typedef struct {
  PLAYER_TYPE type; // to distinguish players/dealer
  Currency currency;
  Card *hand;
  int score;
  bool stand;
  int id;
} Player;

Player *createPlayers(int num_players);
void initializePlayer(Player *player, PLAYER_TYPE player_type, int id);
void free_player(Player *player);
#endif // PLAYER_H
