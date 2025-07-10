cmake_minimum_required(VERSION 3.10)
project(cs50x_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -g -O0 -fsanitize=address,undefined")


# Week 1
add_executable(hello src/week1/hello/hello.cpp)
add_executable(mario-less src/week1/mario-less/mario-less.cpp)
add_executable(mario-more src/week1/mario-more/mario-more.cpp)
add_executable(cash src/week1/cash/cash.cpp)
add_executable(credit src/week1/credit/credit.cpp)

# Week 2
add_executable(scrabble src/week2/scrabble/scrabble.cpp)
add_executable(readability src/week2/readability/readability.cpp)
add_executable(caesar src/week2/caesar/caesar.cpp)

# Week 3
add_executable(sort src/week3/sort/sort.cpp)
