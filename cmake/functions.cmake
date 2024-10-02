# functions.cmake [root]

# Function to add a test executable for each library's tests
function(add_test_executable TESTNAME TESTSOURCES)
    add_executable(${TESTNAME} ${TESTSOURCES})
    target_link_libraries(${TESTNAME} PRIVATE ${ARGN})
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()