#ifndef LIFEAID_H
#define LIFEAID_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Common.h"

class LifeAid
{
    public:
        LifeAid(sf::RenderWindow * window);
        void setPosition(float newPosX, float newPosY);
        void update();
        void draw();
        sf::Vector2f getPosition();

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_LifeAid;
        sf::Sprite m_sprite_LifeAid;
};

#endif // LIFEAID_H
