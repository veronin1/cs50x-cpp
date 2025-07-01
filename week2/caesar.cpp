#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

int get_valid_argument(int argc, char *argv[]);
std::string encrypt(std::string plaintext, int key);

int main(int argc, char *argv[]) {
    int key = get_valid_argument(argc, argv);

    if (key == -1) {
        return 1;
    }

    std::string plaintext;
    std::cout << "plaintext: ";
    if (!(std::getline(std::cin, plaintext))) {
        std::cerr << "Invalid text";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return 1;
    }

    std::string ciphertext = encrypt(plaintext, key);
    std::cout << ciphertext;
}

int get_valid_argument(int argc, char *argv[]) {
    std::string usage = "Usage: ./caesar key";

    if (argc != 2) {
        std::cout << usage;
        return -1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        if (!(std::isdigit(argv[1][i]))) {
            std::cout << usage;
            return -1;
        }
    }

    int argument = std::stoi(argv[1]);

    if (argument < 0) {
        std::cout << usage;
        return -1;
    }

    return argument;
}

std::string encrypt(std::string plaintext, int key) {
    std::string ciphertext;

    for (int i = 0, n = plaintext.length(); i < n; i++) {
        char current_char = plaintext[i];

        if (std::isalpha(current_char)) {
            if (std::isupper(current_char)) {
                ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
            } else if (std::islower(current_char)) {
                ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
            } else {
                ciphertext[i] = current_char;
            }
        }
    }

    return ciphertext;
}
