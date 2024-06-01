#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura do przechowywania informacji o grze
typedef struct {
    int red;
    int green;
    int blue;
} CubeSet;

// Funkcja do sprawdzania, czy dany zestaw kostek jest możliwy
int isPossible(CubeSet set, int max_red, int max_green, int max_blue) {
    return set.red <= max_red && set.green <= max_green && set.blue <= max_blue;
}

int main() {
    FILE *file = fopen("input_2.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.");
        return 1;
    }

    int sum_possible_games = 0;
    int sum_cube_power = 0;

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ":");
        int game_number = atoi(token + 4);

        int max_red = 12, max_green = 13, max_blue = 14;
        int possible = 1;
        int min_red = max_red, min_green = max_green, min_blue = max_blue;

        token = strtok(NULL, ";");
        while (token != NULL) {
            CubeSet set;
            sscanf(token, "%d %*s, %d %*s, %d %*s", &set.red, &set.green, &set.blue);

            if (!isPossible(set, max_red, max_green, max_blue)) {
                possible = 0;
                break;
            }

            if (set.red < min_red) min_red = set.red;
            if (set.green < min_green) min_green = set.green;
            if (set.blue < min_blue) min_blue = set.blue;

            token = strtok(NULL, ";");
        }

        if (possible) {
            sum_possible_games += game_number;
            sum_cube_power += min_red * min_green * min_blue;
        }
    }

    fclose(file);

    printf("Suma identyfikatorów możliwych gier: %d\n", sum_possible_games);
    printf("Suma mocy kostek w możliwych grach: %d\n", sum_cube_power);

    return 0;
}
