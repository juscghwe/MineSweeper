# tests.cmake [libs_generator]
set(TESTNAME tests_generator)

set(TESTSOURCES
    tests/test_fieldgenerator.cpp
)

include(${CMAKE_SOURCE_DIR}/cmake/functions.cmake)

add_test_executable(${TESTNAME} "${TESTSOURCES}" gtest gtest_main utility generator)

target_include_directories(${TESTNAME} 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/constants)