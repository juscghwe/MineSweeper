/**
 * @file fieldarray.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief This file declares the `FieldArray` class which manages the grid of cells in the Minesweeper game.
 */

#ifndef FIELD_ARRAY_H
#define FIELD_ARRAY_H

#include "gui/texturemanager.hpp"
#include "utility/fieldvector.hpp"
#include <memory>

namespace Gui {

/**
 * @class FieldArray
 * @brief Manages the layout and rendering of a grid of cells in the Minesweeper game.
 */
class FieldArray
{
  public:
    /**
     * @brief Constructs a `FieldArray` object to manage a Minesweeper grid.
     * @param kFieldVector `std::unique_ptr<Utility::FieldVector>&` A unique pointer to the logical representation of the Minesweeper grid.
     * @param textureManager `TextureManager&` Reference to the texture manager used to manage textures for the grid.
     */
    FieldArray(const std::unique_ptr<Utility::FieldVector>& kFieldVector, TextureManager& textureManager);

    /**
     * @brief Retrieves the dimensions of the window based on the grid size.
     * @return `const std::pair<int, int>` A pair containing the width (X) and height (Y) of the window.
     */
    const std::pair<int, int> getWindowSize() const { return std::pair<int, int>{kWindowX_, kWindowY_}; };

  private:
    const int kWindowX_;  ///< The width of the game window in pixels, based on grid columns and button size.
    const int kWindowY_;  ///< The height of the game window in pixels, based on grid rows and button size.
    const int kButtonX_;  ///< The width of a single button (cell) in pixels.
    const int kButtonY_;  ///< The height of a single button (cell) in pixels.
    const std::unique_ptr<Utility::FieldVector>&
        kFieldVector_;                ///< A unique pointer to the Minesweeper grid's logical data structure.
    TextureManager& textureManager_;  ///< Reference to the texture manager responsible for grid rendering.

    /**
     * @brief Initializes the grid of cells and sets up their visual positions.
     */
    void initializeGrid();
};

};  // namespace Gui

#endif