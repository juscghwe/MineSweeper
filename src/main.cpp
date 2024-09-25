#include "fieldgenerator.hpp"
#include <iostream>

int main()
{
    FieldGenerator fieldGenerator(10, 10, 4);
    std::unique_ptr<FieldVector> playfield = fieldGenerator.generateField();
    for (std::vector<CellStructure> row : playfield->getFieldGrid()) {
        for (CellStructure column : row) {
            std::cout << (column.isMine ? "X" : std::to_string(column.adjecentMines));
        }
        std::cout << "\n";
    }
    return 0;
}