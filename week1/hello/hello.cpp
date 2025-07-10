#include <iostream>
#include <string>

int main(void) {
  std::string name;
  std::cout << "What's your name? ";
  std::getline(std::cin, name);
  std::cout << "Hello, " << name << '\n';
  return 0;
}