#ifndef HEART_H
#define HEART_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

class Heart
{
    public:
        Heart(sf::RenderWindow * window);
        int& countHeart();
        void draw();

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_heart;
        sf::Sprite m_sprite_heart;
        int heartNumber;
};

#endif // HEART_H
