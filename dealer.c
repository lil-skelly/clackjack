#include "dealer.h"

void dealInitialCards(Player* players, int num_players, Deck* deck) {
    for (int i = 0; i < num_players; i++) {
        addCardToHand(&players[i].hand, drawCard(deck));

    }
}