#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
    
}

int main() {
    int n;
    printf("Podaj liczbę z jakiej chcesz uzyskać silnię: ");
    scanf("%d", &n);

    unsigned long long result = factorial(n);
    if (result < 0) {
        printf("Nie można uzyskać silni z ujemnej liczby.\n");
        return -1;
    }
    printf("Wynik: %llu\n", result);
    return 0;
}
