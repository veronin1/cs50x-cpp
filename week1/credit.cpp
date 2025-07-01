#include <iostream>

long long get_credit_number(void);
bool calculate_luhn(long long credit_card);

int main(void) {
    long long credit_card = get_credit_number();
    if (credit_card == 0) {
        std::cerr << "No valid credit card.\n";
        return 1;
    }

    calculate_luhn(credit_card);
    return 0;
}

long long get_credit_number(void) {
    long long credit_card = 0LL;

    /* Get number, if cin stream fails
    clear error flag and skip to newline*/
    do {
        std::cout << "Number: ";
        if (!(std::cin >> credit_card)) {
            std::cerr << "Invalid number";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            credit_card = 0;
        }
    } while (credit_card <= 0);
    return credit_card;
}

bool calculate_luhn(long long credit_card) {
    long long n = credit_card;
    int total = 0;
    int counter = 0;
    // Loop through all digits
    while (n > 0) {
        // Iterate on each loop
        counter++;

        // process last digit
        int last_digit = (int)(n % 10);

        // remove last digit
        n /= 10;

        // Math
        if (counter % 2 == 0) {
            last_digit *= 2;

            if (last_digit > 9) {
                int tens = last_digit % 10;
                int ones = last_digit / 10;
                total += tens + ones;
            } else {
                total += last_digit;
            }
        } else {
            total += last_digit;
        }
    }

    if (total % 10 == 0) {
        return true;
    }

    return false;
}