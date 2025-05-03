#include "TextBox.h"
#include <cstdlib>
#include <iostream>

Textbox::Textbox(int visible, int charSize, int width, sf::Vector2f screenPos)
    : m_content(m_font)
{
    Setup(visible, charSize, width, screenPos);
}

Textbox::~Textbox()
{
    Clear();
}

void Textbox::Setup(int visible, int charSize, int width, sf::Vector2f screenPos)
{
    m_numVisible = visible;

    sf::Vector2f offset(2.0f, 2.0f);

    if(!m_font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "No found assets/fonts/arial.ttf" << std::endl;
    }

    m_content.setFont(m_font);
    m_content.setString("");
    m_content.setCharacterSize(charSize);
    m_content.setFillColor(sf::Color::White);
    m_content.setPosition(screenPos + offset);

    m_backdrop.setSize(sf::Vector2f(width, (visible * (charSize * 1.2f))));
    m_backdrop.setFillColor(sf::Color(90,90,90,90));
    m_backdrop.setPosition(screenPos);
}

void Textbox::Add(const sf::String &message)
{
    m_messages.push_back(message);
    if (m_messages.size() < 6)
    {
        return;
    }
    m_messages.erase(m_messages.begin());
}

void Textbox::Clear()
{
    m_messages.clear();
}

void Textbox::Render(sf::RenderWindow &window)
{
    sf::String l_content;

    for(auto &itr : m_messages)
    {
        l_content += (itr + sf::String("\n"));
    }

    if(l_content != ""){
        m_content.setString(l_content);
        window.draw(m_backdrop);
        window.draw(m_content);
    }
}

void Textbox::SetPosiotion(sf::Vector2f newPos)
{
    sf::Vector2f offset(2.0f, 2.0f);
    m_content.setPosition(newPos + offset);
    m_backdrop.setPosition(newPos);
}
