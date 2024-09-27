/**
 * @file fieldvector.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @headerfile "include/cellstruct.hpp"
 */

#ifndef FIELD_VECTOR_H
#define FIELD_VECTOR_H

#include "cellstruct.hpp"
#include <stdexcept>
#include <vector>

namespace MineSweeper {
class FieldVector
{
  public:
    FieldVector(const std::size_t rows, const std::size_t columns, const std::size_t mines);

    /**
     * @brief Get the entire cell at a specific point in the grid.
     * @param row `size_t` Row the cell is in.
     * @param col `size_t` Column the cell is in.
     * @return `CellStructure`
     * @throws `std::out_of_range` error if the pointed at cell is out of bounds.
     */
    MineSweeper::CellStructure& at(size_t row, size_t column);

    /**
     * @brief Get number of rows in the grid.
     * @return `size_t`
     */
    size_t rows() const;

    /**
     * @brief Get number of columns in the grid.
     * @return `size_t`
     */
    size_t columns() const;

    const std::vector<std::vector<MineSweeper::CellStructure>>& getFieldGrid() const
    {
        return fieldGrid_;
    }

  private:
    const std::size_t rows_;
    const std::size_t columns_;
    const std::size_t mines_;
    std::vector<std::vector<MineSweeper::CellStructure>> fieldGrid_;

    /**
     * @private
     * @brief Validates validity of the pointer.
     * @return `bool`
     * @throws `std::out_of_range` error if the pointed at cell is out of bounds.
     */
    bool isInvalidIndex(const size_t row, const size_t column) const;
};
};  // namespace MineSweeper

#endif  // FIELD_VECTOR_H_