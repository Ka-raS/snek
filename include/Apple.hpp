#pragma once

#include "Common.hpp"

#include <deque>

namespace snek
{
    class Apple
    {
    public:
        Apple();
        ~Apple();

        void reset(const std::deque<Position> &snakeBody);
        void render() const;
        const Position &getPosition() const;

    private:
        Position m_position;
    };

} // namespace snek