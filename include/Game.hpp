#pragma once

#include "Snake.hpp"
#include "Apple.hpp"
#include "Common.hpp"

#include "raylib.h"

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

        void handleInput();
        void handleCollision();
        static bool hasEnoughTimePassed();

    private:
        Image m_windowIcon;
        Sound m_eatingSound;

        Snake m_snake;
        Apple m_apple;
        Direction m_nextSnakeDirection;
    };

} // namespace snek