#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// scrabble.c

const int points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

void get_player_words(string words[]);
int compute_score(string word);
void print_winner(string *words);

int main(void)
{
    string words[2];

    // Prompt the user for two words
    get_player_words(words);

    // Print the winner & calculate score
    print_winner(words);

    return 0;
}

void get_player_words(string words[])
{
    for (int i = 0; i < 2; i++)
    {
        words[i] = get_string("Player %d: ", i + 1);
    }
}

int compute_score(string word)
{
    int score = 0;
    int letter_index = 0;

    // Check if its alphabetical and then lowercase string
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                word[i] += 32;
            }

            letter_index = word[i] - 97;

            // Calculate score
            score += points[letter_index];
        }
    }

    return score;
}

void print_winner(string *words)
{
    int player1 = compute_score(words[0]);
    int player2 = compute_score(words[1]);

    if (player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2 > player1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
