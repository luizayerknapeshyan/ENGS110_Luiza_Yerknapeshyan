#include <stdio.h>
#include <string.h>

int binToDec(const char* binary) {
    int decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal = (decimal << 1) | 1;
        } else if (binary[i] == '0') {
            decimal = decimal << 1;
        } else {
            printf("Invalid input: %c is not a binary digit (0 or 1).\n", binary[i]);
            return -1;
        }
    }

    return decimal;
}

int main() {
    char binary[32]; 
    int decimal;

    printf("Enter a binary number (0s and 1s): ");
    scanf("%s", binary);

    decimal = binToDec(binary);

    if (decimal != -1) {
        printf("Decimal representation: %d\n", decimal);
    }

    return 0;
}

