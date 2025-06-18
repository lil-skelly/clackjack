#ifndef ROUND_H
#define ROUND_H

#include "actions.h"
#include "currency.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include <stdio.h>
#include <string.h>

#define CHOICE_LIST                                                            \
  X(C_STAND, "Stand", 0)                                                       \
  X(C_HIT, "Hit", 1)                                                           \
  X(C_DDOWN, "Double down", 2)                                                 \
  X(C_SPLIT, "Split", 3)                                                       \
  X(C_SURRENDER, "Surrender", 4)

typedef enum {
#define X(name, desc, val) name,
  CHOICE_LIST
#undef X
      C_COUNT
} ChoiceType;

static const char *choiceDescriptions[] = {
#define X(name, desc, val) desc,
    CHOICE_LIST
#undef X
};

static const int choiceValues[] = {
#define X(name, desc, val) val,
    CHOICE_LIST
#undef X
};

typedef struct {
  int value;
  char description[20];
} Choice;

void printChoices(Choice choices[]);
int isUserSelectionValid(Choice choices[], int input);
Choice getPlayerChoice(Choice choices[]);

void populateChoice(Choice *choice, const char *description, int value);

void initializeBJChoices(Choice *choices);

void playTurn(Player *player, Deck *deck, Choice *choices, Card **hand);
#endif // ROUND_H