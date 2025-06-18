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
  player->hand = malloc(MAX_HANDS * sizeof(Card *));
  player->num_hands =1;
  if (!player->hand) {
    fprintf(stderr, "Error allocating memory for hands\n");
    exit(1);
  }

  // Initialize first hand with START_HAND_SIZE cards
  player->hand[0] = NULL;
  initializeCurrency(&player->currency);
}

void free_player(Player *player) {
  for (int i=0; i<player->num_hands;i++) {
    free(player->hand[i]);
  }
  free(player->hand);
  free(player);
}