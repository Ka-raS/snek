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
        onst Position &getPosition() const;

    private:
        Position m_position;
    };
    
    inline const Position &Apple::getPosition() const 
    { 
        return m_position;
    }

} // namespace snek
