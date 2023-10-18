#include <stdio.h>

void removeN(int* arr, int n) {
	for(int i = 0; i < 10; i++) {
		if(arr[i] == n) {
			for(int j = i; j < 9; j++) {
				arr[j] = arr[j+1];
			}
			arr[9] = 0;
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[10], newArr[10];
	int n;

	printf("Input 10 integers: ");

	for(int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Input an integer value: ");
	scanf("%d", &n);

	removeN(arr, n);

	return 0;
}
