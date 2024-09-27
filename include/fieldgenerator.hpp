/**
 * @file fieldgenerator.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Defines the `FieldGenerator` class, which generates a minefield for the Minesweeper game.
 */

#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "fieldvector.hpp"
#include <memory>
#include <set>

namespace MineSweeper {
namespace Generation {

// Represents the directional position of a field in the minefield grid.
struct Position {
    const int row;     ///< `int` Row index of the position in the grid.
    const int column;  ///< `int` Column index of the position in the grid.

    /**
     * @brief Compares two `Position` objects for ordering. Necessary for `set<Position>`.
     * @param other The other `Position` to compare against.
     * @return `bool` `true` if this `Position` is less than the other, `false` otherwise.
     */
    constexpr bool operator<(const Position& other) const
    {
        return (row == other.row) ? (column < other.column) : (row < other.row);
    }
};

// A constant `set<Position>` representing the relative positions of adjacent fields.
const std::set<Position> ADJECENT_FIELDS_RELATIVE =
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class FieldGenerator
{
  public:
    /**
     * @brief Constructs a `FieldGenerator` object with specified dimensions and number of mines.
     * @param rows `size_t` The number of rows in the minefield.
     * @param columns `size_t` The number of columns in the minefield.
     * @param mines `size_t` The number of mines to place in the minefield.
     */
    FieldGenerator(const std::size_t rows, const std::size_t columns, const std::size_t mines);

    /**
     * @brief Generates the minefield based on the specified rows, columns, and mines.
     * @return `std::unique_ptr<MineSweeper::FieldVector>` A unique pointer to the generated `FieldVector` representing the minefield.
     * @details This method randomly places mines in the minefield and calculates the adjacent mine counts.
     */
    std::unique_ptr<MineSweeper::FieldVector> generateField();

  private:
    const std::size_t rows_;     ///< `size_t` The number of rows in the minefield.
    const std::size_t columns_;  ///< `size_t` The number of columns in the minefield.
    const std::size_t mines_;    ///< `size_t` The number of mines in the minefield.
    std::unique_ptr<MineSweeper::FieldVector>
        fieldGrid_;  ///< `unique_ptr<MineSweeper::FieldVector>` Unique pointer to the minefield grid.

    /**
     * @private
     * @brief Generates a set of unique random numbers within a specified range.
     * @param min `int` The lower bound of the range (inclusive).
     * @param max `int` The upper bound of the range (inclusive).
     * @param limit `int` The number of unique random numbers to generate.
     * @return `std::set<int>` A set containing the generated unique random numbers.
     */
    std::set<int> uniqueRandomNumbers(const int min, const int max, const int limit) const;

    /**
     * @private
     * @brief Transforms a 1D representation of mine positions into a 2D representation.
     * @param mineFieldOneD `std::set<int>` A set of integers representing linear positions of mines.
     * @return `std::set<Position>` A set of objects representing 2D coordinates of the mines.
     */
    std::set<Position> minePlacementTwoD(const std::set<int>& mineFieldOneD) const;

    /**
     * @private
     * @brief Places mines in the field grid based on the provided 2D positions.
     * @param mineFieldTwoD `std::set<Position>` A set indicating where to place the mines.
     */
    void placeMines(const std::set<Position>& mineFieldTwoD);

    /**
     * @private
     * @brief Calculates the number of adjacent mines for a given position in the minefield.
     * @param position `Position` The field for which to calculate adjacent mines.
     */
    void calculateAdjecentMines(const Position& position);
};
};  // namespace Generation
};  // namespace MineSweeper

#endif  // FIELD_GENERATOR_H_