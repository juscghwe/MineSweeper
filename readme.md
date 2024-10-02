# CMake logic

```batch
project_root/
│
├── CMakeLists.txt             # Main CMake file at the root
├── cmake/                     # Folder for CMake utilities and split logic
│   ├── tests.cmake            # Handles test-specific configurations
│   ├── dependencies.cmake     # Handles external dependencies
│   ├── build_settings.cmake   # Handles custom build settings (e.g., warnings, flags)
│   └── functions.cmake        # Utility functions for reuse across libs/tests
├── libs/
│   ├── generator/
│   │   ├── CMakeLists.txt     # Library-specific CMake file
│   │   └── cmake/
│   │       ├── source.cmake   # Sources for the generator lib
│   │       └── dependencies.cmake  # Dependencies for the generator lib
│   ├── gui/
│   │   ├── CMakeLists.txt     # Same structure for GUI library
│   │   └── cmake/
│   │       └── source.cmake   # Sources for the GUI lib
└── tests/
    ├── CMakeLists.txt         # Unit test configuration
    └── cmake/
        └── test_sources.cmake # Test source files for the entire project
```