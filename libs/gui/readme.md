[comment]: <> (`libs/gui/readme.md`)
[comment]: <> (@author juscghwe https://github.com/juscghwe)
# GUI Library

## Overview
The `GUI` library handles the graphical user interface for the Minesweeper game, including rendering the game board, tiles, and handling user interactions.

## Features
- Loads and manages textures for tiles (numbers, flags, mines, etc.)
- Renders the game board in a grid format
- Handles mouse input for tile selection and interaction

## Usage
The GUI library integrates with SFML to handle rendering and user interactions. Make sure SFML is properly linked and included in your project.

### Example
```cpp
#include "gui/texturemanager.hpp"
#include "gui/gamewindow.hpp" // TODO: Not yet implemented

// Initialize and load textures
TextureManager::getInstance().loadTextures("assets/tileset.png");

// Render the window
GameWindow window;
window.run();
```

## Tests
Unit tests for the GUI components are under development. Check the `tests` directory for progress on GUI-related tests. To run them, ensure `BUILD_TESTS` is enabled and execute:
```bash
ctest
```

## Notes
The GUI library is still under construction. Any feedback or suggestions are welcome. This library is part of my learning process, and I am continuously improving it.