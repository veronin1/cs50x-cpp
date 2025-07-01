#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>

std::string get_string(const std::string& prompt);
int compute_score(std::string word);

// Scrabble points
const std::array<int, 26> POINTS = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                                    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int main(void) {
    std::string word1 = get_string("Player 1: ");
    std::string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2) {
        std::cout << "Player 1 wins\n";
    } else if (score2 > score1) {
        std::cout << "Player 2 wins\n";
    } else {
        std::cout << "Tie\n";
    }

    return 0;
}

// Custom get_string function
std::string get_string(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    if (!(std::cin >> input)) {
        std::cerr << "Invalid word";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return input;
}

int compute_score(std::string word) {
    int score = 0;

    // Uppercase string (easier index)
    transform(word.begin(), word.end(), word.begin(), ::toupper);

    for (int i = 0, n = word.length(); i < n; i++) {
        int index = word[i] - 'A';
        score += POINTS[index];
    }
    return score;
}