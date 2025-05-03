#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using MessageContainer = std::vector<sf::String>;

class Textbox
{
public:
    Textbox(int visible = 5, int charSize = 9, int width = 200, sf::Vector2f screenPos = sf::Vector2f(0,0));
    ~Textbox();

    void Setup(int visible, int charSize,
               int width, sf::Vector2f screenPos);
    void Add(const sf::String& message);
    void Clear();

    void Render(sf::RenderWindow& window);
    void SetPosiotion(sf::Vector2f newPos);
private:
    MessageContainer m_messages;
    int m_numVisible;

    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_content;
};

#endif // TEXTBOX_H
