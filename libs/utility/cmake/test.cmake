# tests.cmake [libs_utility]
# Handles test-specific configurations

set(TESTNAME tests_utility)

set(TESTSOURCES
    tests/test_cellstruct.cpp
    tests/test_fieldvector.cpp
    tests/test_positionstruct.cpp
)

add_test_executable(${TESTNAME} "${TESTSOURCES}" ${TESTENVIRONMENTSGOOGLE} utility)
