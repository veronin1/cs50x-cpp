/* This was originally a task wherein the student had to run 3 binary files and
 * determine what sort they were running as they were acting on different types
 * of data (sorted list of 50000 elements, unsorted list of 1000 elements etc).
 * The 3 possible sorts were: Bubble, Selection and Merge */

#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  size_t num;

  std::ifstream data(argv[1]);

  std::vector<int> dataVect;

  while (data >> num) {
    dataVect.push_back((num));
  }
}

void bubbleSort(std::pmr::vector<int> &dataVect) { return; }

void selectionSort() {}

void mergeSort() {}