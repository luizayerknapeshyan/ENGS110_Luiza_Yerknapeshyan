#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int N = (rand() % 100) + 1;
	int guess;

	printf("Guess the number between 1 and 100 \n");
	scanf("%d", &guess);

	bool correct = false;

	while (correct == false) {
		if (guess == N) {
			correct = true;
			printf("Correct!\n");
		} else if (guess > N) {
			printf("Too high, try agian\n");
			scanf("%d", &guess);
		} else {
			printf("Too low, try again\n");
			scanf("%d", &guess);
		}
	}

	return 0;
}
