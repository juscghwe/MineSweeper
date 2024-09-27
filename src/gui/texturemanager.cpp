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

sf::Texture& TextureManager::getTexture(const CellState kState, const int kAdjecentMines)
{
    if (kState == CellState::Adjecent) {
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
    const std::string kFilename = ASSET_TILE_PATH + std::to_string(kAdjecentMines) + ASSET_TILE_TYPE;
    if (!texture.loadFromFile(kFilename)) {
        throw std::runtime_error("Asset not found: ");
    }
    texture.setSmooth(true);
    return std::move(texture);
}

// @private
sf::Texture TextureManager::loadTextureForState(const CellState kState)
{
    sf::Texture texture;
    const std::string kFilename = ASSET_TILE_PATH + getTexturePath(kState) + ASSET_TILE_TYPE;
    if (!texture.loadFromFile(kFilename)) {
        throw std::runtime_error("Asset not found: " + kFilename);
    }
    texture.setSmooth(true);
    return std::move(texture);
}

// @private
std::string TextureManager::getTexturePath(const CellState kState)
{
    switch (kState) {
        case CellState::Unknown:
            return "Unknown";
        case CellState::Flagged:
            return "Flag";
        case CellState::Mine:
            return "Mine";
        case CellState::Empty:
            return "Empty";
        default:
            throw std::runtime_error("Asset not found for unknown state.");  // No path for Adjacent since it's dynamic
    }
}
}  // namespace MineSweeper