#include "include/main.h"
#include "include/currency.h"
#include "include/player.h"
#include "include/round.h"

int SEEDED = 0; // Seeding hasn't occured yet

int main() {
  // Initialize and shuffle the deck
  Deck deck;
  prepareDeck(&deck);

  // Initialize player and dealer currency
  int num_players =
      1; // later the number of players will be passed as command line arguments
  Player *players = createPlayers(num_players);
  Player *dealer = &players[num_players];

  // // Initialize choices
  Choice choices[C_COUNT];
  initializeBJChoices(choices);

  playTurn(&players[0], &deck,choices);

  printCurrency(players[0].currency,players[0].id);
  placeBet(&players[0].currency, 1000);
  printf("Won with blackjack! X3 multiplier\n");
  hBetOutcome(&players[0].currency, BET_BLACKJACK,  players[0].id);
  printf("Lost\n");
  hBetOutcome(&players[0].currency, BET_LOST, players[0].id);

  for (int i = 0; i < num_players; i++) {
    free_player(&players[i]);
  }
  printf("Freed players/dealer \n");
  // // Test currency functionality
  // printCurrency(&player_currency);
  // placeBet(&player_currency, 100);
  // hBetOutcome(&player_currency, BET_BLACKJACK);
  // updateCurrency(&player_currency, 200); // Winning amount

  return 0;
}
