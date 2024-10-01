# tests.cmake [libs_generator]
set(TESTNAME tests_generator)

set(TESTSOURCES
    tests/test_fieldgenerator.cpp
)

add_test_executable(${TESTNAME} "${TESTSOURCES}" ${TESTENVIRONMENTSGOOGLE} ${TESTENVIRONMENTSSMFL} utility)
