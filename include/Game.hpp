#pragma once

#include "raylib.h"

class Game
{
public:
    Game();
    ~Game();
    void Run();

private:
    void Update();

private:
    Image m_windowIcon;
};
