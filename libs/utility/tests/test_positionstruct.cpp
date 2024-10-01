#include "positionstruct.hpp"
#include <gtest/gtest.h>
#include <set>

// Test operator< for usability within `std::set`
TEST(PositionStructTest, DefaultComparison)
{
    MineSweeper::PositionStruct pos1{1, 2};
    MineSweeper::PositionStruct pos2{1, 3};
    MineSweeper::PositionStruct pos3{0, 5};

    EXPECT_TRUE(pos1 < pos2);   // Same row, but column 2 < 3
    EXPECT_TRUE(pos3 < pos1);   // Row 0 < 1
    EXPECT_FALSE(pos2 < pos1);  // pos2 is not less than pos1
}

// Test uniqueness within `std::set`
TEST(PositionStructTest, SetUniqueness)
{
    std::set<MineSweeper::PositionStruct> positions;
    positions.insert({1, 2});
    positions.insert({1, 2});  // Duplicate
    positions.insert({0, 5});

    EXPECT_EQ(positions.size(), 2);  // Should contain only 2 unique positions
}