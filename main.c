#include "deck.h"
#include "currency.h"
#include <stdio.h>

int SEEDED = 0; // Seeding hasn't occured yet

int main() {
    // Initialize player currency
    Currency player_currency;
    initializeCurrency(&player_currency);

    // Initialize and shuffle the deck
    Deck deck;
    initializeDeck(&deck);
    shuffleDeck(&deck);

    // Print the shuffled cards
    for (int i = 0; i < 52; i++) {
        printCard(deck.cards[i]);
    }
    printf("\n\n\n\n");
    // Draw all cards (+1) from thew deck
    for (int i = 0; i < 53; i++) {
        Card card = drawCard(&deck);
        printCard(card);
    }
    
    // Test currency functionality
    printCurrency(&player_currency);
    placeBet(&player_currency, 100);
    hBetOutcome(&player_currency, BET_BLACKJACK);
    updateCurrency(&player_currency, 200); // Winning amount

    return 0;
}
