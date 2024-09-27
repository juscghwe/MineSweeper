cmake_minimum_required(VERSION 3.28)
project(MineSweeper LANGUAGES CXX)

# Set C++ compiler and compiler path
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SOURCES
    src/main.cpp
    src/fieldvector.cpp
    src/fieldgenerator.cpp
    # Add other source files as needed
)
add_executable(main ${SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)
set_target_properties(main PROPERTIES OUTPUT_NAME "MineSweeper")

# Clang-tidy
set(CMAKE_CXX_CLANG_TIDY "C:/msys64/ucrt64/bin/clang-tidy.exe;-checks=*,-clang-analyzer-alpha*")


if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()