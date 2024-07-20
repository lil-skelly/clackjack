#include "actions.h"

void hit(Deck *deck, Player *player) {
    Card card = drawCard(deck);
    addCardToHand(&player->hand, card);
    printf("I hit\n");
    
}

void stand(Deck *deck, Player *player) {
    printf("I stand\n");
    return;
}

void double_down(Deck *deck, Player *player) {
    printf("I double down\n");
    return;
}

void split(Deck *deck, Player *player) {
    printf("I split\n");
    return;
}

void surrender() {
    printf("I surrender\n");
    return;
}
