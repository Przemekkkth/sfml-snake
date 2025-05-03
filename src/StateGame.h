#ifndef STATEGAME_H
#define STATEGAME_H
#include "BaseState.h"
#include "World.h"

class StateGame : public BaseState
{
public:
    StateGame(StateManager* stateManager);
    ~StateGame();

    virtual void OnCreate() override;
    virtual void OnDestroy() override;
    virtual void Activate() override;
    virtual void Deactivate() override;
    virtual void Update(const sf::Time &time) override;
    virtual void Draw() override;
    virtual void HandlePlayerInput(const std::optional<sf::Event> &event) override;
private:
    World *m_world;
};

#endif // STATEGAME_H
