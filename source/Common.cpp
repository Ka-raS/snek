#include "Common.hpp"
#include "Configs.hpp"

#include "raylib.h"
#include <array>
#include <cstddef>

namespace snek
{
    static constexpr std::array<Direction, 5> s_oppositeDirections = {
        Direction::None, Direction::Down, Direction::Up, Direction::Right, Direction::Left
    };   

    Position RandomPosition()
    {
        return {
            .x = GetRandomValue(0, configs::mapWidth - 1),
            .y = GetRandomValue(0, configs::mapHeight - 1)
        };
    }

    Position ToDirectionalVector(const Direction direction)
    {
        switch (direction)
        {
        case Direction::None:
            return {.x = 0, .y = 0};

        case Direction::Up:
            return {.x = 0, .y = -1};

        case Direction::Down:
            return {.x = 0, .y = 1};

        case Direction::Left:
            return {.x = -1, .y = 0};

        case Direction::Right:
            return {.x = 1, .y = 0};
        
        default:
            return {};
        }
    }

    bool isOppositeDirection(Direction current, Direction other)
    {
        return other == s_oppositeDirections[static_cast<size_t>(current)];
    }

    Position ToPixelCoordinates(const Position &position)
    {
        return {
            .x = position.x * configs::tileSize,
            .y = position.y * configs::tileSize
        };
    }

}
