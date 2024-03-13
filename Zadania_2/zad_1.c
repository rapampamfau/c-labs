#include <stdio.h>

int main() {
    int number = 20;
    int * p_number = &number;
    printf("Before: %d\n", number);
    *p_number += 1;
    printf("After: %d\n", number);
    printf("After via pointer: %d\n", *p_number);

    return 0;
}