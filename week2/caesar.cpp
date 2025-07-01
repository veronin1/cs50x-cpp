#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {}

int get_valid_argument(int argc, char *argv[]) {
    std::string usage = "Usage: ./caesar key";

    if (argc != 2) {
        std::cout << usage;
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        if (!(std::isdigit(argv[1][i]))) {
            std::cout << usage;
            return 1;
        }
    }

    int argument = std::stoi(argv[1]);

    if (argument < 0) {
        std::cout << usage;
        return 1;
    }

    return argument;
}
