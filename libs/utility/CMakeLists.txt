# CMakeLists.txt [libs_utility]
add_library(utility INTERFACE)

target_include_directories(utility
    INTERFACE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Not necessary as header only
#include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake)
#target_sources(utility PRIVATE ${SOURCES})

# Add tests if enabled globally
if(BUILD_TESTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/tests.cmake)
endif()