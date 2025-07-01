#include <iostream>
#include <string>

long long get_credit_number(void);
bool calculate_luhn(long long card);
std::string identify_card_network(long long card);

int main(void) {
    long long card = get_credit_number();
    if (card == 0) {
        std::cerr << "No valid credit card.\n";
        return 1;
    }

    std::string network = identify_card_network(card);
    return 0;
}

long long get_credit_number(void) {
    long long card = 0LL;

    /*
     * Get number, if cin stream fails
     * clear error flag and skip to newline
     */

    do {
        std::cout << "Number: ";
        if (!(std::cin >> card)) {
            std::cerr << "Invalid number";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            card = 0;
        }
    } while (card <= 0);
    return card;
}

bool calculate_luhn(long long card) {
    long long n = card;
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

        /*
         * If counter is even, double last_digit.
         * If doubled value is greater than 9, add the sum
         * of its digits to total. Otherwise, add last_digit
         * directly to total.
         * If counter is odd, add last_digit to total.
         */
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

std::string identify_card_network(long long card) {
    return "Hi";
    return "bye";
}