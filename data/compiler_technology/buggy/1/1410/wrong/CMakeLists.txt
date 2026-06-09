cmake_minimum_required(VERSION 3.26)
project(Compiler C)

set(CMAKE_C_STANDARD 99)

add_executable(Compiler wordanalyze.c
        main.c
        wordanalyze.h
        main.h
)
