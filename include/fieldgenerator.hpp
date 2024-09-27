/**
 * @file fieldgenerator.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "fieldvector.hpp"
#include <memory>
#include <set>

namespace MineSweeper {
namespace Generation {

struct Position {
    const int row;
    const int column;

    constexpr bool operator<(const Position& other) const
    {
        return (row == other.row) ? (column < other.column) : (row < other.row);
    }
};

const std::set<Position> adjecentCounter_ =
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class FieldGenerator
{
  public:
    FieldGenerator(const std::size_t rows, const std::size_t columns, const std::size_t mines);

    /**
     * @brief Generates the minefield by the class defined `rows`, `columns` and number of `mines`.
     * @return `std::unique_ptr<FieldVector>` Moves the `FieldVector` to the caller as `unique_ptr`. 
     */
    std::unique_ptr<FieldVector> generateField();

  private:
    const std::size_t rows_;
    const std::size_t columns_;
    const std::size_t mines_;
    std::unique_ptr<MineSweeper::FieldVector> fieldGrid_;

    /**
     * @private
     * @brief Generates a set of random unique numbers.
     * @param min `int = 0` Lower end of the number range.
     * @param max `int` Upper end of the number range.
     * @param limit `int` Number of unique numbers to generate.
     * @return `std::set<int>` Set of unique random numbers.
     */
    std::set<int> uniqueRandomNumbers(const int min, const int max, const int limit) const;

    /**
     * @private
     * @brief Transforms a 1D representation of the minefield into a 2D representation.
     * @param minePlacementOneD `std::set<int>` Linear position of the mines.
     * @return `std::set<Position>` Each `pair` represents one 2D coordinate of a mine.
     */
    std::set<Position> minePlacementTwoD(const std::set<int>& mineFieldOneD,
                                         const std::size_t columns) const;

    /**
     * @private
     * @brief 
     * @param mineFieldTwoD
     */
    void placeMines(const std::set<Position>& mineFieldTwoD);

    /**
     * @private
     * @brief 
     * @param mineFieldTwoD
     */
    void calculateAdjecentMines(const Position& position);
};
};  // namespace Generation
};  // namespace MineSweeper

#endif  // FIELD_GENERATOR_H_