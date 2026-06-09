cmake_minimum_required(VERSION 3.16)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)	

include_directories(include/frontend)

aux_source_directory(src/frontend SRC_FRONTEND)

add_executable(Compiler src/main.cpp ${SRC_FRONTEND})	