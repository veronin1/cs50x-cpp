# CS50x C++ Translations

This repo contains my translations of CS50x C projects into C++. The goal is to redo the assignments using C++ features where it makes sense, while keeping the original logic intact - this is to deepen my understanding and learning of C++.

## Structure

- `src/week1/`, `src/week2/`, etc. — folders with projects grouped by week
- Each folder contains `.cpp` files for translated assignments

## Building with CMake

This project uses CMake to build all the assignments. The executables are generated inside the build/ folder.

```sh
mkdir -p build
cd build
cmake ..
make readability # will only compile the readability problem
make # will compile all projects
```

## Running the programs

After building, executables will be located in the `build/` folder which can be run as follows:

```sh
./hello
./mario-less
./sort data/x.txt
```

## Input data files

Some programs (like sort) expect input files located under the source directory i.e. the data in the sort problem set is located under the sort directory.

```sh
src/week3/sort/data/x.txt
```

Make sure to provide the full path considering the position of the build folder:

```sh
./sort ../src/week3/sort/data/random50000.txt
```

## Building without CMake

Files can still be compiled manually via the compiler of your choosing

```sh
g++ week1/mario-less.cpp -o mario-less
./mario-less
```
