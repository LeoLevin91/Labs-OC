cmake_minimum_required(VERSION 3.13)
project(Cript_Ceasar)

set(CMAKE_CXX_STANDARD 14)

add_executable(SERVER.cpp CLIENT.cpp text_buff.cpp)