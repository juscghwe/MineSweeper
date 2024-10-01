/**
 * @file fieldvector.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Defines the `FieldVector` class, representing a 2D grid of cells for the Minesweeper game.
 * @headerfile "include/fieldvector.hpp"
 */

#include "fieldvector.hpp"

namespace MineSweeper {
FieldVector::FieldVector(const std::size_t rows, const std::size_t columns, const std::size_t mines)
    : rows_(rows), columns_(columns), mines_(mines)
{
    fieldGrid_.resize(rows, std::vector<MineSweeper::CellStruct>(columns));
}

MineSweeper::CellStruct& FieldVector::at(size_t row, size_t column)
{
    if (isInvalidIndex(row, column)) {
        throw std::out_of_range("Index out of bounds.\n");
    };
    return fieldGrid_[row][column];
}

// @private
bool FieldVector::isInvalidIndex(const size_t row, const size_t column) const
{
    return (row >= rows() || column >= columns());
}
}  // namespace MineSweeper