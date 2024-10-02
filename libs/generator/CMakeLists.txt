# CMakeLists.txt [libs_generator]

add_library(generator STATIC)

target_include_directories(generator
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/constants>
)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/sources.cmake)
target_sources(generator PRIVATE ${SOURCES} ${HEADERS})

# Link utility library to the gui target
target_link_libraries(generator PRIVATE utility)

# Add tests if enabled globally
if(BUILD_TESTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/tests.cmake)
endif()