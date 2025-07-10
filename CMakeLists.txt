cmake_minimum_required(VERSION 3.10)
project(cs50x_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -g -O0 -fsanitize=address,undefined")


# Week 1
add_subdirectory(week1/hello)
add_subdirectory(week1/mario-less)
add_subdirectory(week1/mario-more)
add_subdirectory(week1/cash)
add_subdirectory(week1/credit)

# Week 2
add_subdirectory(week2/scrabble)
add_subdirectory(week2/readability)
add_subdirectory(week2/caesar)