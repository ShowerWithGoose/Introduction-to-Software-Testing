cmake_minimum_required(VERSION 3.15)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compiler main.cpp ../InputBuffer/CInputBuffer.h ../LexicalAnalyzer/CLexicalAnalyzer.cpp ../LexicalAnalyzer/CLexicalAnalyzer.h ../Exceptions/LexicalError.h)