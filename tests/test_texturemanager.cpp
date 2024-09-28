#include "gui/texturemanager.hpp"
#include <gtest/gtest.h>

constexpr int NUM_ADJECENT_TEXTURES = 8;  // Number of adjacent textures available

// Test class for the TextureManager focusing on loading textures for different cell states.
class TextureManagerTest : public ::testing::TestWithParam<MineSweeper::KTextures::CellState>
{
  protected:
    MineSweeper::TextureManager& textureManager = MineSweeper::TextureManager::getInstance();
};

// Test loading textures for different states
TEST_P(TextureManagerTest, LoadsTextureForState)
{
    MineSweeper::KTextures::CellState state = GetParam();
    EXPECT_NO_THROW(textureManager.getTexture(state));  // Ensure no exception is thrown when getting the texture
    EXPECT_TRUE(textureManager.getTexture(state).getSize().x > 0);  // Check that the texture has a valid width
}

// Instantiate the parameterized test for different cell states
INSTANTIATE_TEST_SUITE_P(TextureStates, TextureManagerTest,
                         ::testing::Values(MineSweeper::KTextures::CellState::Flagged,
                                           MineSweeper::KTextures::CellState::Mine,
                                           MineSweeper::KTextures::CellState::Unknown,
                                           MineSweeper::KTextures::CellState::Empty));

// Test class for the TextureManager focusing on loading textures for adjacent fields.
class TextureManagerAdjecentTest : public ::testing::TestWithParam<int>
{
  protected:
    MineSweeper::TextureManager& textureManager = MineSweeper::TextureManager::getInstance();
};

// Test loading textures for adjacent fields based on the number of adjacent mines
TEST_P(TextureManagerAdjecentTest, LoadsTextureForAdjecent)
{
    int adjecentMines = GetParam();
    EXPECT_NO_THROW(textureManager.getTexture(MineSweeper::KTextures::CellState::Adjecent,
                                              adjecentMines));  // Ensure no exception is thrown
    EXPECT_TRUE(textureManager.getTexture(MineSweeper::KTextures::CellState::Adjecent, adjecentMines).getSize().x >
                0);  // Validate the texture size
}

// Instantiate the parameterized test for adjacent mine counts
INSTANTIATE_TEST_SUITE_P(TextureAdjecentNumbers, TextureManagerAdjecentTest,
                         ::testing::Range(1, NUM_ADJECENT_TEXTURES));

// Test for invalid state handling in TextureManager for different states
TEST_F(TextureManagerTest, ThrowsForInvalidState)
{
    EXPECT_THROW(textureManager.getTexture(static_cast<MineSweeper::KTextures::CellState>(999)),
                 std::out_of_range);  // Ensure exception is thrown for invalid state
}

// Test for invalid state handling in TextureManager for adjacent textures
TEST_F(TextureManagerAdjecentTest, ThrowsForInvalidState)
{
    EXPECT_THROW(textureManager.getTexture(MineSweeper::KTextures::CellState::Adjecent, 99),
                 std::out_of_range);  // Ensure exception is thrown for invalid adjacent count
}