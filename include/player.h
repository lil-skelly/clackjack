#ifndef PLAYER_H
#define PLAYER_H
#include "deck.h"
#include "hand.h"
#include <stdbool.h>

#include "currency.h"

#define MAX_HANDS 4
#define START_HAND_SIZE 2

typedef enum { HUMAN = true, DEALER = false } PLAYER_TYPE;

#define DEALER_ID 0xb01dface

typedef struct {
  PLAYER_TYPE type; // to distinguish players/dealer
  Currency currency;
  Card **hand;
  int num_hands;
  int score;
  bool stand;
  int id;
} Player;

Player *createPlayers(int num_players);
void initializePlayer(Player *player, PLAYER_TYPE player_type, int id);
void free_player(Player *player);
#endif // PLAYER_H
