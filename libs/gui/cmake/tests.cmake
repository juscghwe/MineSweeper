# tests.cmake [libs_gui]
set(TESTNAME tests_gui)

set(TESTSOURCES
    tests/test_texturemanager.cpp
)

include(${CMAKE_SOURCE_DIR}/cmake/functions.cmake)

add_test_executable(${TESTNAME} "${TESTSOURCES}" gtest gtest_main sfml-graphics gui)

target_include_directories(${TESTNAME} 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/constants)