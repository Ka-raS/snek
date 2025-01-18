#pragma once

#include "raylib.h"
#include <chrono>

namespace snek::configs
{
    constexpr int fpsTarget = 60;
    constexpr int windowWidth = 800;
    constexpr int windowHeight = 800;
    constexpr int mapWidth = 20;
    constexpr int mapHeight = 20;
    constexpr int tileSize = 40;

    constexpr const char *windowTitle = "snek";
    constexpr const char *windowIconPath = "resources/icon.png";
    constexpr const char *eatingSoundPath = "resources/eating_sound.wav";

    constexpr Color backgroundColor = BLACK;
    constexpr Color snakeColor = WHITE;
    constexpr Color appleColor = WHITE;

    constexpr float appleThickness = 0.25F * tileSize;
    constexpr std::chrono::milliseconds snakeSpeed(80);

} // namespace configs