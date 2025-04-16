#include "include/deck.h"
#include <time.h>

const char *RANKS[] = {"2", "3",  "4", "5", "6", "7", "8",
                       "9", "10", "J", "Q", "K", "A"};
const char *SUITS[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const int VALUES[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

void initializeDeck(Deck *deck) {
  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      deck->cards[k].rank = (char *)RANKS[j];
      deck->cards[k].suit = (char *)SUITS[i];
      deck->cards[k].value = VALUES[j];
      k++;
    }
  }
  deck->index = DECK_SIZE;
}

void shuffleDeck(Deck *deck) {
  if (!SEEDED) {
    srand(time(NULL));
    SEEDED = 1;
  }

  for (int i = 51; i > 0; i--) {
    int r = rand() % (i + 1);

    Card temp = deck->cards[i];
    deck->cards[i] = deck->cards[r];
    deck->cards[r] = temp;
  }
}

void prepareDeck(Deck *deck) {
  initializeDeck(deck);
  shuffleDeck(deck);
}

Card drawCard(Deck *deck) {
  if (deck->index == 0) {
    printf("Deck empty. Cannot remove card\n");
    return (Card){
        .rank = NULL,
        .suit = NULL,
        .value = 0,
    };
  }
  return deck->cards[deck->index--];
}

void printCard(Card card) {
  if (card.rank != NULL && card.suit != NULL) {
    printf("%s of %s, value: %d\n", card.rank, card.suit, card.value);
  } else {
    printf("No card available\n");
  }
}
