#include <stdio.h>

int main() {
	int N;
	int result = 0;

	printf("Input a number 1-1000: ");
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		if(i % 3 == 0 || (i % 5 == 0 && i % 3 != 0)) {
			result += i;
		}
	}

	printf("%d\n", result);

	return 0;
}
