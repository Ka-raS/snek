#pragma once

#include "Snake.hpp"
#include "Apple.hpp"
#include "Common.hpp"

#include "raylib.h"
#include <chrono>

namespace snek
{
    class Game
    {
    public:
        Game();
        ~Game();
        void Run();

    private:
        void update();
        void render() const;
        void startNewGame();

        void handleInput();
        void handleCollision();
        bool hasEnoughTimePassed();

    private:
        bool m_isRunning;
        std::chrono::time_point<std::chrono::steady_clock> m_lastUpdate;

        Snake m_snake;
        Apple m_apple;
        Direction m_snakeNextDirection;

        Image m_windowIcon;
        Sound m_eatingSound;
    };

} // namespace snek