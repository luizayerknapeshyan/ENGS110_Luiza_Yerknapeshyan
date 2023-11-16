#include <stdio.h>

void swap(int*a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int* array, int size) {
	for(int i = 0; i < size - 1; i++) {
		int min_index = i;

		for(int j = i + 1; j < size; j++) {
			if(array[j] < array[min_index]) {
				min_index = j;
			}
		}

	swap(&array[min_index], &array[i]);
	}
}

void printArray(int* array, int size) {
	for(int i = 0; i < size; i++) {
		printf("%d: %d\n", i, array[i]);
	}
}

int main() {
	int array[] = {11, 54, -22, 458, 0};
	int size = sizeof(array) / sizeof(array[0]);

	printf("before sorting:\n");
	printArray(array, size);
	
	selectionSort(array, size);

	printf("After sorting:\n");
	printArray(array, size);

	return 0;
}







