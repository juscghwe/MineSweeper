# CMakeLists.txt
set(PROJECT_NAME
    MineSweeper)

# root
cmake_minimum_required(VERSION 3.28)
project(MineSweeper LANGUAGES CXX)

# Set C++ compiler and compiler path
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Include
include(cmake/dependencies.cmake)
include(cmake/build_settings.cmake)
include(cmake/tests.cmake)

# Clang-tidy
set(CMAKE_CXX_CLANG_TIDY "C:/msys64/ucrt64/bin/clang-tidy.exe;-checks=*,-clang-analyzer-alpha*")