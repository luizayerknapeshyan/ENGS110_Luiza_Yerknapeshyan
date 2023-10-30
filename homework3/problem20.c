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
            capacity++;
            ptr = (int*)realloc(ptr, capacity * sizeof(int));
            if (ptr == NULL) {
                printf("Memory reallocation failed.\n");
                free(ptr);
                return 1;
            }
        }
    }

    ptr[i] = '\0';

    for (int i = capacity; i >= 0; i--) {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    free(ptr);
    return 0;
}

