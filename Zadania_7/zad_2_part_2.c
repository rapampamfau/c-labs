#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GAMES 100
#define LINE_SIZE 256

typedef struct {
    int id;
    int max_red;
    int max_green;
    int max_blue;
} Game;

void parse_line(char *line, Game *game) {
    int red, green, blue;
    char *token = strtok(line, ";");
    while (token != NULL) {
        sscanf(token, "%d red, %d green, %d blue", &red, &green, &blue);
        if (red > game->max_red) game->max_red = red;
        if (green > game->max_green) game->max_green = green;
        if (blue > game->max_blue) game->max_blue = blue;
        token = strtok(NULL, ";");
    }
}

int main() {
    FILE *file = fopen("input_2.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[LINE_SIZE];
    Game games[MAX_GAMES];
    int game_count = 0;

    while (fgets(line, sizeof(line), file)) {
        Game game = {0, 0, 0, 0};
        sscanf(line, "Game %d:", &game.id);
        char *data = strchr(line, ':') + 1;
        parse_line(data, &game);
        games[game_count++] = game;
    }
    fclose(file);

    int total_power = 0;
    for (int i = 0; i < game_count; i++) {
        int power = games[i].max_red * games[i].max_green * games[i].max_blue;
        total_power += power;
    }
    printf("Sum of powers: %d\n", total_power);

    return EXIT_SUCCESS;
}
