cmake_minimum_required(VERSION 3.21)
project(CP4)

set(CMAKE_CXX_STANDARD 14)

add_executable(CP4 CP4.cpp UserTree.cpp VoteHeap.cpp User.h)
target_compile_options(CP4 PRIVATE -Wall -Wextra -pedantic)