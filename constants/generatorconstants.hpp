#ifndef GENERATOR_CONSTANTS_H
#define GENERATOR_CONSTANTS_H

#include "utility/positionstruct.hpp"

namespace MineSweeper {

namespace KGenerator {

// Relative positions of adjacent cells (N, NE, E, SE, S, SW, W, NW).
constexpr PositionStruct ADJACENT_FIELDS_RELATIVE[] =
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

}  // namespace KGenerator

}  // namespace MineSweeper

#endif  // GENERATOR_CONSTANTS_H