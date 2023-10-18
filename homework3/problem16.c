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

    printf("Enter numbers from 1 to 10: ");

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

    for (int i = 1; i <= 10; i++) {
        int nOfElements = 0;

        for (int j = 0; j < current_size; j++) {
            if (ptr[j] == i) {
                nOfElements++;
            }
        }

        printf("The number of %ds is %d\n", i, nOfElements);
    }

    free(ptr);
    return 0;
}

