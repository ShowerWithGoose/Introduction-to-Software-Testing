cmake_minimum_required(VERSION 3.28)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compiler main.cpp
        Token.h
        Token.cpp
        CommentRemover.h
        CommentRemover.cpp
        Error.h
        Error.cpp
        Lexer.h
        Lexer.cpp
        Parser.h
        Parser.cpp
)
