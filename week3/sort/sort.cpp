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

void bubbleSort(std::vector<int> &dataVect) {
  int swapCounter = -1;
  while (swapCounter != 0) {
    swapCounter = 0;

    for (int i = 0, n = dataVect.size() - 1; i < n; i++) {
      if (dataVect[i] > dataVect[i + 1]) {
        int tmp;
        tmp = dataVect[i];
        dataVect[i + 1] = dataVect[i];
        dataVect[i] = tmp;
        ++swapCounter;
      }
    }
  }
}

void selectionSort() {}

void mergeSort() {}