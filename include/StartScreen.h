#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>

class StartScreen
{
    public:
        StartScreen(sf::RenderWindow * window);
        virtual ~StartScreen();
        void draw();

    private:
        sf::RenderWindow* m_window;
        sf::Texture m_texture_startScreen;
        sf::Sprite m_sprite_startScreen;

};

#endif // STARTSCREEN_H
