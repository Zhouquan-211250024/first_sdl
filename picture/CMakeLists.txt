cmake_minimum_required(VERSION 3.21)
project(picture C)

set(CMAKE_C_STANDARD 11)
link_libraries(SDL2)
add_executable(picture main.c)
