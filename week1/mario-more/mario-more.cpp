#include <iostream>
#include <limits>

int get_height(void);
void print_pyramid(int height);

int main(void) {
  const int height = get_height();
  print_pyramid(height);
}

int get_height(void) {
  int n;
  do {
    std::cout << "Height: ";
    std::cin >> n;

    if (std::cin.fail()) {
      std::cin.clear();
      // Ignore remaining input in the buffer until a newline is found (cs50.ai)
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

  } while (n < 1 || n > 8);

  return n;
}

void print_pyramid(int height) {
  int n = height;

  // Outer loop for each row
  for (int i = 0; i < n; i++) {
    // Print spaces before left pyramid
    for (int j = n; j > i + 1; j--) {
      std::cout << " ";
    }
    // Print left pyramid
    for (int k = 0; k < i + 1; k++) {
      std::cout << "#";
    }

    // Print two-space gap
    std::cout << "  ";

    // Print normal pyramid
    for (int l = 0; l < i + 1; l++) {
      std::cout << "#";
    }

    // Move to nextline after each row
    std::cout << '\n';
  }
}
