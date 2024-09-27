/**
 * @file cellstruct.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#ifndef CELL_STRUCTURE_H
#define CELL_STRUCTURE_H

#include <cstddef>

namespace MineSweeper {
struct CellStructure {
    bool isMine = false;            // Cell is a mine
    bool isCovered = true;          // Cell is not uncovered by the user (default = true)
    bool isFlagged = false;         // Cell got flagged by the user (default = false)
    std::size_t adjecentMines = 0;  // Cells next to the cell that are mines
};
}  // namespace MineSweeper

#endif  // CELL_STRUCTURE_H_