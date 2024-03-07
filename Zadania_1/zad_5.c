#include <stdio.h>

int main() {
    int limit;

    printf("Podaj limit dla którego ma być wyliczona suma wielokrotności 3 i 5: \n");
    scanf("%d", &limit);

    if (limit < 0) {
        printf("0");
        return 0;

    } else {
        int sum;

        for(int i = 1; i < limit; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                sum += i;
            }
        }
        printf("Suma: %d\n", sum);
    }

    return 0;
}