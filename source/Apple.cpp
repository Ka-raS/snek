#include "Apple.hpp"
#include "Common.hpp"
#include "Configs.hpp"

#include "raylib.h"
#include <deque>

namespace snek
{
    Apple::Apple()
        : m_position(RandomPosition()) {};

    Apple::~Apple() = default;

    void Apple::reset(const std::deque<Position> &snakeBody)
    {
        bool isValid = false;
        while (!isValid)
        {
            isValid = true;
            m_position = RandomPosition();
            for (const Position &part : snakeBody)
                if (m_position == part)
                {
                    isValid = false;
                    break;
                }
        }
    }

    void Apple::render() const
    {
        DrawCircle(m_position.x * configs::scale, m_position.y * configs::scale, configs::scale / 2, configs::appleColor);
    }

    const Position &Apple::getPosition() const
    {
        return m_position;
    }

} // namespace snek