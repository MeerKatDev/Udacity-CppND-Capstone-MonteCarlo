cmake_minimum_required(VERSION 3.7)
project(integrate)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")


include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(integrate ${SOURCES})
