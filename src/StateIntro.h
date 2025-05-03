#ifndef STATEINTRO_H
#define STATEINTRO_H
#include "BaseState.h"
#include <SFML/Graphics/Text.hpp>

class StateIntro : public BaseState
{
public:
    StateIntro(StateManager* stateManager);
    ~StateIntro();

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
    sf::Time blinkInterval;
    sf::Time blinkTimer;
    bool isVisible;
};

#endif // STATEINTRO_H
