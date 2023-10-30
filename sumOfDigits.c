#include <stdio.h>

int sum(int initial) {
    int remainder;
    int result = 0;

    while(initial > 0) {
        remainder = initial % 10;
        initial = initial / 10;

        result += remainder;
        //printf(result);
    }
    return result;
}

int main() {
    int number;
    
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    int result = sum(number);

    printf("The sum of digits is %d", result);
    return 0;
}
