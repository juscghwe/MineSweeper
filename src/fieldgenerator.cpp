/**
 * @file fieldgenerator.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 * @headerfile "include/generatefield.hpp"
 * @brief Generates the entire grid for the user to play on.
 */

#include "fieldgenerator.hpp"
#include <random>

FieldGenerator::FieldGenerator(std::size_t rows, std::size_t columns, std::size_t mines)
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
std::set<int> FieldGenerator::uniqueRandomNumbers(int min, int max, int limit)
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
std::set<Position> FieldGenerator::minePlacementTwoD(std::set<int> mineFieldOneD)
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
void FieldGenerator::placeMines(std::set<Position> mineFieldTwoD)
{
    for (Position position : mineFieldTwoD) {
        fieldGrid_->at(position.row, position.column).isMine = true;
    };
};

// @private
void FieldGenerator::calculateAdjecentMines(Position position)
{
    for (Position adjecent : adjecentCounter_) {
        fieldGrid_->at(position.row + adjecent.row, position.column + adjecent.column)
            .adjecentMines += 1;
    }
};