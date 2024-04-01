#include <stdio.h>
#include <stdlib.h>

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int** generatePascalTriangle(int numRows) {
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++) {
            triangle[i][j] = binomialCoefficient(i, j);
        }
    }
    return triangle;
}

void printPascalTriangle(int** triangle, int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

void freePascalTriangle(int** triangle, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

int main() {
    int numRows;

    printf("Podaj liczbę wierszy trójkąta Pascala: ");
    scanf("%d", &numRows);

    int** pascalTriangle = generatePascalTriangle(numRows);

    printf("Trójkąt Pascala o %d wierszach:\n", numRows);
    printPascalTriangle(pascalTriangle, numRows);

    freePascalTriangle(pascalTriangle, numRows);

    return 0;
}
