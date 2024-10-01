/**
 * @file texturemanager.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Texture Manager for MineSweeper.
 * @headerfile "include/gui/texturemanager.hpp"
 */

#include "gui/texturemanager.hpp"
#include <string>

namespace Gui {

TextureManager& TextureManager::getInstance()
{
    static TextureManager instance;
    return instance;
}

sf::Texture& TextureManager::getTexture(const Constants::GuiConstants::CellState kState, const int kAdjecentMines)
{
    if (kState == Constants::GuiConstants::CellState::Adjacent) {
        if (adjecentTextures_.find(kAdjecentMines) == adjecentTextures_.end()) {
            adjecentTextures_[kAdjecentMines] = loadTextureForAdjecent(kAdjecentMines);
        }
        return adjecentTextures_[kAdjecentMines];
    } else {
        if (textures_.find(kState) == textures_.end()) {
            textures_[kState] = loadTextureForState(kState);
        }
        return textures_[kState];
    }
}

// @private
sf::Texture TextureManager::loadTextureForAdjecent(const int kAdjecentMines)
{
    sf::Texture texture;
    const std::string kFilename = Constants::GuiConstants::TextureConstants::getAdjacentTexture(kAdjecentMines);
    if (!texture.loadFromFile(kFilename)) {
        throw std::runtime_error("Asset not found: ");
    }
    texture.setSmooth(true);
    return std::move(texture);
}

// @private
sf::Texture TextureManager::loadTextureForState(const Constants::GuiConstants::CellState kState)
{
    sf::Texture texture;
    const std::string kFilename = Constants::GuiConstants::TextureConstants::getTextureForState(kState);
    if (!texture.loadFromFile(kFilename)) {
        throw std::runtime_error("Asset not found: " + kFilename);
    }
    texture.setSmooth(true);
    return std::move(texture);
}

}  // namespace Gui