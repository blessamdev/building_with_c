/*
Author: Blessam
Date:   2026-10-11
Description: This is a simple hangman game implemented in C89 standard. 
The game allows the player to guess letters of a hidden word,
with a limited number of incorrect guesses allowed before the game is lost.
The program includes functions for displaying the current state of the word,
checking for win/loss conditions, and handling user input.
Language: C89
*/

#include <stdio.h>
#include <string.h>

char secretWord[] = "code";
char guessedWord[] = "____";
int chances = 3;
int wordLength = 4;

int main(void) {
    char userGuess;
    int correctGuess;
    int found;
    int i;

    printf("========================================\n");
    printf("         HANGMAN GAME START             \n");
    printf("========================================\n");
    printf("You have %d chances to guess the word.\n", chances);

    while (chances > 0) {
        printf("\nWord: %s\n", guessedWord);
        printf("Chances left: %d\n", chances);
        printf("Enter a letter: ");
        scanf(" %c", &userGuess);

        found = 0;
        for (i = 0; i < wordLength; i++) {
            if (secretWord[i] == userGuess) {
                guessedWord[i] = userGuess;
                found = 1;
            }
        }
        if (found == 0) {
            chances--;
            printf("Wrong guess! '%c' is not in the word.\n", userGuess);
        } else {
            printf("Good job! '%c' is in the word.\n", userGuess);
        }

        if (strchr(guessedWord, '_') == NULL) {
            printf("\nFinal Word: %s\n", guessedWord);
            printf("The Man survives! You Win!\n");
            break;
        }
    }

    if (chances == 0) {
        printf("\nMan gets hanged! Game Over. The secret word was: %s\n", secretWord);
    }

    return 0;
}
