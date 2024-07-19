#include "currency.h"
#include <stdio.h>

void initializeCurrency(Currency *player_currency) {
    player_currency->start_balance = START_BALANCE;
    player_currency->current_balance = player_currency->start_balance;
    player_currency->won = 0;
}

void placeBet(Currency *player_currency, int bet_amount) {
    if ((player_currency->current_balance - bet_amount) < 0) {
        printf("Not enough balance to place bet of %i\n", bet_amount);
    }
    player_currency->bet = bet_amount;
    printf("Bet placed: %i\n", bet_amount);
}

void hBetOutcome(Currency *player_currency, int flag) {
    int multiplier;

    switch (flag) {
        case BET_WON:
            multiplier = BASE_MULTI;
            break;
        case BET_LOST:
            multiplier = -1;
            break;
        case BET_BLACKJACK:
            multiplier = BLACKJACK_MULTI;
            break;
        default:
            printf("Invalid flag\n");
            return;
    }
    updateCurrency(player_currency, player_currency->bet * multiplier);
}

void updateCurrency(Currency *player_currency, int amount) {
    if (amount > 0) {
        player_currency->won += amount;
    }
    player_currency->current_balance += amount;
    printCurrency(player_currency);
}

void printCurrency(Currency *player_currency) {
    printf("| %-14s | %-15s | %-3s |\n", "START BALANCE", "CURRENT BALANCE", "WON");
    printf("|---------------|-----------------|-----|\n");

    printf(
        "| %-14d | %-15d | %-3d |\n\n\n", 
           player_currency->start_balance, 
           player_currency->current_balance, 
           player_currency->won
    );
}
