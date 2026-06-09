cmake_minimum_required(VERSION 3.26)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compiler main.cpp
        lexer_def.h
        lexer_func.h
        source_program.h
        global_settings.h)
