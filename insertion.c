#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int rand_max, length;

    printf("Enter max random integer: ");
    scanf("%d", &rand_max);
    printf("Enter array length: ");
    scanf("%d", &length);

    int* numbers = calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        numbers[i] = rand() % rand_max + 1;
    }

    printf("Initial array: ");
    print_array(numbers, length);

    clock_t start_time = clock();
    int count = sort(numbers, length);
    clock_t end_time = clock();

    double result_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    print_array(numbers, length);

    printf("Count of iterations: %d\n", count);
    printf("The array was sorted in %f ms", result_time);

    free(numbers);

    return 0;
}

int sort(int* numbers, int length) {
    int counter = 0;

    for (int j = 2; j < length; j++) {
        int key = numbers[j];
        int i = j-1;

        while (i >= 0 && numbers[i] > key) {
            numbers[i+1] = numbers[i];
            i--;
        }

        numbers[i+1] = key;
        counter++;
    }

    return counter;
}

void print_array(int* numbers, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}