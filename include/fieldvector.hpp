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
     * @throws `std::out_of_range` error if the vector is empty.
     * @throws `std::out_of_range` error if the pointed at cell is out of bounds.
     */
    CellStructure& at(size_t row, size_t column) {}

    const size_t rows() {}
    const size_t columns() {}

  private:
    std::size_t rows_;
    std::size_t columns_;
    std::size_t mines_;
    std::vector<std::vector<CellStructure>> fieldGrid_;

    /**
     * @private
     * @return `bool`
     */
    const bool isEmpty() {}

    /**
     * @private
     * @return `bool`
     */
    const bool isInvalidIndex(size_t row, size_t column) {}
};

#endif  // FIELD_VECTOR_H_