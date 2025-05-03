#ifndef SHAREDCONTEXT_H
#define SHAREDCONTEXT_H

#include "Window.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>

struct SharedContext{
    SharedContext()
        : m_window(nullptr)
    {
        if(!m_bgMusic.openFromFile("assets/music/alex_gameboy.wav"))
        {
            std::cerr << "Not found assets/music/alex_gameboy.wav" << std::endl;
        }
        m_bgMusic.setVolume(50.f);

        if(!m_pickUpSFXBuffer.loadFromFile("assets/sounds/pick_up.ogg"))
        {
            std::cerr << "Not found assets/sounds/pick_up.ogg" << std::endl;
        }
        m_pickUpSFX = new sf::Sound(m_pickUpSFXBuffer);

        if(!m_deathSFXBuffer.loadFromFile("assets/sounds/hit.ogg"))
        {
            std::cerr << "Not found assets/sounds/hit.ogg" << std::endl;
        }
        m_deathSFX = new sf::Sound(m_deathSFXBuffer);
    }

    ~SharedContext() {
        delete m_pickUpSFX;
        delete m_deathSFX;
    }

    Window* m_window;
    sf::Music m_bgMusic;
    sf::Sound *m_pickUpSFX;
    sf::SoundBuffer m_pickUpSFXBuffer;
    sf::Sound *m_deathSFX;
    sf::SoundBuffer m_deathSFXBuffer;
};

#endif // SHAREDCONTEXT_H
