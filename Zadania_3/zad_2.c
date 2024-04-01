#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createAndFillMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Błąd alokacji pamięci dla wierszy.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Błąd alokacji pamięci dla kolumn.\n");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    printf("Zawartość macierzy:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;

    printf("Podaj liczbę wierszy macierzy: ");
    scanf("%d", &rows);
    printf("Podaj liczbę kolumn macierzy: ");
    scanf("%d", &cols);

    srand(time(NULL));

    int** matrix = createAndFillMatrix(rows, cols);

    printMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);

    return 0;
}
