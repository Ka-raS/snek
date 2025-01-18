#include "Game.hpp"
#include "Snake.hpp"
#include "Apple.hpp"
#include "Configs.hpp"

#include "raylib.h"
#include <chrono>

namespace snek
{
    Game::Game()
        : m_windowIcon(LoadImage(configs::windowIconPath))
    {
        SetTargetFPS(configs::fpsTarget);
        InitWindow(configs::windowWidth, configs::windowHeight, configs::windowTitle);
        SetWindowIcon(m_windowIcon);
        InitAudioDevice();
        m_eatingSound = LoadSound(configs::eatingSoundPath);
    }

    Game::~Game()
    {
        UnloadImage(m_windowIcon);
        UnloadSound(m_eatingSound);
        CloseWindow();
    }

    void Game::Run()
    {
        while (!WindowShouldClose())
        {
            update();
            render();
        }
    }

    void Game::update()
    {
        handleInput();
        if (hasEnoughTimePassed())
        {
            if (m_snake.isValidDirection(m_nextSnakeDirection))
                m_snake.setDirection(m_nextSnakeDirection);
            m_snake.move();
            handleCollision();
        }
    }

    void Game::render() const
    {
        BeginDrawing();
        ClearBackground(configs::backgroundColor);
        m_snake.render();
        m_apple.render();
        EndDrawing();
    }

    bool Game::hasEnoughTimePassed()
    {
        static std::chrono::time_point previous = std::chrono::steady_clock::now();
        const std::chrono::time_point now = std::chrono::steady_clock::now();
        const std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - previous);

        if (elapsed >= configs::snakeSpeed)
        {
            previous = now;
            return true;
        }
        return false;
    }

    void Game::handleInput()
    {
        switch (GetKeyPressed())
        {
        case KeyboardKey::KEY_UP:
            m_nextSnakeDirection = Direction::Up;
            break;

        case KeyboardKey::KEY_DOWN:
            m_nextSnakeDirection = Direction::Down;
            break;

        case KeyboardKey::KEY_LEFT:
            m_nextSnakeDirection = Direction::Left;
            break;

        case KeyboardKey::KEY_RIGHT:
            m_nextSnakeDirection = Direction::Right;
            break;

        default:
            break;
        }
    }

    void Game::handleCollision()
    {
        if (m_snake.isCollisionWith(m_apple.getPosition()))
        {
            PlaySound(m_eatingSound);
            m_apple.reset(m_snake.getPosition());
            m_snake.grow();
        }
        else if (m_snake.isSelfCollision())
        {
            m_snake.reset();
            m_apple.reset(m_snake.getPosition());
            m_nextSnakeDirection = Direction::None;
        }
    }

} // namespace snek