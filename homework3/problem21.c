#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int max_length = 10;
    unsigned int current_size = 0;
    unsigned int capacity = max_length;

    int* ptr = (int*)malloc(max_length * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    current_size = max_length;

    printf("Enter integers: ");

    int c = EOF;
    unsigned int i = 0;

    while (scanf("%d", &c) != EOF) {
        ptr[i++] = c;

        if (i == capacity) {
            capacity += max_length;
            ptr = (int*)realloc(ptr, capacity * sizeof(int));
            if (ptr == NULL) {
                printf("Memory reallocation failed.\n");
                free(ptr);
                return 1;
            }
        }
    }

    ptr[i] = '\0';

    int sum = 0;

    for (int i = 0; i < capacity; i++) {
    	    sum += ptr[i];
    }
	
    printf("The sum is %d\n", sum);
    free(ptr);
    return 0;
}

