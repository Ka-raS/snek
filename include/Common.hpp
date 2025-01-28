#pragma once

namespace snek
{
    enum class Collision
    {
        None,
        Apple,
        Snake
    };

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

        inline bool operator==(const Position& other) const;
    };
    
    inline bool Position::operator==(const Position &other) const 
    {
        return this->x == other.x && this->y == other.y;
    }

    Position RandomPosition();

    Position ToDirectionalVector(Direction direction);

    bool isOppositeDirection(Direction current, Direction other);

    Position ToPixelCoordinates(const Position &position);

} // namespace snek