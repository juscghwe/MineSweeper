# tests.cmake [libs_gui]
set(TESTNAME tests_gui)

set(TESTSOURCES
    tests/test_texturemanager.cpp
)

add_test_executable(${TESTNAME} "${TESTSOURCES}" ${TESTENVIRONMENTSGOOGLE} ${TESTENVIRONMENTSSMFL})
