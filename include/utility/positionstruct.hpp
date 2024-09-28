/**
 * @file positionstruct.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Defines the `PositionStruct` for the Minesweeper game, representing the directional position of a cell in rows and columns.
 */

#ifndef POSITION_STRUCTURE_H
#define POSITION_STRUCTURE_H

namespace MineSweeper {

/**
 * @struct PositionStruct
 * @brief Represents the directional position of a field in the minefield grid.
 */
struct PositionStruct {
    const int row;     ///< `int` Row index of the position in the grid.
    const int column;  ///< `int` Column index of the position in the grid.

    /**
     * @brief Compares two `Position` objects for ordering. Necessary for `std::set<Position>`.
     * @param other The other `Position` to compare against.
     * @return `bool` `true` if this `Position` is less than the other, `false` otherwise.
     */
    constexpr bool operator<(const PositionStruct& other) const
    {
        return (row == other.row) ? (column < other.column) : (row < other.row);
    }
};

}  // namespace MineSweeper

#endif  // POSITION_STRUCTURE_H_