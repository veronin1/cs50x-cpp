#include <array>
#include <iostream>

int main(void) {
  int change = 0;

  // Get change from user
  std::cout << "Change owed: ";
  if (!(std::cin >> change)) {
    std::cerr << "Invalid input. Enter a number.\n";
    return 1;
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