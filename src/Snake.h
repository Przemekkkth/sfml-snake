#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <optional>

struct SnakeSegment {
    SnakeSegment(int x, int y)
        : position(x, y)
    {}
    sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;
enum class Direction {None, Up, Down, Left, Right};

class Snake
{
public:
    Snake();
    ~Snake();

    void SetDirection(Direction dir);
    Direction GetDirection();
    int GetSpeed();
    sf::Vector2i GetPosition();
    int GetLives();
    int GetScore();
    void IncreaseScore();
    bool HasLost();
    void HandlePlayerInput(const std::optional<sf::Event>& event);

    void Lose();
    void ToggleLost();

    Direction GetPhysicalDirection();

    void Extend();
    void Reset();

    void Move();
    void Tick();
    void Cut(int segments);
    void Render(sf::RenderWindow& window);
private:
    void CheckCollision();

    SnakeContainer m_snakeBody;
    int m_size;
    Direction m_dir;
    int m_speed;
    int m_lives;
    int m_score;
    bool m_lost;
    sf::RectangleShape m_bodyRect;
    //Textbox* m_log;
};

#endif // SNAKE_H
