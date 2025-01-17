#include "Common.hpp"
#include "Configs.hpp"

#include "raylib.h"

namespace snek
{
    Position RandomPosition()
    {
        return {
            .x = GetRandomValue(0, configs::mapWidth - 1),
            .y = GetRandomValue(0, configs::mapHeight - 1)};
    }

    Position DirectionalVector(const Direction direction)
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

    bool Position::operator==(const Position &other) const
    {
        return this->x == other.x && this->y == other.y;
    }

    bool isOpposite(const Direction current, const Direction other)
    {
        return (current == Direction::Up && other == Direction::Down) ||
               (current == Direction::Down && other == Direction::Up) ||
               (current == Direction::Left && other == Direction::Right) ||
               (current == Direction::Right && other == Direction::Left);
    }

} // namespace utils