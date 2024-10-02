[comment]: <> (`libs/generator/readme.md`)
[comment]: <> (@author juscghwe https://github.com/juscghwe)
# FieldGenerator Library

## Overview
The `FieldGenerator` library is responsible for generating the Minesweeper game field, including placing mines and calculating adjacent mine counts for each cell.

## Features
- Generates a field with random mine placement
- Computes adjacent mine counts for each cell

## Usage
This library exposes a simple interface for generating a Minesweeper field with a specified number of rows, columns, and mines.

### Example
```cpp
#include "fieldgenerator/fieldgenerator.hpp"

FieldGenerator generator;
auto field = generator.generate(10, 10, 20); // Generates a 10x10 field with 20 mines
```

## Tests
Unit tests for this library are located in the `tests` directory. To run them, make sure the global `BUILD_TESTS` flag is set and execute the following command: 
```batch
ctest
```

## Notes
This library is a work in progress. Feedback is welcome, and contributions are encouraged as I use this project as a learning experience.