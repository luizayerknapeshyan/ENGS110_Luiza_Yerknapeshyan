#include <stdio.h>

int main() {
	int arr[10];

	printf("Enter 10 integers: ");

	for(int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	int min = arr[0];
	int max = arr[0];

	for(int i = 0; i < 10; i++) {
		if(max < arr[i]) {
			max = arr[i];
		}

		if(min > arr[i]) {
			min = arr[i];
		}
	} 

	printf("the maximum value is %d and the minimum value is %d.\n", max, min);

	return 0;
}
