cmake_minimum_required(VERSION 3.0)

project(MyFirstProg)

add_library(mysource STATIC isPrime.cpp)

add_executable(main main.cpp)

target_link_libraries(main mysource)