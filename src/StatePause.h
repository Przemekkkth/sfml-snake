#ifndef STATEPAUSE_H
#define STATEPAUSE_H
#include "BaseState.h"

class StatePause : public BaseState
{
public:
    StatePause(StateManager* stateManager);
    ~StatePause();

    virtual void OnCreate() override;
    virtual void OnDestroy() override;
    virtual void Activate() override;
    virtual void Deactivate() override;
    virtual void Update(const sf::Time &time) override;
    virtual void Draw() override;
    virtual void HandlePlayerInput(const std::optional<sf::Event> &event) override;

private:
    sf::Text m_title;
    sf::Text m_hintText;
    sf::Font m_font;
};

#endif // STATEPAUSE_H
