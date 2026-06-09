cmake_minimum_required(VERSION 3.15)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Compiler
        main.cpp
        error.cpp
        lexer.cpp
        parser.cpp)
