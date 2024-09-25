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

class FieldVector
{
  public:
    FieldVector(std::size_t rows, std::size_t columns, std::size_t mines);

    /**
     * @brief Get the entire cell at a specific point in the grid.
     * @param row `size_t` Row the cell is in.
     * @param col `size_t` Column the cell is in.
     * @return `CellStructure`
     * @throws `std::out_of_range` error if the pointed at cell is out of bounds.
     */
    CellStructure& at(size_t row, size_t column) {}

    /**
     * @brief Get number of rows in the grid.
     * @return `size_t`
     */
    size_t FieldVector::rows() const { return fieldGrid_.size(); }

    /**
     * @brief Get number of columns in the grid.
     * @return `size_t`
     */
    size_t FieldVector::columns() const { return fieldGrid_[0].size(); }

  private:
    std::size_t rows_;
    std::size_t columns_;
    std::size_t mines_;
    std::vector<std::vector<CellStructure>> fieldGrid_;

    /**
     * @private
     * @brief Validates validity of the pointer.
     * @return `bool`
     * @throws `std::out_of_range` error if the pointed at cell is out of bounds.
     */
    bool isInvalidIndex(size_t row, size_t column) const {}
};

#endif  // FIELD_VECTOR_H_