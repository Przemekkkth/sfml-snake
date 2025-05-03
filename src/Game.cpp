#include "Game.h"
#include <iostream>
int Game::LEVEL = 15;

Game::Game()
    : m_elapsed(0.0f), m_stateManager(&m_context)
{
    m_clock.restart();
    srand(time(nullptr));
    m_context.m_window = &m_window;
    m_stateManager.SwitchTo(StateType::Intro);
}

Game::~Game()
{

}

sf::Time Game::GetElapsed()
{
    return m_clock.getElapsedTime();
}

void Game::RestartClock()
{
    m_elapsed += m_clock.restart().asSeconds();
}

Window* Game::GetWindow()
{
    return &m_window;
}

void Game::HandleInput()
{
    while (const std::optional event = GetWindow()->GetRenderWindow()->pollEvent())
    {
        GetWindow()->HandlePlayerInputs(event);
        m_world.HandlePlayerInput(event);
        m_stateManager.HandlePlayerInput(event);
    }
}

void Game::Update()
{
    float timestep = 1.0f / Game::LEVEL;

    if(m_elapsed >= timestep){
        m_stateManager.Update(sf::seconds(timestep));
        m_elapsed -= timestep;
    }
}

void Game::Render()
{
    m_window.BeginDraw();
    m_stateManager.Draw();
    m_window.EndDraw();
}

void Game::LateUpdate()
{
    m_stateManager.ProcessRequests();
    RestartClock();
}
