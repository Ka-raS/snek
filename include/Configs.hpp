#pragma once

#include "raylib.h"

namespace snek::configs
{
    constexpr int fpsTarget = 60;
    constexpr int windowWidth = 800;
    constexpr int windowHeight = 800;
    
    constexpr int mapWidth = 20;
    constexpr int mapHeight = 20;
    constexpr int tileSize = 40;

    constexpr inline const char *windowTitle = "snek";
    constexpr inline const char *windowIconPath = "resources/icon.png";
    constexpr inline const char *eatingSoundPath = "resources/eating_sound.wav";

    constexpr inline Color backgroundColor = BLACK;
    constexpr inline Color snakeColor = WHITE;
    constexpr inline Color appleColor = WHITE;

    constexpr float appleThickness = 0.25F * tileSize;
    constexpr float snakeSpeed = 8.0F; // tiles per second

} // namespace configs
