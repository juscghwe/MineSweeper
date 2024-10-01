/**
 * @file fieldvector.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Defines the `FieldVector` class, representing a 2D grid of cells for the Minesweeper game.
 * @headerfile "include/cellstruct.hpp"
 */

#ifndef FIELD_VECTOR_H
#define FIELD_VECTOR_H

#include "utility/cellstruct.hpp"
#include <stdexcept>
#include <vector>

namespace MineSweeper {

/**
 * @class `FieldVector`
 * @brief Represents a 2D grid of cells in the Minesweeper game.
 */
class FieldVector
{
  public:
    /**
     * @brief Constructs a `FieldVector` with specified dimensions and number of mines.
     * @param rows `size_t` The number of rows in the grid.
     * @param columns `size_t` The number of columns in the grid.
     * @param mines `size_t` The number of mines in the grid.
     */
    FieldVector(const std::size_t rows, const std::size_t columns, const std::size_t mines);

    /**
     * @brief Accesses the cell at a specific grid position.
     * @param row `size_t` The row index of the cell.
     * @param column `size_t` The column index of the cell.
     * @return A reference to the `MineSweeper::CellStruct` at the specified position.
     * @throws `std::out_of_range` if the specified indices are out of bounds.
     */
    MineSweeper::CellStruct& at(size_t row, size_t column);

    /**
     * @brief Retrieves the number of rows in the grid.
     * @return `size_t` The number of rows in the grid.
     */
    size_t rows() const { return fieldGrid_.size(); };

    /**
     * @brief Retrieves the number of columns in the grid.
     * @return `size_t` The number of columns in the grid.
     */
    size_t columns() const { return fieldGrid_[0].size(); };

    /**
     * @brief Retrieves the entire field grid.
     * @return A `const std::vector<std::vector<MineSweeper::CellStruct>>&` representing the grid.
     */
    const std::vector<std::vector<MineSweeper::CellStruct>>& getFieldGrid() const { return fieldGrid_; }

  private:
    const std::size_t rows_;     ///< `size_t` The number of rows in the grid.
    const std::size_t columns_;  ///< `size_t` The number of columns in the grid.
    const std::size_t mines_;    ///< `size_t` The number of mines in the grid.
    std::vector<std::vector<MineSweeper::CellStruct>>
        fieldGrid_;  ///< `std::vector<std::vector<MineSweeper::CellStruct>>` The grid of cells.

    /**
     * @brief Validates if the specified indices are valid for the grid.
     * @param row `size_t` The row index to validate.
     * @param column `size_t` The column index to validate.
     * @return `bool` `true` if the indices are invalid; `false` otherwise.
     * @throws `std::out_of_range` if the specified indices are out of bounds.
     */
    bool isInvalidIndex(const size_t row, const size_t column) const;
};

};  // namespace MineSweeper

#endif  // FIELD_VECTOR_H