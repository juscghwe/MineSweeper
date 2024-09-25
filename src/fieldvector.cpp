/**
 * @file fieldvector.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @headerfile "include/fieldvector.hpp"
 */

#include "fieldvector.hpp"

FieldVector::FieldVector(std::size_t rows, std::size_t columns, std::size_t mines)
    : rows_(rows), columns_(columns), mines_(mines)
{
    fieldGrid_.resize(rows, std::vector<CellStructure>(columns));
}

CellStructure& FieldVector::at(size_t row, size_t column)
{
    isInvalidIndex(row, column);
    return fieldGrid_[row][column];
}

size_t FieldVector::rows() const
{
    return fieldGrid_.size();
}

size_t FieldVector::columns() const
{
    return fieldGrid_[0].size();
}

// @private
bool FieldVector::isInvalidIndex(size_t row, size_t column) const
{
    return (row >= rows() || column >= columns());
}