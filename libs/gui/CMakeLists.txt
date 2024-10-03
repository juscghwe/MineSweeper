# CMakeLists.txt [libs_gui]
add_library(gui STATIC)

target_include_directories(gui
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/constants>
)

message("Include paths for gui: ${CMAKE_SOURCE_DIR}/constants")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake)
target_sources(gui PRIVATE ${SOURCES} ${HEADERS})

# Link SFML libraries to the gui target
target_link_libraries(gui PUBLIC sfml-graphics utility)

# Add tests if enabled globally
if(BUILD_TESTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/tests.cmake)
endif()