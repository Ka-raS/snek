#pragma once

#include <unordered_map>

namespace snek
{
    enum class Direction
    {
        None,
        Up,
        Down,
        Left,
        Right
    };

    struct Position
    {
        int x;
        int y;

        bool operator==(const Position &other) const;
    };

    Position RandomPosition();

    Position ToDirectionalVector(Direction direction);

    bool isOpposite(Direction current, Direction other);

    Position ToPixelCoordinates(const Position &position);

} // namespace snek
