#include "player.h"
#include <stdlib.h>
#include <stdio.h>

Player* createPlayers(int num_players) {
    Player* players = (Player*) malloc(num_players * sizeof(Player));
    if (players == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for players\n");
        return NULL;
    }
    for (int i=0; i<num_players; i++) {
        initializePlayer(&players[i]);
    }
    return players;
}

void initializePlayer(Player* player) {
    player->hand = (Card*)malloc(sizeof(Card));
    initializeCurrency(&player->currency);
}