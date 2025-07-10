#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program that encrypts a message given a non-zero integer within argv[1] using Caesar cipher.

int get_valid_argument(int argc, string argv[]);
string encrypt_message(int caesar_key, const string plaintext);
string get_message(void);

int main(int argc, string argv[])
{
    int caesar_key = get_valid_argument(argc, argv);

    if (caesar_key == -1)
    {
        return 1;
    }

    const string plaintext = get_message();
    string ciphertext = encrypt_message(caesar_key, plaintext);

    if (ciphertext == NULL)
    {
        return 1;
    }

    printf("ciphertext: %s\n", ciphertext);
    free(ciphertext);

    return 0;
}

int get_valid_argument(int argc, string argv[])
{
    string usage = "Usage: ./caesar key";

    if (argc != 2)
    {
        printf("%s\n", usage);
        return -1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("%s\n", usage);
            return -1;
        }
    }

    int argument = atoi(argv[1]);

    if (argument < 0)
    {
        return -1;
    }

    return argument;
}

string get_message(void)
{
    string plaintext = get_string("plaintext: ");
    return plaintext;
}

string encrypt_message(int caesar_key, const string plaintext)
{
    int n = strlen(plaintext);
    caesar_key %= 26;

    string encrypted_message = malloc(n + 1);

    if (encrypted_message == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        char current_char = plaintext[i];

        if (isupper(current_char))
        {
            encrypted_message[i] = ((current_char - 'A' + caesar_key) % 26) + 'A';
        }
        else if (islower(current_char))
        {
            encrypted_message[i] = ((current_char - 'a' + caesar_key) % 26) + 'a';
        }
        else
        {
            encrypted_message[i] = current_char;
        }
    }
    encrypted_message[n] = '\0';

    return encrypted_message;
}
