#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word); // function declaration

int main(void)
{
    string player1 = get_string("Player 1 Name: ");
    string player2 = get_string("Player 2 Name: ");
    
    // Get input words from both players
    string word1 = get_string("enter your word %s: ",player1);
    string word2 = get_string("enter your word %s: ",player2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("%s wins! %s : %d points but %s: %d points",player1, player1, score1, player2, score2);
    }
    else if (score2 > score1)
    {
        printf("%s wins! %s: %d points but %s: %d points",player2, player2, score2, player1, score1);
    }
    else 
    {
        printf("Tie! %s: %d points but %s: %d points",player1, score1, player2, score2); // if score1 = score2 print tie!
    }
}

int compute_score(string word) // compute_score function return score of players
{
    // TODO: Compute and return score for string
    int n = strlen(word); // string length of word insterted by player , ex "code" has 4 alphabets
    int score = 0; // score starts from 0
    for (int i = 0; i < n; i++)
    {
        if (isalpha(word[i])) // checks whether a character is an alphabet or not
        {
            word[i] = toupper(word[i]); // converting small letters to CAPITAL LETTERS
            score += POINTS[(int)word[i] - 65];
        }
    }
    return score;
}
