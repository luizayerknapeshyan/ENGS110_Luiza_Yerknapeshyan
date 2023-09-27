#include <stdio.h>
#include <stdbool.h>

bool isPrime(int initial) {
        bool prime = true;

        for(int i = 2; i <= initial / 2; i++) {
                if(initial > 2 && initial % i == 0) {
                        prime = false;
                }
        }

        return prime;
}

int main() {
        int number;


        printf("Enter an integer: ");
        scanf("%d", &number);

        for(int i = 2; i <= number; i++) {
                if(isPrime(i)) {
                        printf("%d \n", i); //loop through every number from 2 to the number and call the isPrime function for each
                }
        }

        return 0;
}

