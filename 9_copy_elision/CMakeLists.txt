cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(9_copy_elision main.cpp)

target_compile_options(9_copy_elision PRIVATE -fno-elide-constructors)
