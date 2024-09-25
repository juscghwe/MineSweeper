/**
 * @file fieldgenerator.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "cellstruct.hpp"
#include <vector>

class FieldGenerator
{
  public:
    FieldGenerator(std::size_t rows, std::size_t columns, std::size_t mines);

    void generateField();

  private:
    std::size_t rows_;
    std::size_t columns_;
    std::size_t mines_;
    std::vector<std::vector<CellStructure>> fieldGrid_;

    void placeMines();
    void calculateAdjecentMines();
};

#endif  // FIELD_GENERATOR_H_