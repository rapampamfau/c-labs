#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compareMoves(int playerMove, int computerMove, int *computerPoints, int *playerPoints)
{
    if (playerMove == computerMove)
    {
        printf("It's a draw!\n");
    }
    else if (playerMove == 1 && computerMove == 2)
    {
        (*computerPoints)++;
        printf("Paper wraps the rock! Point for computer.\n");
    }
    else if (playerMove == 1 && computerMove == 3)
    {
        (*playerPoints)++;
        printf("Rock smashes scissors! Point for you.\n");
    }
    else if (playerMove == 2 && computerMove == 1)
    {
        (*playerPoints)++;
        printf("Paper wraps the rock! Point for you.\n");
    }
    else if (playerMove == 2 && computerMove == 3)
    {
        (*computerPoints)++;
        printf("Scissors cut paper! Point for computer.\n");
    }
    else if (playerMove == 3 && computerMove == 1)
    {
        (*computerPoints)++;
        printf("Rock smashes scissors! Point for computer.\n");
    }
    else if (playerMove == 3 && computerMove == 2)
    {
        (*playerPoints)++;
        printf("Scissors cut paper! Point for you.\n");
    }
}

void displayScores(int *playerMoves, int *computerMoves, int rounds)
{
    printf("\nScores:\n");
    for (int i = 0; i < rounds; i++)
    {
        printf("Round %d - Player: %d | Computer: %d\n", i + 1, playerMoves[i], computerMoves[i]);
    }
}

int main()
{
    int numberOfRoundsToWin;
    int playerChoice;
    int computerChoice;
    int playerPoints = 0;
    int computerPoints = 0;
    int choices[] = {1, 2, 3};
    int round = 0;
    char userInput[10];

    printf("<------ Rock, paper, scissors ------>\nEnter number of rounds to win: ");
    scanf("%d", &numberOfRoundsToWin);
    printf("Enter a number.\n");

    int *playerMoves = (int *)malloc(numberOfRoundsToWin * sizeof(int));
    int *computerMoves = (int *)malloc(numberOfRoundsToWin * sizeof(int));

    while (playerPoints < numberOfRoundsToWin && computerPoints < numberOfRoundsToWin)
    {
        printf("1 -> rock\n2 -> paper\n3 -> scissors\n ");
        scanf("%d", &playerChoice);

        if (playerChoice < 1 || playerChoice > 3)
        {
            printf("Invalid choice! Please choose again.\n");
            continue;
        }

        if (strcmp(userInput, "scores") == 0)
        {
            displayScores(playerMoves, computerMoves, round);
            continue;
        }

        computerChoice = rand() % 3 + 1;

        compareMoves(playerChoice, computerChoice, &computerPoints, &playerPoints);

        playerMoves[round] = playerPoints;
        computerMoves[round] = computerPoints;
        round++;

        printf("Player: %d | Computer: %d\n", playerPoints, computerPoints);
    }

    free(playerMoves);
    free(computerMoves);

    return 0;
}
