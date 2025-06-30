#include <iostream>

int get_height(void);
void print_pyramid(int n);

int main() {
  const int n = get_height();
  print_pyramid(n);
}

int get_height(void) {
  int n;
  do {
    std::cout << "Height: ";
    std::cin >> n;
  } while (n < 1 || n > 8);
  return n;
}

void print_pyramid(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n; j > i + 1; j--) {
      std::cout << " ";
    }
    for (int k = 0; k < i - 1; k++) {
      std::cout << "#";
    }
    std::cout << "\n";
  }
}