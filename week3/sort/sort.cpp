/* This was originally a task wherein the student had to run 3 binary files and
 * determine what sort they were running as they were acting on different types
 * of data (sorted list of 50000 elements, unsorted list of 1000 elements etc).
 * The 3 possible sorts were: Bubble, Selection and Merge */

#include <chrono>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

void bubbleSort(std::vector<int> &dataVect);
void selectionSort(std::vector<int> &dataVect);
void mergeSort(std::vector<int> &dataVect);

int main(int argc, char *argv[]) {
  size_t num;

  std::ifstream data(argv[1]);

  std::vector<int> dataVect;

  while (data >> num) {
    dataVect.push_back((num));
  }

  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point end;
  std::chrono::duration<double> diff = end - start;

  // Bubble Sort Timing
  start = std::chrono::high_resolution_clock::now();
  bubbleSort(dataVect);
  end = std::chrono::high_resolution_clock::now();
  diff = end - start;

  std::cout << "Results for Bubble Sort: " << diff.count() << " seconds\n";

  // Selection Sort Timing
  start = std::chrono::high_resolution_clock::now();
  selectionSort(dataVect);
  end = std::chrono::high_resolution_clock::now();
  diff = end - start;
  std::cout << "Results for Selection Sort: " << diff.count() << " seconds\n";

  // Merge Sort Timing
  start = std::chrono::high_resolution_clock::now();
  mergeSort(dataVect);
  end = std::chrono::high_resolution_clock::now();
  diff = end - start;

  std::cout << "Results for Merge Sort: " << diff.count() << " seconds\n";

  /*
for (int i = 0, n = dataVect.size(); i < n; i++) {
std::cout << dataVect[i] << std::endl;
}
*/
}

void bubbleSort(std::vector<int> &dataVect) {
  int swapCounter = -1;
  while (swapCounter != 0) {
    swapCounter = 0;

    for (int i = 0, n = dataVect.size() - 1; i < n; i++) {
      if (dataVect[i] > dataVect[i + 1]) {
        int tmp;
        tmp = dataVect[i + 1];
        dataVect[i + 1] = dataVect[i];
        dataVect[i] = tmp;
        ++swapCounter;
      }
    }
  }
}

void selectionSort(std::vector<int> &dataVect) {
  int smallestValue = dataVect[0];
  int n = dataVect.size() - 1;
  int index = 0;

  // find smallest value
  for (int i = 0; i < n; i++) {
    if (dataVect[i] < smallestValue) {
      smallestValue = dataVect[i];
      index = i;
    }

    int tmp = dataVect[index];
    dataVect[index] = dataVect[i];
    dataVect[i] = tmp;
  }
}

void mergeSort(std::vector<int> &dataVect) {}