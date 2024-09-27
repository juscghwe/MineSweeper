#include "gui/texturemanager.hpp"
#include <gtest/gtest.h>

constexpr int NUM_ADJECENT_TEXTURES = 8;

// Test loading textures for different states
class TextureManagerTest : public ::testing::TestWithParam<CellState>
{
  protected:
    MineSweeper::TextureManager& textureManager = MineSweeper::TextureManager::getInstance();
};

TEST_P(TextureManagerTest, LoadsTextureForState)
{
    CellState state = GetParam();
    EXPECT_NO_THROW(textureManager.getTexture(state));
    EXPECT_TRUE(textureManager.getTexture(state).getSize().x > 0);
}

INSTANTIATE_TEST_SUITE_P(TextureStates, TextureManagerTest,
                         ::testing::Values(CellState::Flagged, CellState::Mine, CellState::Unknown, CellState::Empty));

TEST_F(TextureManagerTest, ThrowsForInvalidState)
{
    EXPECT_THROW(textureManager.getTexture(static_cast<CellState>(999)), std::runtime_error);
}

// Test loading textures for the adjecent fields
class TextureManagerAdjecentTest : public ::testing::TestWithParam<int>
{
  protected:
    MineSweeper::TextureManager& textureManager = MineSweeper::TextureManager::getInstance();
};

TEST_P(TextureManagerAdjecentTest, LoadsTextureForAdjecent)
{
    int adjecentMines = GetParam();
    EXPECT_NO_THROW(textureManager.getTexture(CellState::Adjecent, adjecentMines));
    EXPECT_TRUE(textureManager.getTexture(CellState::Adjecent, adjecentMines).getSize().x > 0);
}

INSTANTIATE_TEST_SUITE_P(TextureAdjecentNumbers, TextureManagerAdjecentTest,
                         ::testing::Range(1, NUM_ADJECENT_TEXTURES));

TEST_F(TextureManagerAdjecentTest, ThrowsForInvalidState)
{
    EXPECT_THROW(textureManager.getTexture(CellState::Adjecent, 99), std::runtime_error);
}