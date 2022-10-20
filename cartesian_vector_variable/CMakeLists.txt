cmake_minimum_required(VERSION 3.0)

project(MyThirdProg)
set(CMAKE_CXX_STANDARD 17)

add_library(mysource STATIC vector.cpp)

add_executable(main main.cc)

target_link_libraries(main mysource)