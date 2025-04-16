#include "include/player.h"
#include <stdio.h>
#include <stdlib.h>

int player_id = 1;

Player *createPlayers(int num_players) {
  int total = num_players + 1; // num of players including dealer
  Player *players = (Player *)malloc(total * sizeof(Player));

  if (players == NULL) {
    fprintf(stderr, "Error: Unable to allocate memory for players\n");
    exit(1);
  }
  for (int i = 0; i < num_players; i++) {
    initializePlayer(&players[i], HUMAN, i + 1); // IDs start from 1
  }
  initializePlayer(&players[total - 1], DEALER, DEALER_ID);
  return players;
}

void initializePlayer(Player *player, PLAYER_TYPE player_type, int id) {
  player->type = player_type;
  player->score = 0;
  player->id = id;
  player->hand = (Card *)malloc(sizeof(Card));
  if (player->hand == NULL) {
    fprintf(stderr, "Error: Unable to allocate memory for player hand\n");
    exit(1);
  }

  initializeCurrency(&player->currency);
}

void free_player(Player *player) {
  free(player->hand);
  free(player);
}