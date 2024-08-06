#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to get the Scrabble score of a word
int getScrabbleScore(char word[]) {
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'l': case 'n': case 's': case 't': case 'r':
                score += 1; break;
            case 'd': case 'g':
                score += 2; break;
            case 'b': case 'c': case 'm': case 'p':
                score += 3; break;
            case 'f': case 'h': case 'v': case 'w': case 'y':
                score += 4; break;
            case 'k':
                score += 5; break;
            case 'j': case 'x':
                score += 8; break;
            case 'q': case 'z':
                score += 10; break;
            default:
                break;
        }
    }
    return score;
}

int main(int argc, char* argv[])
{
    char word1[100];
    char word2[100];
    int playerOnePoints;
    int playerTwoPoints;

    // Input for Player 1
    printf("Player 1 enter a word: ");
    scanf("%99s", word1); // Note: Limiting input to avoid buffer overflow

    // Input for Player 2
    printf("Player 2 enter a word: ");
    scanf("%99s", word2); // Note: Limiting input to avoid buffer overflow

    // Calculate scores
    playerOnePoints = getScrabbleScore(word1);
    playerTwoPoints = getScrabbleScore(word2);

    // Display scores
    printf("Player 1 score: %d\n", playerOnePoints);
    printf("Player 2 score: %d\n", playerTwoPoints);

    // Determine the winner
    if (playerOnePoints > playerTwoPoints) {
        printf("Player 1 wins!\n");
    } else if (playerOnePoints < playerTwoPoints) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}
