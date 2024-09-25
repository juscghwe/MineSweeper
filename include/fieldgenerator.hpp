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
    FieldGenerator(int rows, int columns, int mines);

  private:
    int rows_;
    int columns_;
    int mines_;
    std::vector<std::vector<CellStructure>> fieldGrid_;

    void placeMines();
    void calculateAdjecentMines();
};

#endif  // FIELD_GENERATOR_H_