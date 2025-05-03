#ifndef GAME_H
#define GAME_H
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include "SharedContext.h"
#include "StateManager.h"
#include "Window.h"
#include "World.h"

class Game {
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    void LateUpdate();

    sf::Time GetElapsed();
    void RestartClock();

    Window* GetWindow();
    static int LEVEL;
private:
    SharedContext m_context;
    Window m_window;
    StateManager m_stateManager;
    World m_world;
    sf::Clock m_clock;
    float m_elapsed;
};


#endif // GAME_H
