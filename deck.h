#ifndef DECK_H
#define DECK_H

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
    int top;
} Deck;

// Function declarations
void initializeDeck(Deck *deck);
void shuffleDeck(Deck *deck);

Card getTopCard(Deck *deck);
void removeTopCard(Deck *deck);
Card drawCard(Deck *deck);

int evaluateHand(Card hand[]);

void printCard(Card card);
#endif // DECK_H
