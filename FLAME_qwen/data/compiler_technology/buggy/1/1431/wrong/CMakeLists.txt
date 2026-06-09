cmake_minimum_required(VERSION 3.10)

project(Compiler)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 定义项目名称和版本


# 添加可执行文件
add_executable(Compiler main.cpp fault.cpp cifa.cpp wenfa.cpp)

# 包含头文件目录（如果使用相对路径可以省略）
target_include_directories(Compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})