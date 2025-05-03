#ifndef WORLD_H
#define WORLD_H
#include <optional>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Snake.h"
#include "TextBox.h"

class SharedContext;
class World
{
public:
    World(SharedContext* sharedContext = nullptr);
    void HandlePlayerInput(const std::optional<sf::Event>& event);
    void Update();
    void Render(sf::RenderWindow& window);
    void RespawnApple();
    int Level();
private:
    sf::RectangleShape m_boundaries[4];
    Snake m_snake;
    sf::CircleShape m_apple;
    int m_score;
    Textbox m_log;
    SharedContext* m_sharedContext;
};

#endif // WORLD_H
