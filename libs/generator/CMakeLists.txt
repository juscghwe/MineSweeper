# CMakeLists.txt [libs_generator]
add_library(generator STATIC)

target_include_directories(generator
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/constants
)

target_link_libraries(gui PUBLIC utility)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake)
target_sources(generator PRIVATE ${SOURCES} ${HEADERS})

# Add tests if enabled globally
if(BUILD_TESTS)
    add_subdirectory(tests)
endif
