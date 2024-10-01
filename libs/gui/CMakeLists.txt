# CMakeLists.txt [libs_gui]
add_library(gui STATIC)

target_include_directories(gui
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake)
target_sources(gui PRIVATE ${SOURCES} ${HEADERS})

# Link SFML libraries to the gui target
target_link_libraries(gui PUBLIC sfml-graphics)

# Add tests if enabled globally
if(BUILD_TESTS)
    add_subdirectory(tests)
endif
