#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool powerOfTwo(int n) {
	int count = 0;

    // Count the number of set bits (1s) in n
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }

    // If there is only one set bit, it's a power of 2
    return (count == 1);
}

int main() {
	unsigned int N;

	printf("Enter a positive integer: ");
	scanf("%d", &N);

	bool isPowerOfTwo = powerOfTwo(N);

	if(isPowerOfTwo) {
		printf("%d is a power of 2.\n", N);
	} else {
		printf("%d is not a power of 2.\n", N);
	}

	return 0;
}
