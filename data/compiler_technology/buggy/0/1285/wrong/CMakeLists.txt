cmake_minimum_required(VERSION 3.10)  # 指定最低版本
project(Compiler)                      # 设置项目名称为 Compiler

# 设置 C++ 标准，可以选择 C++11, C++14, C++17, C++20 等
set(CMAKE_CXX_STANDARD 17)            # 指定 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # 确保使用指定的 C++ 标准

# 添加可执行文件
add_executable(Compiler lexer.cpp)     # 设置输出的可执行文件名称为 Compiler