#include "include/round.h"

void populateChoice(Choice *choice, const char *description, int value) {
  strcpy(choice->description, description);
  choice->value = value;
}

void initializeBJChoices(Choice *choices) {
  for (int i = 0; i < C_COUNT; i++) {
    populateChoice(&choices[i], choiceDescriptions[i], choiceValues[i]);
  }
}

int isUserSelectionValid(Choice choices[], int input) {
  for (int i = 0; i < C_COUNT; i++) {
    if (choiceValues[i] == input)
      return 1;
  }
  return 0;
}

Choice getPlayerChoice(Choice choices[]) {
  int input;
  Choice selected_choice;

  while (1) {
    printf("Choose an option: \n");
    printChoices(choices);
    if (scanf("%d", &input) != 1) {
      printf("Invalid input. Please enter a number.\n");
      while (getchar() != "\n")
        ;
      continue;
    }

    for (int i = 0; i < C_COUNT; i++) {
      if (input == choices[i].value) {
        return choices[i];
      }
    }
  }

  printf("Invalid selection. Please try again.\n");

  return selected_choice;
}

void printChoices(Choice choices[]) {
  for (int i = 0; i < C_COUNT; i++) {
    printf("> %s (%d)\n", choices[i].description, choices[i].value);
  }
}

void playTurn(Player *player, Deck *deck, Choice *choices) {
  Choice player_choice;
  player_choice = getPlayerChoice(choices);

  int hand_size = getHandSize(player->hand);

  switch (player_choice.value) {
  case C_HIT:
    hit(deck, player);
    break;
  case C_STAND:
    stand(deck, player);
    break;
  case C_DDOWN:
    double_down(deck, player);
    break;
  case C_SPLIT:
    split(deck, player);
    break;
  case C_SURRENDER:
    surrender();

  default:
    fprintf(stderr, "Invalid choice with ID: %d (%s) \n", player_choice.value,
            player_choice.description);
    break;
  }
}
