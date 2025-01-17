#include "Snake.hpp"
#include "Common.hpp"
#include "Configs.hpp"

#include "raylib.h"
#include <deque>

namespace snek
{
    Snake::Snake()
        : m_direction(Direction::None),
          m_body(1, RandomPosition()) {};

    Snake::~Snake() = default;

    void Snake::move()
    {
        grow();
        m_body.pop_back();
    }

    void Snake::grow()
    {
        const Position delta = DirectionalVector(m_direction);
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

        m_body.emplace_front(x, y);
    }

    void Snake::reset()
    {
        m_direction = Direction::None;
        m_body.clear();
        m_body.push_front(RandomPosition());
    }

    void Snake::render() const
    {
        for (const Position &part : m_body)
        {
            const auto [pixelX, pixelY] = ToPixelCoordinates(part);
            DrawRectangle(pixelX, pixelY, configs::tileSize, configs::tileSize, configs::snakeColor);
        }
    }

    void Snake::setDirection(const Direction nextDirection)
    {
        m_direction = nextDirection;
    }

    bool Snake::isSelfCollision() const
    {
        const Position &head = m_body.front();
        for (size_t i = 1; i < m_body.size(); ++i)
            if (head == m_body[i])
                return true;
        return false;
    }

    bool Snake::isCollisionWith(const Position &target) const
    {
        return m_body.front() == target;
    }

    bool Snake::isValidDirection(const Direction nextDirection) const
    {
        return nextDirection != Direction::None && !isOpposite(m_direction, nextDirection);
    }

    const std::deque<Position> &Snake::getPosition() const
    {
        return m_body;
    }

} // namespace snek
