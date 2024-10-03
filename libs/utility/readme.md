[comment]: <> (`libs/utility/readme.md`)
[comment]: <> (@author juscghwe https://github.com/juscghwe)
# Utility Library

The `Utility` library provides common data structures and helper functions used throughout the Minesweeper project. It includes classes like `FieldVector` and `CellStruct` for managing the game's internal state.

## Features
- `FieldVector`: A 2D grid for managing the game state
- `CellStruct`: Represents individual cells in the Minesweeper field
- Utility functions for validating and managing grid data

## Usage
The `Utility` library is header-only and can be included directly in your project.

### Example
```cpp
#include "utility/fieldvector.hpp"

FieldVector field(10, 10, 20); // Creates a 10x10 grid with 20 mines
field.at(0, 0); // Accesses the top-left cell
```

## Tests
Unit tests for the `Utility` library are available in the `tests` directory. To run them, ensure `BUILD_TESTS` is enabled and execute:
```bash
ctest
```

## Notes
This library is header-only and designed for ease of integration. Any feedback on code structure and improvements is greatly appreciated.