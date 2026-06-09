cmake_minimum_required(VERSION 3.20)

# 设置项目名称和版本
project(Compiler VERSION 1.0)

# 添加可执行文件
add_executable(Compiler main.cpp
        outputTools.cpp)

# 如果有其他源文件，添加它们)
target_sources(Compiler PRIVATE components.cpp)

# 包含头文件目录
target_include_directories(Compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
