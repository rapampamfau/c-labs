#include <stdio.h>

float multiply(float *p_num) {
    return *p_num * 2;
}

int main() {
    float num = 2.8;
    printf("Num: %.2f\n", num);
    printf("Multiplied: %.2f\n", multiply(&num));

return 0;
}