/**
 * @file texturemanager.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Texture Manager for MineSweeper.
 * @headerfile "include/gui/texturemanager.hpp"
 */

#include "gui/texturemanager.hpp"

namespace MineSweeper {
TextureManager& TextureManager::getInstance()
{
    static TextureManager instance;
    return instance;
}

sf::Texture& TextureManager::getTexture(const GUI::CellState kState, const int kAdjecentMines)
{
    if (kState == GUI::CellState::Adjecent) {
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
    const std::string kFilename = GUI::TextureConstants::getAdjecentTexture(kAdjecentMines);
    if (!texture.loadFromFile(kFilename)) {
        throw std::runtime_error("Asset not found: ");
    }
    texture.setSmooth(true);
    return std::move(texture);
}

// @private
sf::Texture TextureManager::loadTextureForState(const GUI::CellState kState)
{
    sf::Texture texture;
    const std::string kFilename = GUI::TextureConstants::getTextureForState(kState);
    if (!texture.loadFromFile(kFilename)) {
        throw std::runtime_error("Asset not found: " + kFilename);
    }
    texture.setSmooth(true);
    return std::move(texture);
}
}  // namespace MineSweeper