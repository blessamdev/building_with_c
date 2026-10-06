#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerchoice;
    int computerchoice;
    int playerscore = 0;
    int computerscore = 0;

    srand(time(NULL));

    printf("\n.......Welcome to the game Rock, Paper, Scissors.......\n");
    printf("Choose wisely....\n");

    do {
        // Generate a new choice every round
        computerchoice = (rand() % 3) + 1;

        printf("\nCHOOSE:\n");
        printf(" 1. Rock.\n");
        printf(" 2. Paper.\n");
        printf(" 3. Scissors.\n");
        printf(" 4. Exit game.\n");

        printf("What's ur guess....\t");
        scanf("%d", &playerchoice);

        if (playerchoice == 4) {
            printf("Thanks for playing.\n");
            break; // Exits the do-while loop
        }

        if (playerchoice < 1 || playerchoice > 4) {
            printf("Invalid choice! Please choose 1, 2, 3, or 4.\n");
            continue; // Re-starts the loop prompt
        }

        printf("Computer's choice: %d...\n", computerchoice);

        if (playerchoice == computerchoice) {
            printf("It's a tie.\n");
        } 
        else if ((playerchoice == 1 && computerchoice == 3) ||  // Rock beats Scissors
                 (playerchoice == 2 && computerchoice == 1) ||  // Paper beats Rock
                 (playerchoice == 3 && computerchoice == 2)) {  // Scissors beat Paper
            printf("You win!\n");
            playerscore++;
        } 
        else {
            printf("Computer wins.\n");
            computerscore++;
        }

        printf("Score -> You: %d | Computer: %d\n", playerscore, computerscore);

    } while (playerchoice != 4);

    return 0;
}
