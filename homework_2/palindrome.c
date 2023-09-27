#include <stdio.h>

int inverse(int initial) {
        int remainder;
        int inverted = 0;

        while(initial > 0) {
                remainder = initial % 10; //the remainder is the last digit of the initial number

                inverted = inverted * 10 + remainder; //the remainder is appended to the inverted number

                initial /= 10; //the last digit of the initial number is removed
        }

        return inverted;
}

int main() {
        int number; //declare variable for user input

        printf("Enter an integer: ");
        scanf("%d", &number); //get user input and assign it to the previously declared variable

        int result = inverse(number); //call the inverse function

	if(result == number) {
		printf("the number %d is a palindrome. \n", number); //the number is a palindrome if it is equal to its inverse
	} else {
      		printf("The number %d in NOT a palindrome.\n", number); //the number is not a palindrome if it isn't equal to its inverse
	}

        return 0;
}

