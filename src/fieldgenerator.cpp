/**
 * @file fieldgenerator.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @headerfile "include/generatefield.hpp"
 * @brief Generates the entire grid for the user to play on.
 */

#include "fieldgenerator.hpp"
#include <random>

namespace MineSweeper {
namespace Generation {
FieldGenerator::FieldGenerator(const std::size_t rows, const std::size_t columns,
                               const std::size_t mines)
    : rows_(rows), columns_(columns), mines_(mines)
{}

std::unique_ptr<FieldVector> FieldGenerator::generateField()
{
    fieldGrid_ = std::make_unique<FieldVector>(rows_, columns_, mines_);
    std::set<int> mineFieldOneD = uniqueRandomNumbers(0, rows_ * columns_ - 1, mines_);
    std::set<Position> mineFieldTwoD = minePlacementTwoD(mineFieldOneD);
    placeMines(mineFieldTwoD);

    return std::move(fieldGrid_);
};

//@private
const std::set<int> FieldGenerator::uniqueRandomNumbers(const int min, const int max,
                                                        const int limit) const
{
    std::set<int> numbers;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> dist(min, max);
    while (numbers.size() < limit) {
        int randomNumber = dist(generator);
        numbers.insert(randomNumber);
    }
    return numbers;
};

// @private
const std::set<Position> FieldGenerator::minePlacementTwoD(const std::set<int>& mineFieldOneD) const
{
    std::set<Position> mineFieldTwoD;
    for (int positionOneD : mineFieldOneD) {
        int row = positionOneD / columns_;
        int column = positionOneD % columns_;
        mineFieldTwoD.insert(Position{row, column});
    }
    return mineFieldTwoD;
};

// @private
void FieldGenerator::placeMines(const std::set<Position>& mineFieldTwoD)
{
    for (Position position : mineFieldTwoD) {
        fieldGrid_->at(position.row, position.column).isMine = true;
        calculateAdjecentMines(position);
    };
};

// @private
void FieldGenerator::calculateAdjecentMines(const Position& position)
{
    for (Position adjecent : adjecentCounter_) {
        try {
            fieldGrid_->at(position.row + adjecent.row, position.column + adjecent.column)
                .adjecentMines += 1;
        } catch (const std::out_of_range& e) {
            // ignore the exception and skip to the next adjecent Position
            continue;
        }
    }
};
}  // namespace Generation
}  // namespace MineSweeper