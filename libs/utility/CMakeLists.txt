# CMakeLists.txt [libs_utility]
add_library(utility STATIC)

target_include_directories(utility
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake)
target_sources(utility PRIVATE ${SOURCES})

# Add tests if enabled globally
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()