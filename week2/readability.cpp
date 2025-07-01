#include <cctype>
#include <iostream>
#include <string>
#include <utility>

std::pair<int, int> getLS(std::string text);
float calculateIndex(float L, float S);

int main(void) {
    std::string text;
    std::cout << "Text: ";
    if (!(std::cin >> text)) {
        std::cerr << "Invalid text";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::pair<int, int> LS = getLS(text);
    float index = calculateIndex(LS.first, LS.second);

    if (index < 1) {
        std::cout << "Before Grade 1\n";
    } else if (index > 16) {
        std::cout << "Grade 16+";
    } else {
        std::cout << "Grade " << index;
    }
}

std::pair<int, int> getLS(std::string text) {
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (char c : text) {
        if (isalpha(c)) {
            letters++;
        } else if (isspace(c)) {
            words++;
        } else if (text[c] == '.' || text[c] == '?' || text[c] == '!') {
            sentences++;
        }
    }

    int L = (letters / words) * 100;
    int S = (words / sentences) * 100;

    return std::make_pair(L, S);
}

float calculateIndex(float L, float S) {
    float index = 0.0588f * L - 0.296f * S - 15.8f;
    return index;
}
