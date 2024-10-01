# tests.cmake [root]
# Handles test-specific configurations
FetchContent_Declare(GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2)

FetchContent_MakeAvailable(GoogleTest)

include(CTest)
enable_testing()

# Global test dependencies
set(TESTENVIRONMENTSGOOGLE gtest gtest_main)
set(TESTENVIRONMENTSFML sfml-graphics)

# Function to add a test executable for each library's tests
function(add_test_executable TESTNAME TESTSOURCES)
    add_executable(${TESTNAME} ${TESTSOURCES})
    target_link_libraries(${TESTNAME} PRIVATE ${ARGN})
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()

# TODO: Add integration tests