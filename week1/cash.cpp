#include <iostream>

int main(void) {
  int change = 0;

  // Get change from user
  std::cout << "Change owed: ";
  if (!(std::cin >> change)) {
    std::cerr << "Invalid input. Enter a number.\n";
    return 1;
  }

  // Greedy algorithm
  int counter = 0;
  while (change >= 25) {
    counter++;
    change -= 25;
  }
  while (change >= 10) {
    counter++;
    change -= 10;
  }
  while (change >= 5) {
    counter++;
    change -= 5;
  }
  while (change >= 1) {
    counter++;
    change -= 1;
  }

  // Print
  std::cout << counter;
  return 0;
}