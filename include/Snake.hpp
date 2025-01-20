#pragma once

#include "Common.hpp"
#include <deque>

namespace snek
{
    class Snake
    {
    public:
        Snake() = default;
        ~Snake() = default;

        void reset();
        void render() const;
        void growFront();
        inline void shrinkBack();
        void setDirection(Direction nextDirection);

        Collision checkCollision(const Position &apple) const;
        inline const std::deque<Position> &getPosition() const;

    private:
        Direction m_direction;
        std::deque<Position> m_body;
    };

    inline void Snake::shrinkBack()
    { 
        m_body.pop_back(); 
    }
    
    inline const std::deque<Position> &Snake::getPosition() const
    {
        return m_body;
    }

} // namespace snek