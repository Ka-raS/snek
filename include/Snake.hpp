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
        inline void shrinkBack() { m_body.pop_back(); }
        void setDirection(Direction nextDirection);

        Collision checkCollision(const Position &apple) const;
        inline const std::deque<Position> &getPosition() const { return m_body; }

    private:
        Direction m_direction;
        std::deque<Position> m_body;
    };

} // namespace snek