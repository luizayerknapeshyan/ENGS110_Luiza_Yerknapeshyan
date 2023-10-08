#include <stdio.h>

void rectangle(int length, int width, char symbol) {
        for(int i = 0; i < length; i++) {
                if (i == 0 || i == length - 1) {
                        for(int j = 0; j < width - 1; j++) {
                                printf("%c", symbol);
                        }
                        printf("\n");
                } else {
                        printf("%c", symbol);
                        for(int j = 0; j < width - 3; j++) {
                                printf(" ");
                        }
                        printf("%c\n", symbol);
                }
        }
}

int main() {
        int N, M;
	
	char symbol;  

	printf("Enter a character: ");
        scanf("%c", &symbol); //get a character user input and assign it to symbol

        printf("Enter 2 integers: ");
        scanf("%d %d", &N, &M);

        rectangle(N, M, symbol);
        return 0;
}

//The same here
