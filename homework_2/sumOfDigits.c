#include <stdio.h>

int sum(int initial) {
    int remainder;
    int result = 0;

    while(initial > 0) {
        remainder = initial % 10; //assing the last digit of the initial number to remainder
        initial = initial / 10; //remove the last digit of initial

        result += remainder; //add the remainder to the result
    }
    return result;
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    int result = sum(number);

    printf("The sum of digits is %d \n", result);
    return 0;
}

