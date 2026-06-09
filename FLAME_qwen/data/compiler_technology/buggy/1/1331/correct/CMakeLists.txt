cmake_minimum_required(VERSION 3.26)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compiler Main.cpp Lexer/Lexer.cpp Error/Error.cpp Parser/Parser.cpp Tool/Exp.cpp Tool/Word.cpp Parser/AST.cpp)

target_include_directories(Compiler PRIVATE include)
