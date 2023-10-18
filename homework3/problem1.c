#include <stdio.h>

int main() {
	float n1, n2, result;
	char operation;

	printf("Input an operation: ");
	scanf("%f %c %f", &n1, &operation, &n2);

	switch(operation) {
		case 43: 
			result = n1 + n2;
			break;
		case 45:
			result = n1 - n2;
			break;
		case 42:
			result = n1 * n2;
			break;
		case 47:
			result = n1 / n2;
			break;	
	}

	printf("%f", result);
	return 0;
}
