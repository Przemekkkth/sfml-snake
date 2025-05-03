#ifndef GLOBALS_H
#define GLOBALS_H
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>

namespace GLOBALS {
//LATE NIGHT BATH PALETTE
    const sf::Color COLOR_0 = sf::Color(40, 45, 60);
    const sf::Color COLOR_1 = sf::Color(91, 93, 112);
    const sf::Color COLOR_2 = sf::Color(116, 131, 140);
    const sf::Color COLOR_3 = sf::Color(255, 196, 184);
    const sf::Color COLOR_4 = sf::Color(246, 145, 151);
////

    const sf::Color WINDOW_COLOR = COLOR_2;
    const sf::Color BOUNDARY_COLOR = COLOR_0;
    const sf::Color BODY_COLOR  = COLOR_1;
    const sf::Color HEAD_COLOR  = COLOR_3;
    const sf::Color APPLE_COLOR = COLOR_4;

    const sf::Vector2u WINDOW_SIZE(800, 600);
    const sf::String WINDOW_TITLE("SFML-SNAKE");
    const unsigned int CELL_SIZE = 16;
}

#endif // GLOBALS_H

