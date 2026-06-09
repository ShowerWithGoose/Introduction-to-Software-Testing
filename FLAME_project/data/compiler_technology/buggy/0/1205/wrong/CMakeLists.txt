cmake_minimum_required(VERSION 3.10)

project(Compiler)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

aux_source_directory(src SRC_LIST)

include_directories(include)

add_executable(Compiler ${SRC_LIST})