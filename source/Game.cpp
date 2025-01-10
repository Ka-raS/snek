#include "Game.hpp"
#include "Config.hpp"
#include "raylib.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
    const char *ptr = "bruh";
    ptr[0] = '0';
    ptr = "str";

    InitWindow(config::windowWidth, config::windowHeight, config::windowTitle);
}
