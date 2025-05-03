#include "StatePause.h"
#include "Globals.h"
#include "StateManager.h"
#include <iostream>

StatePause::StatePause(StateManager *stateManager)
    : BaseState(stateManager), m_title(m_font), m_hintText(m_font)
{
    SetTransparent(true);
    if(!m_font.openFromFile("assets/fonts/arial.ttf"))
    {
        std::cerr << "No found assets/fonts/arial.ttf" << std::endl;
    }

    m_title.setFont(m_font);
    m_title.setString("Game Paused");
    m_title.setCharacterSize(50);
    m_title.setFillColor(GLOBALS::COLOR_4);
    m_title.setOrigin( sf::Vector2f(m_title.getLocalBounds().size.x / 2, m_title.getLocalBounds().size.y / 2));
    m_title.setPosition(sf::Vector2f(400, 50));

    m_hintText.setFont(m_font);
    m_hintText.setString("Press 'P' key to unpause...");
    m_hintText.setCharacterSize(25);
    m_hintText.setFillColor(GLOBALS::COLOR_4);
    m_hintText.setOrigin( sf::Vector2f(m_hintText.getLocalBounds().size.x / 2, m_hintText.getLocalBounds().size.y / 2));
    m_hintText.setPosition(sf::Vector2f(400, 500));
}

StatePause::~StatePause()
{

}

void StatePause::OnCreate()
{

}

void StatePause::OnDestroy()
{

}

void StatePause::Activate()
{

}

void StatePause::Deactivate()
{

}

void StatePause::Update(const sf::Time &time)
{

}

void StatePause::Draw()
{
    GetStateManager()->GetContext()->m_window->Draw(m_title);
    GetStateManager()->GetContext()->m_window->Draw(m_hintText);

}

void StatePause::HandlePlayerInput(const std::optional<sf::Event> &event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {

        if (keyPressed->scancode == sf::Keyboard::Scancode::P)
        {
            m_stateMgr->SwitchTo(StateType::Game);
        }
    }
}
