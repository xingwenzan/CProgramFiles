cmake_minimum_required(VERSION 3.24)
project(AlgorithmC C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmC main.c )

link_libraries(libeasyx.a)

