#include "StateGame.h"
#include "StateManager.h"
#include "Globals.h"
#include "Game.h"
#include <SFML/Window/Event.hpp>


StateGame::StateGame(StateManager *stateManager)
    : BaseState(stateManager)
{

}

StateGame::~StateGame()
{

}

void StateGame::OnCreate()
{
    m_world = new World(GetStateManager()->GetContext());
    GetStateManager()->GetContext()->m_bgMusic.play();
}

void StateGame::OnDestroy()
{
    delete m_world;
    Game::LEVEL = 15;
    GetStateManager()->GetContext()->m_bgMusic.stop();
}

void StateGame::Activate()
{

}

void StateGame::Deactivate()
{

}

void StateGame::Update(const sf::Time &time)
{
    m_world->Update();
}

void StateGame::Draw()
{
    sf::RenderWindow* window = GetStateManager()->GetContext()->m_window->GetRenderWindow();
    m_world->Render(*window);
}

void StateGame::HandlePlayerInput(const std::optional<sf::Event> &event)
{
    m_world->HandlePlayerInput(event);
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
        {
            m_stateMgr->SwitchTo(StateType::Intro);
            m_stateMgr->Remove(StateType::Game);
        }
        else if (keyPressed->scancode == sf::Keyboard::Scancode::P)
        {
            m_stateMgr->SwitchTo(StateType::Paused);
        }
    }
}
