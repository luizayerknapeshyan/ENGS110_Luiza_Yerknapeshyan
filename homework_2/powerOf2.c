#include <stdio.h>
#include <stdbool.h> //include the boolean header

bool isPower(int initial) {
	bool powerOf2 = true;

	if(initial == 1) {
		return powerOf2; //1 is a power of 2
	} else {
		while(initial > 1) {
			if(initial % 2 != 0) {
				powerOf2 = false; //if the remainder at any point is not 0 then it is not a power of two
			}

			initial /= 2;
		}
	}

	return powerOf2;
}

int main() {
	int number; //declare variable to store user input

	printf("Enter an integer: ");
	scanf("%d", &number); //get user input and assing it to previously declared variable

	bool isPowerOf2 = isPower(number); //call the boolean functon "isPower"

	if(isPowerOf2 == true) {
		printf("%d is a power of 2. \n", number);
	} else {
		printf("%d is NOT a power of 2. \n", number);
	}

	return 0;
}
