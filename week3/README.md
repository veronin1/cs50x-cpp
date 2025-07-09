# Sorting

This program runs Bubble Sort, Selection Sort and Merge Sort

## How to Compile

For optimal performance, I highly recommend compiling this program using the following g++ flags:

```sh
g++ -O3 -march=native -flto -o sort sort.cpp
```

These flags enable aggressive optimizations that can significantly improve execution speed. For example, compiling with these flags versus a simple g++ sort.cpp resulted in the following performance gains:

| Sorting Algorithm  | Simple Compilation Avg (`g++ sort.cpp`) | Optimized Compilation Avg (`g++ -O3 sort.cpp`) | Speedup       |
| ------------------ | --------------------------------------- | ---------------------------------------------- | ------------- |
| **Bubble Sort**    | 16.7197 seconds                         | 3.81841 seconds                                | 4.38× faster  |
| **Selection Sort** | 5.91171 seconds                         | 0.31962 seconds                                | 18.50× faster |
| **Merge Sort**     | 0.0388661 seconds                       | 0.00524334 seconds                             | 7.41× faster  |

## Usage

Run the program with a data file as input, for example:

```sh
./sort data/random50000.txt
```
