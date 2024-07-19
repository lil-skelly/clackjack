#include "hand.h"

int evaluateHand(Card hand[], int hand_size) {
    int total_value = 0;
    int ace_count = 0;

    for (int i=0; i<hand_size; i++) { // Sum all the cards values
        total_value += hand[i].value;
        if (hand[i].value == 11) {
            ace_count++;
        }
    }

    while (total_value > 21 && ace_count > 0) {
        total_value -= 10; // Convert ace from 11 to 1
        ace_count--;
    }

    if (total_value > 21) {
        return HAND_BUST;
    } else if (total_value == 21 && hand_size == 2) {
        return HAND_BLACKJACK;
    } else {
        return total_value;
    }
}
