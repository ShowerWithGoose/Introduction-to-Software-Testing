cmake_minimum_required(VERSION 3.28.3)
project(Compiler)

set(C/C++ clang 12.0.0 C++17)

include_directories(Error_Part)
add_executable(Compiler Compiler.cpp
        Lexer_Part/LineReader.cpp
        Error_Part/ErrorCollector.cpp
        Lexer_Part/Lexer.cpp
        Lexer_Part/Token.cpp)