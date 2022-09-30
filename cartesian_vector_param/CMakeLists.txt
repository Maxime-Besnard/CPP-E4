cmake_minimum_required(VERSION 3.0)

project(MyThirdProg)

add_library(mysource STATIC vector.cpp)

add_executable(main main.cc)

target_link_libraries(main mysource)