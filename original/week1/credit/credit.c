#include <cs50.h>
#include <stdio.h>

unsigned long long get_user_credit();
int calculate_luhn_checksum(unsigned long long n);
string validate_card(unsigned long long n);

int main(void)
{
    // Get user number
    unsigned long long number = get_user_credit();

    // Validate card and output
    string valid = validate_card(number);
    printf("%s", valid);
    return 0;
}

// Prompt for input
unsigned long long get_user_credit()
{
    unsigned long long number;
    do
    {
        number = get_long_long("Number: ");
    }
    while (number < 0);
    return number;
}

// Calculate checksum
int calculate_luhn_checksum(unsigned long long n)
{
    int total = 0;

    // Extract the check digit (last) and remove it for processing.
    int check_digit = n % 10;
    n /= 10;

    int position = 0;

    // Process remaining digits from right to left
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;

        // Double every other digit starting from the rightmost digit
        if (position % 2 == 0)
        {
            digit *= 2;

            // If doubling provides two digits, add them together
            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10);
            }
        }

        total += digit;
        position++;
    }

    // Add the check digit back
    total += check_digit;

    // Valid if total modulo 10 equals 0
    return (total % 10 == 0);
}

// Check for card length and starting digits
string validate_card(unsigned long long n)
{
    if (!calculate_luhn_checksum(n))
    {
        return "INVALID\n";
    }

    unsigned long long temp_n = n;

    // Get length of n
    int length = 0;
    while (temp_n > 0)
    {
        temp_n = temp_n / 10;
        length++;
    }

    if (length < 13)
    {
        return "INVALID\n";
    }

    int first_two_digits;
    while (n > 100)
    {
        first_two_digits = (n /= 10);
    }

    if ((first_two_digits == 34 || first_two_digits == 37) && length == 15)
    {
        return "AMEX\n";
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && length == 16)
    {
        return "MASTERCARD\n";
    }
    else if (first_two_digits / 10 == 4 && (length == 13 || length == 16 || length == 19))
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}
