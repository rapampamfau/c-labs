#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    data.i = 42;
    printf("Wartość int: %d\n", data.i);

    data.f = 3.14;
    printf("Wartość float: %f\n", data.f);

    data.c = 'A';
    printf("Wartość char: %c\n", data.c);

    return 0;
}
    