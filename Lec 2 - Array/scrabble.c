#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);
int ascii_to_index(char word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    printf("score1: %i\n", score1);

    int score2 = compute_score(word2);
    printf("score2: %i\n", score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player1 is the winner\n");
    }
    else if (score1 < score2)
    {
        printf("Player2 is the winner\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

}


int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score=0;

    for (int i=0, n = strlen(word); i < n; i++)
    {
        score += POINTS[ascii_to_index(word[i])];
    }
    return score;
}


int ascii_to_index(char word)
{
    int ascii = word;
    if (ascii >= 97 && ascii  <= 122)
    {
        ascii -= 32;
    }
    else 
    {
        return ascii - 65;
    }
    return ascii - 65;
}