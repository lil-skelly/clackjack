#include "deck.h"
#include "currency.h"
#include "hand.h"
#include "actions.h"
#include "dealer.h"
#include "player.h"
#include "round.h"

#include <stdio.h>
#include <stdlib.h>

int SEEDED = 0; // Seeding hasn't occured yet


void cleanup_player(Player *player) {
    free(player);
    free(player->hand);
}

int main() {
    // Initialize and shuffle the deck
    Deck deck;
    prepareDeck(&deck);

    // Initialize player and dealer currency
    int num_players = 1;
    Player* players = createPlayers(num_players);

    Player* dealer = (Player*)malloc(sizeof(Player));
    initializePlayer(dealer);

    // // Initialize choices
    Choice* choices = (Choice*)malloc(sizeof(Choice) * 5);
    initializeBJChoices(choices);

    printChoices(choices, 5);
    for (int i=0; i<num_players; i++) {
        playTurn(&players[i], &deck, choices);
    }

    printCurrency(&players[0].currency);
    printCurrency(&dealer->currency);

    for (int i=0; i<num_players; i++) {
        cleanup_player(&players[i]);

    }
    cleanup_player(dealer);
    // free(choices);
    printf("Freed players/dealer and choices\n");
    // // Test currency functionality
    // printCurrency(&player_currency);
    // placeBet(&player_currency, 100);
    // hBetOutcome(&player_currency, BET_BLACKJACK);
    // updateCurrency(&player_currency, 200); // Winning amount

    return 0;
}
