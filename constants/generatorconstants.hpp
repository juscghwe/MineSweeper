#ifndef GENERATOR_CONSTANTS_H
#define GENERATOR_CONSTANTS_H

#include "utility/positionstruct.hpp"

namespace MineSweeper {

namespace KGenerator {

// A constant `PositionStruct[]` representing the relative positions of adjacent fields.
constexpr PositionStruct ADJECENT_FIELDS_RELATIVE[] =
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

}  // namespace KGenerator

}  // namespace MineSweeper

#endif  // GENERATOR_CONSTANTS_H_