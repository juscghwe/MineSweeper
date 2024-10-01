# tests.cmake
# Handles test-specific configurations
FetchContent_Declare(GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2)

FetchContent_MakeAvailable(GoogleTest)

include(CTest)
enable_testing()

# Global test dependencies
set(TESTENVIRONMENTSGOOGLE
    gtest 
    gtest_main 
)
set(TESTENVIRONMENTSFML
    sfml-graphics
)

# TODO: Add integration tests