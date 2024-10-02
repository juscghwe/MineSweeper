#ifndef GENERATOR_CONSTANTS_H
#define GENERATOR_CONSTANTS_H

#include "utility/positionstruct.hpp"

namespace Constants {
namespace GeneratorConstants {

// Relative positions of adjacent cells (N, NE, E, SE, S, SW, W, NW).
constexpr Utility::PositionStruct ADJACENT_FIELDS_RELATIVE[] =
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

}  // namespace GeneratorConstants
}  // namespace Constants

#endif  // GENERATOR_CONSTANTS_H