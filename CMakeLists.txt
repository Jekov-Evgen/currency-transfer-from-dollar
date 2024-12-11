cmake_minimum_required(VERSION 3.31.2)
project(transferFromDollar)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/header)
include_directories(${CMAKE_SOURCE_DIR}/lib/include)

add_executable(transferFromDollar main.cpp src/command.cpp)