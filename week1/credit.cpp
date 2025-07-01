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
    std::cout << network;
    return 0;
}

long long get_credit_number(void) {
    long long card = 0LL;

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

    while (n > 0) {
        counter++;
        int last_digit = n % 10;
        n /= 10;

        if (counter % 2 == 0) {
            last_digit *= 2;
            if (last_digit > 9) {
                last_digit -= 9;
            }
        }
        total += last_digit;
    }
    return (total % 10 == 0);
}

std::string identify_card_network(long long card) {
    bool valid = calculate_luhn(card);

    if (!valid) {
        return "INVALID\n";
    }

    long long temp = card;
    int length = 0;
    while (temp > 0) {
        length++;
        temp /= 10;
    }

    long long first_two_digits = card;
    for (int i = 0; i < length - 2; i++) {
        first_two_digits /= 10;
    }

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37)) {
        return "AMERICAN EXPRESS\n";
    } else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55)) {
        return "MASTERCARD\n";
    } else if ((length == 13 || length == 16) && (first_two_digits / 10 == 4)) {
        return "VISA\n";
    } else {
        return "INVALID\n";
    }
}