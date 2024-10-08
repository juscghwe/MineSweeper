/**
 * @file fieldgenerator.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @brief Defines the `FieldGenerator` class, which generates a minefield for the Minesweeper game.
 * @headerfile "include/fieldgenerator.hpp"
 * @headerfile "generatorconstants.hpp"
 */

#include "generator/fieldgenerator.hpp"
#include "generatorconstants.hpp"
#include <random>

namespace Generator {

FieldGenerator::FieldGenerator(const std::size_t rows, const std::size_t columns, const std::size_t mines)
    : rows_(rows),
      columns_(columns),
      mines_(mines),
      fieldGrid_(std::make_unique<Utility::FieldVector>(rows, columns, mines))
{}

std::unique_ptr<Utility::FieldVector> FieldGenerator::generateField()
{
    const std::set<int> mineFieldOneD = uniqueRandomNumbers(0, rows_ * columns_ - 1, mines_);
    const std::set<Utility::PositionStruct> mineFieldTwoD = minePlacementTwoD(mineFieldOneD);
    placeMines(mineFieldTwoD);

    return std::move(fieldGrid_);
};

//@private
std::set<int> FieldGenerator::uniqueRandomNumbers(const int min, const int max, const int limit) const
{
    if (limit <= 0 || limit > (max - min + 1)) {
        throw std::invalid_argument("Limit must be greater than 0 and less than or equal to the range.");
    }

    std::set<int> numbers;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> dist(min, max);

    while (numbers.size() < limit) {
        const int randomNumber = dist(generator);
        numbers.insert(randomNumber);
    }
    return numbers;
};

// @private
std::set<Utility::PositionStruct> FieldGenerator::minePlacementTwoD(const std::set<int>& mineFieldOneD) const
{
    std::set<Utility::PositionStruct> mineFieldTwoD;
    for (const int positionOneD : mineFieldOneD) {
        const int row = positionOneD / columns_;
        const int column = positionOneD % columns_;
        mineFieldTwoD.insert(Utility::PositionStruct{row, column});
    }
    return mineFieldTwoD;
};

// @private
void FieldGenerator::placeMines(const std::set<Utility::PositionStruct>& mineFieldTwoD)
{
    for (const Utility::PositionStruct position : mineFieldTwoD) {
        fieldGrid_->at(position.row, position.column).isMine = true;
        calculateAdjecentMines(position);
    };
};

// @private
void FieldGenerator::calculateAdjecentMines(const Utility::PositionStruct& position)
{
    for (const Utility::PositionStruct& adjecent : Constants::GeneratorConstants::ADJACENT_FIELDS_RELATIVE) {
        if (position.row + adjecent.row >= 0 && position.row + adjecent.row < rows_ &&
            position.column + adjecent.column >= 0 && position.column + adjecent.column < columns_) {
            fieldGrid_->at(position.row + adjecent.row, position.column + adjecent.column).adjacentMines += 1;
        }
    }
};

}  // namespace Generator