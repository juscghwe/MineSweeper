# dependencies.cmake [root]
# Handles external dependencies
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)

FetchContent_MakeAvailable(SFML)

if(BUILD_TESTS)
    FetchContent_Declare(GoogleTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2)

    FetchContent_MakeAvailable(GoogleTest)
endif()