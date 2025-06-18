#include "include/actions.h"

void hit(Deck *deck, Card **hand) {
  Card card = drawCard(deck);
  addCardToHand(hand, card);
  printf("I hit\n");
}

void stand(Deck *deck, Card **hand) {
  printf("I stand\n");
  return;
}

void double_down(Deck *deck, Card **hand) {
  printf("I double down\n");
  return;
}

void split(Deck *deck, Card **hand) {
  printf("I split\n");
  return;
}

void surrender() {
  printf("I surrender\n");
  return;
}
