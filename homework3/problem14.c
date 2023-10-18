#include <stdio.h>
#include <stdlib.h>

int main() {
    int lower_bound = 1;
    int upper_bound = 100;
    int computer_guess;
    char user_feedback;

    printf("Think of a number between 1 and 100.\n");
    printf("Press Enter when you're ready...");
    getchar();

    int attempts = 0;
    while (1) {
        computer_guess = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
        printf("My guess is %d.\n", computer_guess);

        printf("Is my guess too high (H), too low (L), or correct (C)? ");
        scanf(" %c", &user_feedback);

        if (user_feedback == 'C' || user_feedback == 'c') {
            printf("Great! I guessed your number %d in %d attempts!\n", computer_guess, attempts);
            break;
        } else if (user_feedback == 'H' || user_feedback == 'h') {
            upper_bound = computer_guess - 1;
        } else if (user_feedback == 'L' || user_feedback == 'l') {
            lower_bound = computer_guess + 1;
        } else {
            printf("Please enter 'H' for too high, 'L' for too low, or 'C' for correct.\n");
        }

	attempts++;
    }

    return 0;
}

