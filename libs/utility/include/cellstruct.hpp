/**
 * @file cellstruct.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Defines the `CellStruct` for the Minesweeper game, representing the state of a cell in the minefield.
 */

#ifndef CELL_STRUCTURE_H
#define CELL_STRUCTURE_H

#include <cstddef>

namespace MineSweeper {

/**
 * @struct CellStruct
 * @brief Represents the state of a cell in the Minesweeper game.
 */
struct CellStruct {
    bool isMine = false;            ///< `bool` Indicates if the cell is a mine (`default = false`).
    bool isCovered = true;          ///< `bool` Indicates if the cell is covered by the user (`default = true`).
    bool isFlagged = false;         ///< `bool` Indicates if the cell has been flagged by the user (`default = false`).
    std::size_t adjecentMines = 0;  ///< `std::size_t` Count of adjacent mines around the cell (`default = 0`).
};

}  // namespace MineSweeper

#endif  // CELL_STRUCTURE_H