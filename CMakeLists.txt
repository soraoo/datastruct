cmake_minimum_required(VERSION 3.17)
project(DataStruct)

set(CMAKE_CXX_STANDARD 14)

##添加头文件搜索路径
include_directories(include)

add_executable(DataStruct main.cpp include/tree/BinaryTree.hpp)