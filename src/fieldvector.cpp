/**
 * @file fieldvector.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @headerfile "include/fieldvector.hpp"
 */

#include "fieldvector.hpp"

namespace MineSweeper {
FieldVector::FieldVector(const std::size_t rows, const std::size_t columns, const std::size_t mines)
    : rows_(rows), columns_(columns), mines_(mines)
{
    fieldGrid_.resize(rows, std::vector<MineSweeper::CellStructure>(columns));
}

MineSweeper::CellStructure& FieldVector::at(size_t row, size_t column)
{
    if (isInvalidIndex(row, column)) {
        throw std::out_of_range("Index out of bounds.\n");
    };
    return fieldGrid_[row][column];
}

const size_t FieldVector::rows() const
{
    return fieldGrid_.size();
}

const size_t FieldVector::columns() const
{
    return fieldGrid_[0].size();
}

// @private
const bool FieldVector::isInvalidIndex(const size_t row, const size_t column) const
{
    return (row >= rows() || column >= columns());
}
}  // namespace MineSweeper