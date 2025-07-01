#include <iostream>

long long get_credit_number(void);

int main(void) {
    long long credit_card = get_credit_number();
    if (credit_card == 0) {
        return 1;
    }
    return 0;
}

long long get_credit_number(void) {
    long long credit_card = 0LL;
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