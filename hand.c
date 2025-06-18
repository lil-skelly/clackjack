#include "include/hand.h"


// Draw n cards and add them to hand
void drawAndAddCards(Card **hand, Deck* deck, int n) {
  if (n <= 0) return;
  Card card = drawCard(deck);
  addCardToHand(hand, card);
  drawAndAddCards(hand, deck, n-1); 
}

void addCardToHand(Card **hand_ptr, Card new_card) {
  int hand_size = getHandSize(*hand_ptr);

  Card *new_hand = realloc(*hand_ptr, (hand_size + 1) * sizeof(Card));
  if (new_hand == NULL) {
    fprintf(stderr, "Error reallocating memory for hand\n");
    exit(1);
  }
  new_hand[hand_size] = new_card;
  *hand_ptr = new_hand;
}

int evaluateHand(Card hand[]) {
  int total_value = 0;
  int ace_count = 0;
  int hand_size = getHandSize(hand);

  for (int i = 0; i < hand_size; i++) { // Sum all the cards values
    total_value += hand[i].value;
    if (hand[i].value == 11) {
      ace_count++;
    }
  }

  while (total_value > 21 && ace_count > 0) {
    total_value -= 10; // Convert ace from 11 to 1
    ace_count--;
  }

  if (total_value > 21) {
    return BET_LOST;
  } else if (total_value == 21 && hand_size == 2) {
    return BET_BLACKJACK;
  } else {
    return total_value;
  }
}

int getHandSize(Card hand[]) {
  int count = 0;
  for (int i = 0; i < MAX_HAND_SIZE; i++) {
    if (hand[i].value != 0) {
      break;
    }
    count++;
  }
  return count;
}