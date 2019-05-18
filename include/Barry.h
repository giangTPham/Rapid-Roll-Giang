#ifndef BARRY_H
#define BARRY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Common.h"

class Barry
{
    public:
        Barry(sf::RenderWindow * window, float yPos);
        void update();
        void draw();
        sf::Vector2f getPosition();

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_barry;
        sf::Sprite m_sprite_barry;

};

#endif // BARRY_H
