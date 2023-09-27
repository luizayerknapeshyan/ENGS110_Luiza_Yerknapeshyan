#include <stdio.h>
#include <stdbool.h>

bool prime(int initial) {
	bool isPrime = true;

	if(initial == 0 || initial == 1) {
		isPrime = false; //0 and 1 are not prime
	} else {	
	    for(int i = 2; i <= initial / 2; i++) {
			if(initial > 2 && initial % i == 0) {
				isPrime = false; //if the number is divisible by any number from 2 to its half then it isn't prime			
			}
		}
	}
	return isPrime;
}

int main() {
	int number;

	printf("Enter an integer: ");
	scanf("%d", &number);

	bool isPrime = prime(number);

	if(isPrime) {
		printf("%d is a prime number. \n", number);
	} else {
		printf("%d is NOT a prime number. \n", number);
	}

	return 0;
}
