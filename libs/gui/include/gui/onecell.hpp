/**
 * @file onecell.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief This file declares the `OneCell` class which represents a single cell in the Minesweeper grid.
 */

#ifndef ONE_CELL_H
#define ONE_CELL_H

#include "gui/texturemanager.hpp"
#include "utility/cellstruct.hpp"
#include <SFML/Graphics.hpp>

namespace Gui {

/**
 * @struct PixelStruct
 * @brief A simple structure holding the X and Y pixel positions for the cell.
 */
struct PixelStruct {
    int X;  ///< X position of the cell in pixels
    int Y;  ///< Y position of the cell in pixels
};

/**
 * @class OneCell
 * @brief Represents a single cell in the Minesweeper game grid, managing its state and visual representation.
 */
class OneCell
{
  public:
    /**
     * @brief Constructs a `OneCell` object.
     * @param cellStruct `Utility::CellStruct` The structural data of the cell (covered, flagged, adjacent mines, etc.).
     * @param kPosition `PixelStruct` The pixel position of the cell on the screen.
     * @param textureManager `TextureManager&` Reference to the texture manager responsible for managing cell textures.
     */
    OneCell(Utility::CellStruct cellStruct, const PixelStruct kPosition, TextureManager& textureManager);

    /**
     * @brief Marks the cell as clicked, changing its internal state and updating its visual representation.
     */
    void gotClicked();

    /**
     * @brief Marks the cell as flagged, changing its internal state and updating its visual representation.
     */
    void gotFlagged();

  private:
    sf::Sprite sprite_;               ///< The sprite representing the cell's texture.
    Utility::CellStruct cellStruct_;  ///< Data structure containing the cell's logical state.
    const PixelStruct kPosition_;     ///< The pixel position of the cell.
    PixelStruct kScale_;              ///< The sprite size of the cell.
    TextureManager& textureManager_;  ///< Reference to the texture manager.

    /**
     * @brief Retrieves the state of the cell from its structure.
     * @return `const std::pair<Constants::GuiConstants::CellState, int>` A pair containing the cell's visual state and the number of adjacent mines.
     */
    const std::pair<Constants::GuiConstants::CellState, int> getStateFromStruct();

    /**
     * @brief Redraws the cell by updating its sprite texture according to its current state.
     */
    void redraw();
};

};  // namespace Gui

#endif  // ONE_CELL_H