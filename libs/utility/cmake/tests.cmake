# tests.cmake [libs_utility]
# Handles test-specific configurations

set(TESTNAME tests_utility)

set(TESTSOURCES
    tests/test_cellstruct.cpp
    tests/test_fieldvector.cpp
    tests/test_positionstruct.cpp
)

include(${CMAKE_SOURCE_DIR}/cmake/functions.cmake)

add_test_executable(${TESTNAME} "${TESTSOURCES}" gtest gtest_main utility)

target_include_directories(${TESTNAME} 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include)