cmake_minimum_required(VERSION 3.28.3)
project(Compiler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Compiler main.cpp
        analysis/lexer.h
        analysis/lexer.cpp
        items/token.h
        items/token.cpp
        items/AST/node.cpp
        items/AST/node.h
        items/Grammar.cpp
        items/Grammar.h
        analysis/parser.cpp
        analysis/parser.h
        items/error/error.cpp
        items/error/error.h
        items/error/errorList.cpp
        items/error/errorList.h
)
target_include_directories(Compiler PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/items  # 添加 items 目录
)