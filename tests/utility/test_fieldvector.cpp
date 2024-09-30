#include "utility/fieldvector.hpp"
#include <gtest/gtest.h>

// Test class for the FieldVector
class FieldVectorTest : public ::testing::Test
{
  protected:
    // Define test parameters
    const size_t rows = 5;
    const size_t columns = 5;
    const size_t mines = 3;
    MineSweeper::FieldVector fieldVector{rows, columns, mines};  // FieldVector instance for testing
};

// Test the constructor to ensure the grid is initialized correctly
TEST_F(FieldVectorTest, ConstructorInitializesGrid)
{
    EXPECT_EQ(fieldVector.rows(), rows);        // Check number of rows
    EXPECT_EQ(fieldVector.columns(), columns);  // Check number of columns
}

// Test the at() method for valid indices
TEST_F(FieldVectorTest, AtReturnsCellForValidIndices)
{
    EXPECT_NO_THROW(fieldVector.at(0, 0));                   // Check access to the first cell
    EXPECT_NO_THROW(fieldVector.at(rows - 1, columns - 1));  // Check access to the last cell
}

// Test the at() method for invalid indices
TEST_F(FieldVectorTest, AtThrowsForInvalidIndices)
{
    EXPECT_THROW(fieldVector.at(rows, 0), std::out_of_range);        // Check access beyond last row
    EXPECT_THROW(fieldVector.at(0, columns), std::out_of_range);     // Check access beyond last column
    EXPECT_THROW(fieldVector.at(rows, columns), std::out_of_range);  // Check access beyond bottom-right corner
}

// Test the rows() method
TEST_F(FieldVectorTest, RowsReturnsCorrectCount)
{
    EXPECT_EQ(fieldVector.rows(), rows);  // Ensure rows() returns correct value
}

// Test the columns() method
TEST_F(FieldVectorTest, ColumnsReturnsCorrectCount)
{
    EXPECT_EQ(fieldVector.columns(), columns);  // Ensure columns() returns correct value
}