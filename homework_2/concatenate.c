#include <stdio.h>
#include <math.h>

int concatenate(int num1, int num2) {
	int nOfDigits2 = 0; //variable for storing the number of digits of num2
	
	int temp = num2; //temporary variable to use in the loop

	while(temp > 0) {
		nOfDigits2++; 
		temp /= 10; //increase the number of digits and remove last digit of temp
	}

	num1 = num1 * pow(10, nOfDigits2); 

	int result = num1 + num2;

	return result;
}

int main() {
	int number1, number2; //declare the input variables

	printf("Enter two positive integers: ");
	scanf("%d %d", &number1, &number2); //get user input and assign it to previously declared variables
	
	int result = concatenate(number1, number2); //call the "concatenate" function 

	printf("The concatenated number is %d \n", result); //print the result
	return 0;
}
