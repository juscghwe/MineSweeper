# CMakeLists.txt [root]
set(PROJECT_NAME MineSweeper)

# root
cmake_minimum_required(VERSION 3.28)
project(MineSweeper LANGUAGES CXX)

# Set C++ compiler and compiler path
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

option(BUILD_TESTS "Enable building of tests" ON)

if(BUILD_TESTS)
    enable_testing()
endif()

# Add libraries
add_subdirectory(libs/generator)
add_subdirectory(libs/gui)
add_subdirectory(libs/utility)

# Build
add_executable(${PROJECT_NAME} src/main.cpp)

# Include
include(cmake/dependencies.cmake)
include(cmake/build_settings.cmake)
if(BUILD_TESTS)
    include(cmake/tests.cmake)
endif()

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics generator gui utility)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)

# Clang-tidy
set(CMAKE_CXX_CLANG_TIDY "C:/msys64/ucrt64/bin/clang-tidy.exe;-checks=*,-clang-analyzer-alpha*")