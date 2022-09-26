cmake_minimum_required(VERSION 3.0)

project(MySecondProg)

add_library(mysource STATIC isMotive.cpp)

add_executable(main main.cpp)

target_link_libraries(main mysource)