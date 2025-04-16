#ifndef DECK_H
#define DECK_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the SEEDED constant
extern int SEEDED;

#define DECK_SIZE 52
// Define the Card and Deck structures
typedef struct {
  char *rank;
  char *suit;
  int value;
} Card;

typedef struct {
  Card cards[52];
  int index; // decreases for each card drawed
} Deck;

// Function declarations
void initializeDeck(Deck *deck);
void shuffleDeck(Deck *deck);
void prepareDeck(Deck *deck);

Card drawCard(Deck *deck);

void printCard(Card card);
#endif // DECK_H
