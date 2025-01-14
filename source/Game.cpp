#include "Game.hpp"
#include "Configs.hpp"
#include "raylib.h"

#include <iostream>

Game::Game() : m_windowIcon(LoadImage(configs::windowIconPath.string().c_str()))
{
    SetConfigFlags(configs::windowInitConfig);
    SetTargetFPS(configs::fpsTarget);

    InitWindow(configs::windowInitWidth, configs::windowInitHeight, configs::windowTitle);

    SetWindowIcon(m_windowIcon);
}

Game::~Game()
{
    UnloadImage(m_windowIcon);
    CloseWindow();
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        Update();
        }
}

void Game::Update()
{
    BeginDrawing();
    ClearBackground(configs::backgroundColor);
    EndDrawing();
}