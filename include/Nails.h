#ifndef NAILS_H
#define NAILS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

class Nails
{
    public:
        Nails(sf::RenderWindow * window);
        void draw();

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_nails;
        sf::Sprite m_sprite_nails;

};

#endif // NAILS_H
