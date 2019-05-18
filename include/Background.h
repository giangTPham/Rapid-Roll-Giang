#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

class Background
{
    public:
        Background(sf::RenderWindow * window);
        virtual ~Background();
        void draw();
    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_background;
        sf::Sprite m_sprite_background;

};

#endif // BACKGROUND_H
