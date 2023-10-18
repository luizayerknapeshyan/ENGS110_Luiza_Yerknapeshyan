#include <stdio.h>

int main() {
	int percent = 0;

	while(percent != -1) {
		printf("Input your percent grade or input -1 to exit: ");
		scanf("%d", &percent);

		if(percent == -1) {
			break;
		} else if (percent >= 0 && percent <= 59) {
			printf("Your grade is F\n");
		} else if (percent >= 60 && percent <= 69) {
                        printf("Your grade is D\n");
                } else if (percent >= 70 && percent <= 79) {
                        printf("Your grade is C\n");
                } else if (percent >= 80 && percent <= 89) {
                        printf("Your grade is B\n");
                } else if (percent >= 90 && percent <= 100) {
                        printf("Your grade is A\n");
                }
	}

	return 0;
}
