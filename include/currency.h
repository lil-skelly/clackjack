#ifndef CURRENCY_H
#define CURRENCY_H

#include <stdio.h>
#include <stdlib.h>
// initial balance
#define START_BALANCE 1000
// Flag definitions

typedef enum { BET_LOST = -1, BET_WON = 1, BET_BLACKJACK = 3} BET_OUTCOME; // serves as the multiplier

// Payout multipliers
#define BASE_MULTI 2      // multiplier for a normal win
#define BLACKJACK_MULTI 3 // multiplier for a blackjack win

typedef struct {
  int start_balance;
  int current_balance;
  int won;
  int bet;
} Currency;

// Function declarations
void applyCurrencyChange(Currency *currency, int amount);
void initializeCurrency(Currency *player_currency);
void placeBet(Currency *player_currency, int bet_amount);
void updateCurrency(Currency *currency, int amount, int player_id);
void printCurrency(Currency currency, int player_id);
void hBetOutcome(Currency *currency, BET_OUTCOME outcome,
                 int player_id);

#endif // CURRENCY_H
