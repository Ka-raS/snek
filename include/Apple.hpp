#pragma once

#include "Common.hpp"
#include <deque>

namespace snek
{
    class Apple
    {
    public:
        Apple() = default;
        ~Apple() = default;

        void reset(const std::deque<Position> &snakeBody);
        void render() const;
        inline const Position &getPosition() const { return m_position; }

    private:
        Position m_position;
    };

} // namespace snek