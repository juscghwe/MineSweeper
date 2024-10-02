[comment]: <> (`constants/readme.md`)
[comment]: <> (@author juscghwe https://github.com/juscghwe)
# Constants

This directory contains various constant definitions for the MineSweeper project. These constants are not intended to be a standalone library but should be included within the corresponding CMake files where necessary.

## Purpose

The constants provided here serve to:

- Maintain a centralized location for constant values used throughout the project.
- Provide compile-time consistency using `constexpr` where applicable.
- Facilitate the organization of project-specific values such as grid sizes, asset paths, or other game-specific parameters.

## Usage

To use these constants in your project, ensure that the appropriate `#include` directives are used within the source files that require them, and include the constants in the corresponding `CMakeLists.txt` files as needed.

For example, to include constants for the GUI component, add the relevant include path to your `CMakeLists.txt`:

```cmake
target_include_directories(gui 
    PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/constants>
)
```

## Notes
The constants in this directory are organized by category for clarity, such as GUI constants, field generation constants, and others.
Make sure to include only the necessary constant files to avoid unnecessary dependencies between different project components.
