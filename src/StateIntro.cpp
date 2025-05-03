#include "StateIntro.h"
#include "StateManager.h"
#include "Globals.h"
#include <iostream>
#include <SFML/Window/Event.hpp>

StateIntro::StateIntro(StateManager *stateManager)
    : BaseState(stateManager), m_title(m_font), m_hintText(m_font), blinkInterval(sf::seconds(0.35f)), blinkTimer(sf::Time::Zero),
      isVisible(true)
{
    if(!m_font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "No found assets/fonts/arial.ttf" << std::endl;
    }

    m_title.setFont(m_font);
    m_title.setString("SFML Snake");
    m_title.setCharacterSize(50);
    m_title.setFillColor(GLOBALS::COLOR_4);
    m_title.setOrigin( sf::Vector2f(m_title.getLocalBounds().size.x / 2, m_title.getLocalBounds().size.y / 2));
    m_title.setPosition(sf::Vector2f(400, 50));

    m_hintText.setFont(m_font);
    m_hintText.setString("Press any key to continue...");
    m_hintText.setCharacterSize(25);
    m_hintText.setFillColor(GLOBALS::COLOR_4);
    m_hintText.setOrigin( sf::Vector2f(m_hintText.getLocalBounds().size.x / 2, m_hintText.getLocalBounds().size.y / 2));
    m_hintText.setPosition(sf::Vector2f(400, 500));
}

StateIntro::~StateIntro()
{

}

void StateIntro::OnCreate()
{

}

void StateIntro::OnDestroy()
{

}

void StateIntro::Activate()
{
}

void StateIntro::Deactivate()
{

}

void StateIntro::Update(const sf::Time &time)
{
    blinkTimer += time;

    if (blinkTimer >= blinkInterval)
    {
        blinkTimer = sf::Time::Zero;

        isVisible = !isVisible;
    }
}

void StateIntro::Draw()
{
    GetStateManager()->GetContext()->m_window->Draw(m_title);
    if(isVisible)
    {
        GetStateManager()->GetContext()->m_window->Draw(m_hintText);
    }
}

void StateIntro::HandlePlayerInput(const std::optional<sf::Event> &event)
{
    if (event->getIf<sf::Event::KeyPressed>())
    {
        m_stateMgr->SwitchTo(StateType::Game);
        m_stateMgr->Remove(StateType::Intro);
    }
}
