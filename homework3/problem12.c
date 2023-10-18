#include <stdio.h>

void printTriangle(int base) {
	for(int i = 1; i <= base; i += 2) {
		for(int j = base / 2; j > i / 2; j--) {
			printf(" ");
		}

		for(int k = 1; k <= i; k++) {
			printf("*");
		}

		printf("\n");
	}
}

int main() {
	int base;

	printf("Input the base of the triangle: ");
	scanf("%d", &base);
	
	printTriangle(base);

	return 0;	
}
