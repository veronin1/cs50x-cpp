cmake_minimum_required(VERSION 3.10)
project(cs50x_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -g -O0 -fsanitize=address,undefined")


# Week 1
add_executable(hello week1/hello/hello.cpp)
add_executable(mario-less week1/mario-less/mario-less.cpp)
add_executable(mario-more week1/mario-more/mario-more.cpp)
add_executable(cash week1/cash/cash.cpp)
add_executable(credit week1/credit/credit.cpp)

# Week 2
add_executable(scrabble week2/scrabble/scrabble.cpp)
add_executable(readability week2/readability/readability.cpp)
add_executable(caesar week2/caesar/caesar.cpp)