cmake_minimum_required(VERSION 3.28)
project(Myst4)

set(PROJECT_OUT_DIR ${CMAKE_BINARY_DIR}/game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUT_DIR})

add_subdirectory(src)
