cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(integrate)

file(GLOB SOURCES "src/*.cpp")

add_executable(integrate ${SOURCES})
