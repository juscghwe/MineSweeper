#include "cellstruct.hpp"
#include <gtest/gtest.h>

// Test the default values for CellStruct
TEST(CellStructTest, DefaultConstructor)
{
    Utility::CellStruct cell;
    EXPECT_FALSE(cell.isMine);         ///< Cell should not be a mine at the beginning of the game.
    EXPECT_TRUE(cell.isCovered);       ///< Cell should be covered at the beginning of the game.
    EXPECT_FALSE(cell.isFlagged);      ///< Cell should not be flagged at the beginning of the game.
    EXPECT_EQ(cell.adjecentMines, 0);  ///< Cell can't have adjecent Mines when the field hasn't been generated yet.
}

// Test if values of CellStruct can be modified
TEST(CellStructTest, ModifyCellAttributes)
{
    Utility::CellStruct cell;

    // set new values
    cell.isMine = true;
    cell.isCovered = false;
    cell.isFlagged = true;
    cell.adjecentMines = 3;

    // verify new values
    EXPECT_TRUE(cell.isMine);
    EXPECT_FALSE(cell.isCovered);
    EXPECT_TRUE(cell.isFlagged);
    EXPECT_EQ(cell.adjecentMines, 3);
}