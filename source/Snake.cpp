#include "Snake.hpp"
#include "Common.hpp"
#include "Configs.hpp"

#include "raylib.h"
#include <deque>

namespace snek
{
    void Snake::reset()
    {
        m_direction = Direction::None;
        m_body.resize(1);
        m_body.front() = RandomPosition();
    }

    void Snake::render() const
    {
        for (const Position &bodyPart : m_body)
        {
            const auto [pixelX, pixelY] = ToPixelCoordinates(bodyPart);
            DrawRectangle(pixelX, pixelY, configs::tileSize, configs::tileSize, configs::snakeColor);
        }
    }

    void Snake::growFront()
    {
        const Position delta = ToDirectionalVector(m_direction);
        int x = m_body.front().x + delta.x;
        int y = m_body.front().y + delta.y;

        if (x < 0)
            x = configs::mapWidth - 1;
        else if (x >= configs::mapWidth)
            x = 0;

        if (y < 0)
            y = configs::mapHeight - 1;
        else if (y >= configs::mapHeight)
            y = 0;

        m_body.push_front({x, y});
    }

    void Snake::setDirection(const Direction nextDirection)
    {
        if (!isOppositeDirection(m_direction, nextDirection))
            m_direction = nextDirection;
    }

    Collision Snake::checkCollision(const Position &apple) const
    {
        if (m_body.front() == apple)
            return Collision::Apple;
        
        for (size_t i = 4; i < m_body.size(); ++i)
            if (m_body.front() == m_body[i])
                return Collision::Snake;
        
        return Collision::None;
    }
    
} // namespace snek
