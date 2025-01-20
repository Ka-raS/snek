#include "Apple.hpp"
#include "Common.hpp"
#include "Configs.hpp"

#include "raylib.h"
#include <deque>
#include <algorithm>

namespace snek
{
    void Apple::reset(const std::deque<Position> &snakeBody)
    {
        do
        {
            m_position = RandomPosition();
        } while (std::find(snakeBody.begin(), snakeBody.end(), m_position) != snakeBody.end());
    }

    void Apple::render() const
    {
        const auto [pixelX, pixelY] = ToPixelCoordinates(m_position);
        const Rectangle appleRectangle{
            .x = (float)pixelX,
            .y = (float)pixelY,
            .width = (float)configs::tileSize,
            .height = (float)configs::tileSize
        };
        DrawRectangleLinesEx(appleRectangle, configs::appleThickness, configs::appleColor);
    }

} // namespace snek