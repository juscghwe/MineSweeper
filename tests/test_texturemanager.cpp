#include "gui/texturemanager.hpp"
#include <gtest/gtest.h>

constexpr int NUM_ADJECENT_TEXTURES = 8;

// Test loading textures for different states
class TextureManagerTest : public ::testing::TestWithParam<CellState>
{
  protected:
    TextureManager& textureManager = TextureManager::getInstance();
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
    // Test invalid cases and ensure correct errors are thrown
    EXPECT_THROW(textureManager.getTexture(static_cast<CellState>(999)), std::runtime_error);
}

// Test loading textures for the adjecent fields
class TextureManagerAdjecentTest : public ::testing::TestWithParam<int>
{
  protected:
    TextureManager& textureManager = TextureManager::getInstance();
};

TEST_P(TextureManagerAdjecentTest, LoadsTextureForAdjecent) {}

INSTANTIATE_TEST_SUITE_P(TextureAdjecentNumbers, TextureManagerAdjecentTest,
                         ::testing::Range(1, NUM_ADJECENT_TEXTURES));