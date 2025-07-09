/* This was originally a task wherein the student had to run 3 binary files and
 * determine what sort they were running as they were acting on different types
 * of data (sorted list of 50000 elements, unsorted list of 1000 elements etc).
 * The 3 possible sorts were: Bubble, Selection and Merge */

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

void bubbleSort(std::vector<int> &dataVect);
void selectionSort(std::vector<int> &dataVect);
void mergeSort(std::vector<int> &dataVect);
void merge(std::vector<int> &left, std::vector<int> &right,
           std::vector<int> &dataVect);

int main(int argc, char *argv[]) {
  size_t num;

  std::ifstream data(argv[1]);
  std::vector<int> originalData;

  while (data >> num) {
    originalData.push_back(num);
  }

  std::vector<int> dataVect;
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point end;
  std::chrono::duration<double> diff = end - start;

  // Bubble Sort Timing
  dataVect = originalData;
  start = std::chrono::high_resolution_clock::now();
  bubbleSort(dataVect);
  end = std::chrono::high_resolution_clock::now();
  diff = end - start;
  std::cout << "Results for Bubble Sort: " << diff.count() << " seconds\n";

  // Selection Sort Timing
  dataVect = originalData;
  start = std::chrono::high_resolution_clock::now();
  selectionSort(dataVect);
  end = std::chrono::high_resolution_clock::now();
  diff = end - start;
  std::cout << "Results for Selection Sort: " << diff.count() << " seconds\n";

  // Merge Sort Timing
  dataVect = originalData;
  start = std::chrono::high_resolution_clock::now();
  mergeSort(dataVect);
  end = std::chrono::high_resolution_clock::now();
  diff = end - start;
  std::cout << "Results for Merge Sort: " << diff.count() << " seconds\n";

  return 0;
}

void bubbleSort(std::vector<int> &dataVect) {
  bool swapped = true;
  while (swapped) {
    swapped = false;

    for (int i = 0, n = dataVect.size() - 1; i < n; i++) {
      if (dataVect[i] > dataVect[i + 1]) {
        std::swap(dataVect[i + 1], dataVect[i]);
        swapped = true;
      }
    }
  }
}

void selectionSort(std::vector<int> &dataVect) {
  int smallestValue = dataVect[0];
  int n = dataVect.size();

  for (int i = 0; i < n - 1; i++) {
    int index = i;
    for (int j = i + 1; j < n; j++) {
      if (dataVect[j] < dataVect[index]) {
        index = j;
      }
    }

    std::swap(dataVect[index], dataVect[i]);
  }
}

void mergeSort(std::vector<int> &dataVect) {
  if (dataVect.size() <= 1) {
    return;
  }
  int split = dataVect.size() / 2;
  std::vector<int> left(split);
  std::vector<int> right(dataVect.size() - split);

  for (int i = 0; i < split; i++) {
    left[i] = dataVect[i];
  }
  for (int i = split, n = dataVect.size(); i < n; i++) {
    right[i - split] = dataVect[i];
  }

  mergeSort(left);
  mergeSort(right);

  merge(left, right, dataVect);
}

void merge(std::vector<int> &left, std::vector<int> &right,
           std::vector<int> &dataVect) {
  std::vector<int> merged;
  int i = 0, j = 0;

  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      merged.push_back(left[i++]);
    } else {
      merged.push_back(right[j++]);
    }
  }

  while (i < left.size()) {
    merged.push_back((left[i++]));
  }
  while (j < right.size()) {
    merged.push_back((right[j++]));
  }

  for (int k = 0; k < merged.size(); k++) {
    dataVect[k] = merged[k];
  }
}