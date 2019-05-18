#ifndef POSTER_H
#define POSTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>

class Poster
{
    public:
        Poster(sf::RenderWindow * window);
        virtual ~Poster();
        void draw();

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_poster;
        sf::Sprite m_sprite_poster;

};

#endif // POSTER_H
