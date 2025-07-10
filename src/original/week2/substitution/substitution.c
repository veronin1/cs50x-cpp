#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_valid_argument(int argc, string argv[]);
string get_message(void);
string encrypt_message(const string substitution_key, const string plaintext);

int main(int argc, string argv[])
{
    const string substitution_key = get_valid_argument(argc, argv);

    if (substitution_key == NULL)
    {
        return 1;
    }

    const string plaintext = get_message();
    string ciphertext = encrypt_message(substitution_key, plaintext);

    if (ciphertext == NULL)
    {
        return 1;
    }

    printf("ciphertext: %s\n", ciphertext);
    free(ciphertext);

    return 0;
}

string get_message(void)
{
    string plaintext = get_string("plaintext: ");

    if (plaintext == NULL)
    {
        printf("Error: No input provided.\n");
        return NULL;
    }

    return plaintext;
}

string get_valid_argument(int argc, string argv[])
{
    string usage = "Usage: ./substitution key";

    if (argc != 2)
    {
        printf("%s\n", usage);
        return NULL;
    }

    string key = argv[1];
    int key_length = strlen(key);

    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return NULL;
    }

    bool seen[26] = {false};

    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be all letters\n%s\n", usage);
            return NULL;
        }

        int index = tolower(key[i]) - 'a';

        if (seen[index])
        {
            printf("No duplicate letters allowed\n%s\n", usage);
            return NULL;
        }

        seen[index] = true;
    }

    return key;
}

string encrypt_message(const string substitution_key, const string plaintext)
{
    int n = strlen(plaintext);

    string ciphertext = malloc(n + 1);

    if (ciphertext == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        char current_char = plaintext[i];

        if (isupper(current_char))
        {
            ciphertext[i] = substitution_key[current_char - 'A'];
            ciphertext[i] = toupper(ciphertext[i]);
        }
        else if (islower(current_char))
        {
            ciphertext[i] = substitution_key[current_char - 'a'];
            ciphertext[i] = tolower(ciphertext[i]);
        }
        else
        {
            ciphertext[i] = current_char;
        }
    }
    ciphertext[n] = '\0';

    return ciphertext;
}
