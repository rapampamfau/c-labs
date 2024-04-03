#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate_permutations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            // Wywołaj rekurencyjnie funkcję dla reszty ciągu
            generate_permutations(arr, start + 1, end);
            // Przywróć pierwotne ustawienie elementów
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Wszystkie permutacje ciągu:\n");
    generate_permutations(arr, 0, n - 1);
    return 0;
}
