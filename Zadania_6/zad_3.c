#include <stdio.h>

// Definicje trzech funkcji arytmetycznych
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

// Typ wskaźnika do funkcji, która przyjmuje dwa inty i zwraca int
typedef int (*operation)(int, int);

int main() {
    int choice, x, y;
    operation op;

    // Pytanie użytkownika o wybór operacji
    printf("Wybierz operację:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    printf("Wybór: ");
    scanf("%d", &choice);

    // Pobranie dwóch liczb od użytkownika
    printf("Podaj dwie liczby: ");
    scanf("%d %d", &x, &y);

    // Ustawienie wskaźnika do odpowiedniej funkcji
    switch (choice) {
        case 1:
            op = add;
            break;
        case 2:
            op = multiply;
            break;
        case 3:
            op = subtract;
            break;
        default:
            printf("Nieprawidłowy wybór!\n");
            return 1;
    }

    // Wywołanie wybranej funkcji za pomocą wskaźnika do funkcji i wyświetlenie wyniku
    int result = op(x, y);
    printf("Wynik: %d\n", result);

    return 0;
}
