# CMakeLists.txt [libs_generator]
add_library(generator STATIC)

target_include_directories(generator
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake)
target_sources(generator PRIVATE ${SOURCES} ${HEADERS})

# Link utility library
target_link_libraries(generator PRIVATE utility)

# Add tests if enabled globally
if(BUILD_TESTS)
    add_subdirectory(tests)
endif
