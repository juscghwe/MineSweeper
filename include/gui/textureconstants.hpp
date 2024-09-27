#ifndef TEXTURE_CONSTANTS_H
#define TEXTURE_CONSTANTS_H

#include <map>
#include <string>

namespace MineSweeper {
/**
 * @brief Enumeration to represent the state of a cell.
 */
enum CellState {
    Unknown,  ///< The state is unknown (covered).
    Flagged,  ///< The cell is flagged.
    Mine,     ///< The cell contains a mine.
    Empty,    ///< The cell is empty (no adjacent mines).
    Adjecent  ///< The cell is adjacent to a mine. Uses a dynamic mine count.
};

/**
 * @brief Path constants for loading texture assets by state.
 */
const std::map<const CellState, const std::string> ASSET_TILE_STATEBOUND{
    {CellState::Unknown, "assets/MineSweeperSprites/TileUnknown.png"},
    {CellState::Flagged, "assets/MineSweeperSprites/TileFlag.png"},
    {CellState::Mine, "assets/MineSweeperSprites/TileMine.png"},
    {CellState::Empty, "assets/MineSweeperSprites/TileEmpty.png"}};

/**
 * @brief Path constants for loading texture assets based on adjecent tiles.
 */
const std::map<const int, const std::string> ASSET_TILE_ADJECENTBOUND{{1, "assets/MineSweeperSprites/Tile1.png"},
                                                                      {2, "assets/MineSweeperSprites/Tile2.png"},
                                                                      {3, "assets/MineSweeperSprites/Tile3.png"},
                                                                      {4, "assets/MineSweeperSprites/Tile4.png"},
                                                                      {5, "assets/MineSweeperSprites/Tile5.png"},
                                                                      {6, "assets/MineSweeperSprites/Tile6.png"},
                                                                      {7, "assets/MineSweeperSprites/Tile7.png"},
                                                                      {8, "assets/MineSweeperSprites/Tile8.png"}};

};  // namespace MineSweeper
#endif  // TEXTURE_CONSTANTS_H_