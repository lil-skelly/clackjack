#include "include/dealer.h"
#include "include/hand.h"

void dealInitialCards(Player *players, int num_players, Deck *deck) {
  for (int i = 0; i < num_players; i++) {
    drawAndAddCards(&players[i].hand[0], deck, 2); // deal initial two cards
  }
}