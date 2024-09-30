/**
 * @file fieldgenerator.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Defines the `FieldGenerator` class, which generates a minefield for the Minesweeper game.
 * @headerfile "utility/fieldvector.hpp"
 * @headerfile "utility/positionstruct.hpp"
 */

#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "utility/fieldvector.hpp"
#include "utility/positionstruct.hpp"
#include <memory>
#include <set>

namespace MineSweeper {
namespace Generation {

/**
 * @class `FieldGenerator`
 * @brief Generates a 2D grid of cells in the Minesweeper game.
 */
class FieldGenerator
{
  public:
    /**
     * @brief Constructs a `FieldGenerator` object with specified dimensions and number of mines.
     * @param rows `std::size_t` The number of rows in the minefield.
     * @param columns `std::size_t` The number of columns in the minefield.
     * @param mines `std::size_t` The number of mines to place in the minefield.
     */
    FieldGenerator(const std::size_t rows, const std::size_t columns, const std::size_t mines);

    /**
     * @brief Generates the minefield based on the specified rows, columns, and mines.
     * @return `std::unique_ptr<MineSweeper::FieldVector>` A unique pointer to the generated `FieldVector` representing the minefield.
     * @details This method randomly places mines in the minefield and calculates the adjacent mine counts.
     */
    std::unique_ptr<MineSweeper::FieldVector> generateField();

    std::size_t getRows() const { return rows_; }
    std::size_t getColumns() const { return columns_; }
    std::size_t getMines() const { return mines_; }

  private:
    const std::size_t rows_;     ///< `std::size_t` The number of rows in the minefield.
    const std::size_t columns_;  ///< `std::size_t` The number of columns in the minefield.
    const std::size_t mines_;    ///< `std::size_t` The number of mines in the minefield.
    std::unique_ptr<MineSweeper::FieldVector>
        fieldGrid_;  ///< `unique_ptr<MineSweeper::FieldVector>` Unique pointer to the minefield grid.

    /**
     * @private
     * @brief Generates a set of unique random numbers within a specified range.
     * @param min `int` The lower bound of the range (inclusive).
     * @param max `int` The upper bound of the range (inclusive).
     * @param limit `int` The number of unique random numbers to generate.
     * @return `std::set<int>` A set containing the generated unique random numbers.
     * @throws `std::invalid_argument` if the `limit` is not within the range of `min` and `max`.
     */
    std::set<int> uniqueRandomNumbers(const int min, const int max, const int limit) const;

    /**
     * @private
     * @brief Transforms a 1D representation of mine positions into a 2D representation.
     * @param mineFieldOneD `std::set<int>` A set of integers representing linear positions of mines.
     * @return `std::set<PositionStruct>` A set of objects representing 2D coordinates of the mines.
     */
    std::set<PositionStruct> minePlacementTwoD(const std::set<int>& mineFieldOneD) const;

    /**
     * @private
     * @brief Places mines in the field grid based on the provided 2D positions.
     * @param mineFieldTwoD `std::set<PositionStruct>` A set indicating where to place the mines.
     */
    void placeMines(const std::set<PositionStruct>& mineFieldTwoD);

    /**
     * @private
     * @brief Calculates the number of adjacent mines for a given position in the minefield.
     * @param position `PositionStruct` The field for which to calculate adjacent mines.
     */
    void calculateAdjecentMines(const PositionStruct& position);
};
};  // namespace Generation
};  // namespace MineSweeper

#endif  // FIELD_GENERATOR_H