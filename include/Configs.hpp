#pragma once

#include "raylib.h"
#include <chrono>

namespace snek::configs
{
    constexpr int fpsTarget = 60;
    constexpr int windowWidth = 900;
    constexpr int windowHeight = 600;
    constexpr int mapWidth = 45;
    constexpr int mapHeight = 30;
    constexpr int scale = 20;

    constexpr const char *windowTitle = "snek";
    constexpr const char *windowIconPath = "../resources/icon.png";
    constexpr const char *eatingSoundPath = "../resources/eating_sound.wav";

    constexpr Color backgroundColor = BLACK;
    constexpr Color snakeColor = WHITE;
    constexpr Color appleColor = WHITE;

    constexpr std::chrono::milliseconds snakeSpeed(80);

} // namespace configs