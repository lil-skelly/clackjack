#include "include/currency.h"

void initializeCurrency(Currency *player_currency) {
  player_currency->start_balance = START_BALANCE;
  player_currency->current_balance = player_currency->start_balance;
  player_currency->won = 0;
}

void placeBet(Currency *player_currency, int bet_amount) {
  if ((player_currency->current_balance - bet_amount) < 0) {
    printf("Not enough balance to place bet of %i\n", bet_amount);
    return;
  }
  player_currency->bet = bet_amount;
  printf("Bet placed: %i\n", bet_amount);
}

void hBetOutcome(Currency *currency, BET_OUTCOME multiplier,
                 int player_id) {
  updateCurrency(currency, currency->bet * multiplier, player_id);
}
void applyCurrencyChange(Currency *currency, int amount) {
  if (amount > 0)
    currency->won += amount;
  currency->current_balance += amount;
  currency->won = amount;
}

void updateCurrency(Currency *currency, int amount, int player_id) {
  applyCurrencyChange(currency, amount);
  printCurrency(*currency, player_id);
}

void printCurrency(Currency currency, int player_id) {
  // Determine the status based on currency.won
  const char *status = (currency.won < 0) ? "LOST" : "WON";

  printf("| %-10s%-2d %-14s | %-15s | %-3s |\n", "PLAYER #", player_id,
         "START BALANCE", "CURRENT BALANCE", status);
  printf("|---------------|-----------------|-----|\n");

  printf("| %-14d | %-15d | %-3d |\n\n\n", currency.start_balance,
         currency.current_balance, abs(currency.won));
}
