#include "World.h"
#include "Globals.h"
#include "Game.h"
#include "SharedContext.h"
#include <iostream>

World::World(SharedContext *sharedContext)
    : m_score(0), m_sharedContext(sharedContext)
{
    int windowWidth = GLOBALS::WINDOW_SIZE.x;
    int windowHeight = GLOBALS::WINDOW_SIZE.y;
    int size = GLOBALS::CELL_SIZE;

    m_boundaries[0].setPosition(sf::Vector2f(0, 0));
    m_boundaries[0].setSize(sf::Vector2f(windowWidth, size));
    m_boundaries[0].setFillColor(GLOBALS::BOUNDARY_COLOR);

    m_boundaries[1].setPosition(sf::Vector2f(0, 0));
    m_boundaries[1].setSize(sf::Vector2f(size, windowHeight));
    m_boundaries[1].setFillColor(GLOBALS::BOUNDARY_COLOR);

    m_boundaries[2].setPosition(sf::Vector2f(0, windowHeight - 1.5*size));
    m_boundaries[2].setSize(sf::Vector2f(windowWidth, 1.5 * size));
    m_boundaries[2].setFillColor(GLOBALS::BOUNDARY_COLOR);

    m_boundaries[3].setPosition(sf::Vector2f(windowWidth - size, 0));
    m_boundaries[3].setSize(sf::Vector2f(size, windowHeight));
    m_boundaries[3].setFillColor(GLOBALS::BOUNDARY_COLOR);

    m_apple.setFillColor(GLOBALS::APPLE_COLOR);
    m_apple.setRadius(size / 2);

    m_log.SetPosiotion(sf::Vector2f(590, 535));
    RespawnApple();
}

void World::HandlePlayerInput(const std::optional<sf::Event> &event)
{
    m_snake.HandlePlayerInput(event);
}

void World::Update()
{
    int windowWidth = GLOBALS::WINDOW_SIZE.x;
    int windowHeight = GLOBALS::WINDOW_SIZE.y;
    int size = GLOBALS::CELL_SIZE;

    m_snake.Tick();

    if( m_snake.GetPosition().x == (sf::Vector2i(m_apple.getPosition()).x / size)
        &&
        m_snake.GetPosition().y == (sf::Vector2i(m_apple.getPosition()).y / size) )
    {
        m_snake.Extend();
        m_snake.IncreaseScore();
        m_score++;
        RespawnApple();
        Game::LEVEL++;
        m_log.Add(sf::String("You ate an apple. Score: ") + sf::String(std::to_string(m_score)));
        m_sharedContext->m_pickUpSFX->play();
    }

    int gridSize_x = windowWidth / size;
    int gridSize_y = windowHeight / size;

    if( m_snake.GetPosition().x <= 0 ||
        m_snake.GetPosition().y <= 0 ||
        m_snake.GetPosition().x >= gridSize_x - 1 ||
        m_snake.GetPosition().y >= gridSize_y - 1)
    {
        m_snake.Lose();
    }

    if(m_snake.HasLost()) {
        m_snake.Reset();
        m_score = 0;
        Game::LEVEL = 15;
        m_sharedContext->m_deathSFX->play();
    }
}

void World::Render(sf::RenderWindow& window)
{
    window.draw(m_boundaries[0]);
    window.draw(m_boundaries[1]);
    window.draw(m_boundaries[2]);
    window.draw(m_boundaries[3]);
    window.draw(m_apple);
    m_log.Render(window);
    m_snake.Render(window);
}

void World::RespawnApple()
{
    int windowWidth = GLOBALS::WINDOW_SIZE.x;
    int windowHeight = GLOBALS::WINDOW_SIZE.y;
    int size = GLOBALS::CELL_SIZE;

    int maxX = (windowWidth / size) - 2;
    int maxY = (windowHeight / size) - 2;
    m_apple.setPosition(sf::Vector2f(float((rand() % maxX + 1) * size), float((rand() % maxY + 1)) * size));
}

int World::Level()
{
    return m_snake.GetSpeed() + m_score;
}
