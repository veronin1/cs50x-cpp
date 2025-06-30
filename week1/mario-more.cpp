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
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

  } while (n < 1 || n > 8);

  return n;
}

void print_pyramid(int height) {
  int n = height;
  for (int i = 0; i < n; i++) {
    for (int j = n; j > i + 1; j--) {
      std::cout << " ";
    }
    for (int k = 0; k < i + 1; k++) {
      std::cout << "#";
    }

    std::cout << "  ";

    for (int l = 0; l < i + 1; l++) {
      std::cout << "#";
    }
    std::cout << '\n';
  }
}
