#include <stdio.h>

int calculateFactorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    else
        return num * calculateFactorial(num - 1);
}

void calculateFactorialsInArray(int array[], int length) {
    for(int i = 0; i < length; i++) {
        printf("For number %d factorial is: %d\n", array[i], calculateFactorial(array[i]));
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(array) / sizeof(array[0]);
    calculateFactorialsInArray(array, length);

    return 0;
}
