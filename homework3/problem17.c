#include <stdio.h>

// Function to convert a decimal number to binary
void decimalToBinary(int num, int num_bits, char binary[]) {
    // Handle negative numbers using two's complement
    if (num < 0) {
        num = (1 << num_bits) + num;
    }

    for (int i = num_bits - 1; i >= 0; i--) {
        binary[i] = (num & 1) + '0'; // Extract the least significant bit
        num >>= 1; // Right shift the number
    }
    binary[num_bits] = '\0'; // Null-terminate the binary string
}

int main() {
    int num;
    int num_bits = 4; // Number of bits for the binary representation

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    char binary[num_bits + 1]; // +1 for the null terminator
    decimalToBinary(num, num_bits, binary);

    if (num < 0) {
        printf("Binary (Two's Complement) representation: %s\n", binary);
    } else {
        printf("Binary representation: %s\n", binary);
    }

    return 0;
}

