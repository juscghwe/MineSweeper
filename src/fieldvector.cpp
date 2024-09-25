/**
 * @file fieldvector.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @headerfile "include/fieldvector.hpp"
 */

#include "fieldvector.hpp"

FieldVector::FieldVector(std::size_t rows, std::size_t columns, std::size_t mines)
    : rows_(rows), columns_(columns), mines_(mines)
{}

CellStructure& FieldVector::at(size_t row, size_t column)
{
    if (isEmpty()) {
        throw std::out_of_range("Grid not initialized.\n");
    }
    if (isInvalidIndex(row, column)) {
        throw std::out_of_range("Index out of bounds.\n");
    }
    return fieldGrid_[row][column];
}

const size_t FieldVector::rows()
{
    if (isEmpty()) {
        return 0;
    } else {
        return fieldGrid_.size();
    }
}

const size_t FieldVector::columns()
{
    if (isEmpty()) {
        return 0;
    } else {
        return fieldGrid_[0].size();
    }
}

// @private
const bool FieldVector::isEmpty()
{
    return fieldGrid_.empty();
}

// @private
const bool FieldVector::isInvalidIndex(size_t row, size_t column)
{
    return (row >= rows() || column >= columns());
}