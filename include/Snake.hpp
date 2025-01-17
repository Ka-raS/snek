#pragma once

#include "Common.hpp"

#include <deque>

namespace snek
{
    class Snake
    {
    public:
        Snake();
        ~Snake();

        void move();
        void grow();
        void reset();
        void render() const;
        void setDirection(Direction nextDirection);

        bool isSelfCollision() const;
        bool isCollisionWith(const Position &target) const;
        bool isValidDirection(Direction nextDirection) const;

        const std::deque<Position> &getPosition() const;

    private:
        Direction m_direction;
        std::deque<Position> m_body;
    };

} // namespace snek