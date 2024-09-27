/**
 * @file texturemanager.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Singleton Texture Manager for MineSweeper.
 * @headerfile "SFML/Graphics.hpp"
 * 
 * @details The `TextureManager` class is responsible for dynamically loading and storing textures 
 * corresponding to different cell states in the Minesweeper game. It ensures that textures 
 * are only loaded once and can be retrieved efficiently when needed.
 */

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <stdexcept>
#include <string>

/**
 * @brief Enumeration to represent the state of a cell.
 */
enum class CellState {
    Unknown,  ///< The state is unknown (covered).
    Flagged,  ///< The cell is flagged.
    Mine,     ///< The cell contains a mine.
    Empty,    ///< The cell is empty (no adjacent mines).
    Adjecent  ///< The cell is adjacent to a mine. Uses a dynamic mine count.
};

/**
 * @brief Path constants for loading texture assets.
 */
const std::string ASSET_TILE_PATH = "assets/MineSweeperSprites/Tile";
const std::string ASSET_TILE_TYPE = ".png";

/**
 * @class TextureManager
 * @brief Singleton class for managing textures in the Minesweeper game.
 * 
 * @details This class ensures that textures are loaded only once and reused throughout 
 * the application. It manages textures for different cell states and dynamically 
 * loads textures for cells with adjacent mines.
 */
class TextureManager
{
  public:
    /**
     * @brief Retrieves the singleton instance of the `TextureManager`.
     * @return Reference to the singleton `TextureManager` instance.
     */
    static TextureManager& getInstance();

    /**
     * @brief Retrieves the texture corresponding to a cell state.
     * @param kState `CellState` The state of the cell.
     * @param kAdjecentMines `int=0` The number of adjacent mines (only relevant for Adjecent state).
     * @return `sf::Texture` Reference to the texture for the given state.
     */
    sf::Texture& getTexture(const CellState kState, const int kAdjecentMines = 0);

  private:
    std::map<CellState, sf::Texture> textures_;    ///< Map for storing textures based on CellState.
    std::map<int, sf::Texture> adjecentTextures_;  ///< Map for storing textures based on adjacent mine count.

    TextureManager() {};                             // Private Constructor to prevent instancing.
    TextureManager(TextureManager const&) = delete;  // Prevent copies
    void operator=(TextureManager const&) = delete;  // Prevent assignment

    /**
     * @brief Loads the texture for a cell with adjacent mines.
     * @param kAdjecentMines `int` The number of adjacent mines.
     * @return The loaded `sf::Texture` object.
     */
    sf::Texture loadTextureForAdjecent(const int kAdjecentMines);

    /**
     * @brief Loads the texture corresponding to a cell state.
     * @param kState `CellState` The state of the cell.
     * @return The loaded `sf::Texture` object.
     */
    sf::Texture loadTextureForState(const CellState kState);

    /**
     * @brief Gets the file path for the texture based on the cell state.
     * @param kState `CellState` The state of the cell.
     * @return `String` representing the file path.
     */
    static std::string getTexturePath(const CellState kState);
};

#endif  // TEXTURE_MANAGER_H_