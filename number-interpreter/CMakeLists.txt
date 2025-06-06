cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file (GLOB_RECURSE SOURCES "source/*.cpp")
add_library(number-interpreter SHARED ${SOURCES})

target_include_directories(number-interpreter PUBLIC include)
