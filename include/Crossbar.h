#ifndef CROSSBAR_H
#define CROSSBAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Common.h"

class Crossbar
{
    public:
        Crossbar(sf::RenderWindow * window, float yPos);
        void update();
        void draw();
        sf::Vector2f getPosition();


    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_crossbar;
        sf::Sprite m_sprite_crossbar;
};

#endif // CROSSBAR_H
