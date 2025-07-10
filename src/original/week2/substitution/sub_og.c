#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

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
    int n = strlen(key);

    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return NULL;
    }

    int* arr = malloc(sizeof(int) * n);

    if (arr == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        if (isalpha(key[i]))
        {
            if (isupper(key[i]))
            {
                arr[i] = key[i] - 'A';
            }
            else
            {
                arr[i] = key[i] - 'a';
            }
        }
        else
        {
            printf("%s\n", usage);
            return NULL;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                printf("%s\n", usage);
                free(arr);
                return NULL;
            }
        }
    }

    free(arr);

    return argv[1];
}

string encrypt_message(const string substitution_key, const string plaintext)
{
    int n = strlen(plaintext);

    string encrypted_message = malloc(n + 1);

    for (int i = 0; i < n; i++)
    {
        char current_char = plaintext[i];

        if (isupper(current_char))
        {
            encrypted_message[i] = substitution_key[current_char - 'A'];
            encrypted_message[i] = toupper(encrypted_message[i]);
        }
        else if (islower(current_char))
        {
            encrypted_message[i] = substitution_key[current_char - 'a'];
            encrypted_message[i] = tolower(encrypted_message[i]);
        }
        else
        {
            encrypted_message[i] = current_char;
        }
    }
    encrypted_message[n] = '\0';

    return encrypted_message;
}
