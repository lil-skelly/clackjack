#include "include/main.h"
#include "include/currency.h"
#include "include/dealer.h"
#include "include/hand.h"
#include "include/player.h"
#include "include/round.h"

int SEEDED = 0; // Seeding hasn't occured yet

void cleanup_players(Player **players, int num_players) {
  for (int i = 0; i < num_players; i++) {
    free_player(players[i]);
  }
}

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

  for (int i=0; i<(num_players); i++) { // exclude the dealer
    Player *pPlayer = &players[i];
    placeBet(&pPlayer->currency);
    playTurn(pPlayer, &deck, choices, &pPlayer->hand[0]);
    pPlayer->score = evaluateHand(*pPlayer->hand);
  }

  dealInitialCards(players, num_players, &deck);

  cleanup_players(&players, num_players);
  printf("Freed players/dealer \n");


  return 0;
}