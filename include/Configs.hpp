#pragma once

#include "raylib.h"

namespace snek::configs
{
    constexpr inline int fpsTarget = 60;
    constexpr inline int windowWidth = 800;
    constexpr inline int windowHeight = 800;
    
    constexpr inline int mapWidth = 20;
    constexpr inline int mapHeight = 20;
    constexpr inline int tileSize = 40;

    constexpr inline const char *windowTitle = "snek";
    constexpr inline const char *windowIconPath = "resources/icon.png";
    constexpr inline const char *eatingSoundPath = "resources/eating_sound.wav";

    constexpr inline Color backgroundColor = BLACK;
    constexpr inline Color snakeColor = WHITE;
    constexpr inline Color appleColor = WHITE;

    constexpr inline float appleThickness = 0.25F * tileSize;
    constexpr inline float snakeSpeed = 8.0F; // tiles per second

} // namespace configs