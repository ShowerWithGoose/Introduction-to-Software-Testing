cmake_minimum_required(VERSION 3.26)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)

# 将 Entry/Main.cpp 和 Lexer.cpp 作为主要的可执行文件
add_executable(Compiler Entry/Main.cpp Lexer.cpp Error.cpp)
