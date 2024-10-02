#ifndef GUI_CONSTANTS_H
#define GUI_CONSTANTS_H

#include <array>
#include <stdexcept>
#include <string>

namespace Constants {
namespace GuiConstants {

/**
 * @brief Scalings.
 */
constexpr int WINDOWX = 100;
constexpr int WINDOWY = 100;
constexpr int BUTTONX = 10;
constexpr int BUTTONY = 10;

/**
 * @brief Enumeration to represent the state of a cell.
 */
enum class CellState {
    Unknown,  ///< The state is unknown (covered).
    Flagged,  ///< The cell is flagged.
    Mine,     ///< The cell contains a mine.
    Empty,    ///< The cell is empty (no adjacent mines).
    Adjacent  ///< The cell is adjacent to a mine. Uses a dynamic mine count.
};

class TextureConstants
{
  public:
    static constexpr const char* UNKNOWN_TEXTURE = "assets/MineSweeperSprites/TileUnknown.png";
    static constexpr const char* FLAGGED_TEXTURE = "assets/MineSweeperSprites/TileFlag.png";
    static constexpr const char* MINE_TEXTURE = "assets/MineSweeperSprites/TileMine.png";
    static constexpr const char* EMPTY_TEXTURE = "assets/MineSweeperSprites/TileEmpty.png";

    static constexpr std::array<const char*, 8> ADJACENT_TEXTURES = {
        "assets/MineSweeperSprites/Tile1.png",
        "assets/MineSweeperSprites/Tile2.png",
        "assets/MineSweeperSprites/Tile3.png",
        "assets/MineSweeperSprites/Tile4.png",
        "assets/MineSweeperSprites/Tile5.png",
        "assets/MineSweeperSprites/Tile6.png",
        "assets/MineSweeperSprites/Tile7.png",
        "assets/MineSweeperSprites/Tile8.png",
    };

    /**
     * @brief Returns texture corresponding with the cell state.
     * @param kState `CellState`
     * @return `const char*` with the texture path.
     * @throws `std::out_of_range` if theres no texture defined for the parameter.
     */
    static constexpr const char* getTextureForState(const CellState kState)
    {
        switch (kState) {
            case CellState::Unknown:
                return UNKNOWN_TEXTURE;
            case CellState::Flagged:
                return FLAGGED_TEXTURE;
            case CellState::Mine:
                return MINE_TEXTURE;
            case CellState::Empty:
                return EMPTY_TEXTURE;
            default:
                throw std::out_of_range("State not defined in CellState.");
        }
    };

    /**
     * @brief Returns texture corresponding with the cell adjacent counter.
     * @param kMines `int` Number of adjacent mines.
     * @return `const char*` with the texture path.
     * @throws `std::out_of_range` if theres no texture defined for the parameter.
     */
    static constexpr const char* getAdjacentTexture(const int kMines)
    {
        if (kMines >= 1 && kMines <= 8) {
            return ADJACENT_TEXTURES[kMines - 1];
        }
        throw std::out_of_range("No texture defined for " + std::to_string(kMines) + " adjacent cells.");
    };
};

};  // namespace GuiConstants
};  // namespace Constants

#endif  // GUI_CONSTANTS_H