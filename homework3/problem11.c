#include <stdio.h>

void printTriangle(int height) {
	for(int i = 1; i <= height; i++) {
		for(int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	for(int i = 1; i <= height; i++) {
                for(int j = 1; j <= height - i; j++) {
                        printf(" ");
                }

		for(int k = 1; k <= i; k++) {
			printf("*");
		}
                printf("\n");
        }

}

int main() {
	int height;

	printf("Input the height: ");
	scanf("%d", &height);

	printTriangle(height);

	return 0;
}
