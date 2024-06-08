#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Funkcja do obliczania wartości energetycznej dla pojedynczej linii
int calculate_energy_value(const char *line) {
    char first_digit = '\0';
    char last_digit = '\0';

    // Znalezienie pierwszej i ostatniej cyfry
    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            if (first_digit == '\0') {
                first_digit = line[i];
            }
            last_digit = line[i];
        }
    }

    if (first_digit == '\0' || last_digit == '\0') {
        return 0;
    }

    // Połączenie pierwszej i ostatniej cyfry w liczbę dwucyfrową
    char buffer[3];
    buffer[0] = first_digit;
    buffer[1] = last_digit;
    buffer[2] = '\0';

    return atoi(buffer);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return 1;
    }

    char line[256];
    int total_energy = 0;

    // Wczytanie i przetworzenie każdej linii
    while (fgets(line, sizeof(line), file)) {
        total_energy += calculate_energy_value(line);
    }

    fclose(file);

    printf("Total energy value (Part 1): %d\n", total_energy);
    return 0;
}
