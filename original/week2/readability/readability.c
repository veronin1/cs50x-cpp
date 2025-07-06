#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string get_text(void);
float calculate_coleman_index(const string text);

int main(void)
{
    const string text = get_text();
    float (index) = calculate_coleman_index(text);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

    return 0;
}

string get_text(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    return text;
}

float calculate_coleman_index(const string text)
{
    int n = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Handle empty input
    if (n == 0)
    {
        return 0.0;
    }

    // Iterate letters, words, sentences by 1 if condition found
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Averages for index calculation
    float average_letters = ((float) letters / words) * 100.0;
    float average_sentences = ((float) sentences / words) * 100.0;

    // index = 0.0588 * L - 0.296 * S - 15.8
    return round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);
}
