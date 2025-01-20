#include "Game.hpp"
#include "Snake.hpp"
#include "Apple.hpp"
#include "Configs.hpp"

#include "raylib.h"
#include <chrono>

namespace snek
{
    Game::Game() : 
        m_isRunning(true),
        m_snakeNextDirection(Direction::None),
        m_lastUpdate(std::chrono::steady_clock::now()),
        m_windowIcon(LoadImage(configs::windowIconPath))
    {
        SetTargetFPS(configs::fpsTarget);
        InitWindow(configs::windowWidth, configs::windowHeight, configs::windowTitle);
        SetWindowIcon(m_windowIcon);

        InitAudioDevice();
        m_eatingSound = LoadSound(configs::eatingSoundPath); // must call InitAudioDevice() first
    }

    Game::~Game()
    {
        UnloadImage(m_windowIcon);
        UnloadSound(m_eatingSound);
        CloseAudioDevice();
        CloseWindow();
    }

    void Game::Run()
    {
        startNewGame();
        while (!WindowShouldClose())
        {
            update();
            if (!m_isRunning)
                startNewGame();
            render();
        }
    }

    void Game::update()
    {
        handleInput();
        if (!hasEnoughTimePassed())
            return;
        
        m_snake.setDirection(m_snakeNextDirection);
        m_snake.growFront();
        handleCollision();
    }

    void Game::render() const
    {
        BeginDrawing();
        ClearBackground(configs::backgroundColor);
        m_snake.render();
        m_apple.render();
        EndDrawing();
    }

    void Game::startNewGame()
    {
        m_snake.reset();
        m_apple.reset(m_snake.getPosition());
        m_snakeNextDirection = Direction::None;
        m_isRunning = true;
    }

    void Game::handleInput()
    {
        switch (GetKeyPressed())
        {
        case KeyboardKey::KEY_UP:
            m_snakeNextDirection = Direction::Up;
            break;

        case KeyboardKey::KEY_DOWN:
            m_snakeNextDirection = Direction::Down;
            break;

        case KeyboardKey::KEY_LEFT:
            m_snakeNextDirection = Direction::Left;
            break;

        case KeyboardKey::KEY_RIGHT:
            m_snakeNextDirection = Direction::Right;
            break;

        default:
            break;
        }
    }

    void Game::handleCollision()
    {
        switch (m_snake.checkCollision(m_apple.getPosition()))
        {
        case Collision::None:
            m_snake.shrinkBack();
            break;

        case Collision::Apple:
            PlaySound(m_eatingSound);
            m_apple.reset(m_snake.getPosition());
            break;
        
        case Collision::Snake:
            m_isRunning = false;

        default:
            break;
        }
    }

    bool Game::hasEnoughTimePassed()
    {
        const auto now = std::chrono::steady_clock::now();
        const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastUpdate);
        constexpr static float minTime = 1000.0F / configs::snakeSpeed;

        if (elapsed.count() >= minTime)
        {
            m_lastUpdate = now;
            return true;
        }
        return false;
    }

} // namespace snek