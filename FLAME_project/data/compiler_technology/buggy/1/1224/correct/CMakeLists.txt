cmake_minimum_required(VERSION 3.28.3)

project(Compiler)

# 指定源文件路径
file(GLOB SOURCES src/*.cpp)
# 添加可执行文件
add_executable(Compiler ${SOURCES})

