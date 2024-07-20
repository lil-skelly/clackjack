#ifndef ROUND_H
#define ROUND_H

#include <stdio.h>
#include <string.h>
#include "currency.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "actions.h"

#define C_HIT 1
#define C_STAND 0
#define C_DDOWN 2
#define C_SPLIT 3
#define C_SURRENDER 4

typedef struct {
    char description[20];
    int id;
    int value;
} Choice;

void printChoices(Choice choices[], int num_choices);
int isUserSelectionValid(Choice choices[], int num_choices, int input);
Choice getPlayerChoice(Choice choices[], int num_choices);

void populateChoice(Choice *choice, char description[], int value);
int getNextChoiceID();
void initializeBJChoices(Choice* choices);

void playTurn(Player* player, Deck* deck, Choice* choices);

#endif // ROUND_H