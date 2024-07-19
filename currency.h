#ifndef CURRENCY_H
#define CURRENCY_H

// initial balance
#define START_BALANCE 1000
// Flag definitions
#define BET_WON 1
#define BET_LOST 0
#define BET_BLACKJACK 2

// Payout multipliers
#define BASE_MULTI 2 // multiplier for a normal win
#define BLACKJACK_MULTI 3 // multiplier for a blackjack win

typedef struct {
    int start_balance;
    int current_balance;
    int won;
    int bet;
} Currency;

// Function declarations
void initializeCurrency(Currency *player_currency);
void placeBet(Currency *player_currency, int bet_amount);
void updateCurrency(Currency *player_currency, int amount);
void printCurrency(Currency *player_currency);
void hBetOutcome(Currency *player_currency, int flag);

#endif // CURRENCY_H
