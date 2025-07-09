#include <array>
#include <iostream>

int main(void) {
  int change = 0;

  // Get change from user
  while (true) {
    std::cout << "Change owed (in cents): ";
    if (std::cin >> change && change >= 0) {
      break;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid input. Please enter a non-negative integer.\n";
  }

  // Create array
  std::array<int, 4> coins = {25, 10, 5, 1};

  // Greedy algo
  int counter = 0;
  for (int i = 0, n = coins.size(); i < n; i++) {
    while (change >= coins[i]) {
      counter++;
      change -= coins[i];
    }
  }

  // Print counter
  std::cout << counter << '\n';
  return 0;
}