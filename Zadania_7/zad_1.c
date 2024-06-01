#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funkcja do konwersji słowa na cyfrę
int word_to_digit(const char* word) {
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1;  // Zwraca -1 jeśli słowo nie jest cyfrą
}

// Funkcja do znajdowania pierwszej i ostatniej cyfry w linii
void find_digits(const char* line, int* first_digit, int* last_digit) {
    *first_digit = -1;
    *last_digit = -1;
    int len = strlen(line);
    char* buffer = (char*)malloc((len + 1) * sizeof(char));  // Dynamicznie alokowany bufor
    if (buffer == NULL) {
        perror("Błąd alokacji pamięci");
        exit(EXIT_FAILURE);
    }

    int buffer_index = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(line[i])) {
            int digit = line[i] - '0';
            if (*first_digit == -1) {
                *first_digit = digit;
            }
            *last_digit = digit;
        } else if (isalpha(line[i])) {
            buffer[buffer_index++] = line[i];
            buffer[buffer_index] = '\0';

            if (buffer_index >= 3) {
                int digit = word_to_digit(buffer);
                if (digit != -1) {
                    if (*first_digit == -1) {
                        *first_digit = digit;
                    }
                    *last_digit = digit;
                    buffer_index = 0;  // Reset buffer po znalezieniu cyfry
                }
            }
        } else {
            buffer_index = 0;  // Reset buffer przy napotkaniu nie-alfanumerycznego znaku
        }
    }

    free(buffer);  // Zwolnienie dynamicznie zaalokowanej pamięci
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Nie można otworzyć pliku");
        return 1;
    }

    char line[256];
    int total_sum = 0;

    while (fgets(line, sizeof(line), file)) {
        int first_digit, last_digit;
        find_digits(line, &first_digit, &last_digit);

        if (first_digit != -1 && last_digit != -1) {
            int number = first_digit * 10 + last_digit;
            total_sum += number;
        }
    }

    fclose(file);

    printf("Suma wszystkich wartości energetycznych: %d\n", total_sum);
    return 0;
}
