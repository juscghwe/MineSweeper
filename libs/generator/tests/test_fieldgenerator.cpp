#include "generator/fieldgenerator.hpp"
#include "generatorconstants.hpp"
#include "utility/fieldvector.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <set>

namespace MS = MineSweeper;
namespace Gen = MineSweeper::Generation;
namespace KGen = MineSweeper::KGenerator;

// Test Fixture for FieldGenerator
class FieldGeneratorTest : public ::testing::Test
{
  protected:
    const std::size_t rows = 5;
    const std::size_t columns = 5;
    const std::size_t mines = 5;

    std::unique_ptr<Gen::FieldGenerator> fieldGenerator;

    void SetUp() override { fieldGenerator = std::make_unique<Gen::FieldGenerator>(rows, columns, mines); }
};

// Test the constructor to ensure it initializes the field correctly.
TEST_F(FieldGeneratorTest, ConstructorInitializesCorrectly)
{
    EXPECT_EQ(fieldGenerator->getRows(), rows);
    EXPECT_EQ(fieldGenerator->getColumns(), columns);
    EXPECT_EQ(fieldGenerator->getMines(), mines);
}

// Test generateField to ensure the correct number of mines is placed.
TEST_F(FieldGeneratorTest, GenerateFieldPlacesCorrectNumberOfMines)
{
    auto field = fieldGenerator->generateField();

    std::size_t mineCount = 0;
    for (std::size_t row = 0; row < rows; ++row) {
        for (std::size_t col = 0; col < columns; ++col) {
            if (field->at(row, col).isMine) {
                mineCount++;
            }
        }
    }

    EXPECT_EQ(mineCount, mines);  // Ensure the correct number of mines is placed
}

// Test that adjacent mine counts are calculated correctly.
TEST_F(FieldGeneratorTest, AdjacentMinesAreCalculatedCorrectly)
{
    auto field = fieldGenerator->generateField();

    for (std::size_t row = 0; row < rows; ++row) {
        for (std::size_t col = 0; col < columns; ++col) {
            if (field->at(row, col).isMine) {
                continue;  // Skip mines
            }

            // Check if the number of adjacent mines matches the cell's adjacentMines count
            std::size_t expectedAdjMines = 0;
            for (const auto& adj : KGen::ADJACENT_FIELDS_RELATIVE) {
                int adjRow = static_cast<int>(row) + adj.row;
                int adjCol = static_cast<int>(col) + adj.column;
                if (adjRow >= 0 && adjRow < static_cast<int>(rows) && adjCol >= 0 &&
                    adjCol < static_cast<int>(columns) && field->at(adjRow, adjCol).isMine) {
                    expectedAdjMines++;
                }
            }

            EXPECT_EQ(field->at(row, col).adjecentMines, expectedAdjMines);
        }
    }
}

// Test edge case where number of mines exceeds the number of available cells.
TEST_F(FieldGeneratorTest, ThrowsWhenMinesExceedAvailableCells)
{
    EXPECT_THROW(Gen::FieldGenerator(rows, columns, rows * columns + 1).generateField(), std::invalid_argument);
}
