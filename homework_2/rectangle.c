#include <stdio.h>

void rectangle(int length, int width) {
	for(int i = 0; i < length; i++) {
		if (i == 0 || i == length - 1) {
			for(int j = 0; j < width; j++) {
				printf("*"); //print width *s in the first and last row
			}
			printf("\n");		
		} else {
			printf("*");
			for(int j = 0; j < width - 2; j++) {
                                printf(" ");
                        }
			printf("*\n"); //print *, width - 2 spaces and * in the rest of the rows
		}
	}
}

int main() {
	int N, M;

	printf("Enter 2 integers: ");
	scanf("%d %d", &N, &M);	
	
	rectangle(N, M);
	return 0;
}

//Your rectangle has a missing comlumn
