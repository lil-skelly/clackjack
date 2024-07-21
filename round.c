#include "round.h"

static int next_id = 1;

Choice getPlayerChoice(Choice choices[], int num_choices) {
    int input;
    Choice selected_choice;

    printf("Choose an option: \n");
    printChoices(choices, num_choices);

    while (1) {
        printf("CJ > ");
        scanf("%i\n", &input);
        for (int i=0; i<num_choices; i++) {
            if (input == choices[i].id) {
                printf("Selected choice with id %d", selected_choice.id);
                memcpy(&selected_choice, &choices[i], sizeof(Choice));
                break;
            }
        }
    }
    return selected_choice;
}

int isUserSelectionValid(Choice choices[], int num_choices, int input) {
    for (int i=0; i<num_choices; i++) {
        if (input == choices[i].id) {
            return 1;
        }
    }
    return 0;
}

void printChoices(Choice choices[], int num_choices) {
    for (int i=0; i<num_choices; i++) {
        printf("> %s (%d)\n", choices[i].description, choices[i].id);
    }
}

void populateChoice(Choice *choice, char description[], int value) {
    strcpy(choice->description, description);
    
    choice->value = value;
    choice->id = getNextChoiceID();
}

int getNextChoiceID() {
    return next_id++;
}

void initializeBJChoices(Choice* choices) {
    populateChoice(&choices[0], "Stand", C_STAND);
    populateChoice(&choices[1], "Hit", C_HIT);
    populateChoice(&choices[2], "Double Down", C_DDOWN);
    populateChoice(&choices[3], "Split", C_SPLIT);
    populateChoice(&choices[4], "Surrender", C_SURRENDER);
}

void playTurn(Player* player, Deck* deck, Choice* choices) {
    Choice player_choice;
    player_choice = getPlayerChoice(choices, sizeof(choices) / sizeof(Choice));

    int hand_size = getHandSize(player->hand);
    
    switch (player_choice.value)
    {
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
        fprintf(stderr, "Invalid choice with ID: %d\n", player_choice.id);
        break;
    }
}