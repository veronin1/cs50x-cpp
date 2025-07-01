#include <cctype>
#include <iostream>
#include <string>
#include <utility>

std::pair<float, float> getLS(std::string text);
float calculateIndex(float L, float S);

int main(void) {
    std::string text;
    std::cout << "Text: ";
    if (!(std::getline(std::cin, text))) {
        std::cerr << "Invalid text";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::pair<float, float> LS = getLS(text);
    float index = calculateIndex(LS.first, LS.second);

    if (index < 1) {
        std::cout << "Before Grade 1\n";
    } else if (index > 16) {
        std::cout << "Grade 16+";
    } else {
        std::cout << "Grade " << index;
    }
}

std::pair<float, float> getLS(std::string text) {
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (char c : text) {
        if (isalpha(c)) {
            letters++;
        } else if (isspace(c)) {
            words++;
        } else if (c == '.' || c == '?' || c == '!') {
            sentences++;
        }
    }

    float S = 0.0f;
    float L = 0.0f;

    if (sentences != 0 && words != 0 && letters != 0) {
        L = ((float)(letters) / words) * 100.0f;
        S = ((float)(sentences) / words) * 100.0f;
    }

    return std::make_pair(L, S);
}

float calculateIndex(float L, float S) {
    float index = 0.0588f * L - 0.296f * S - 15.8f;
    return index;
}
