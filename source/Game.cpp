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
    InitWindow(config::windowWidth, config::windowHeight, config::windowTitle);
}
