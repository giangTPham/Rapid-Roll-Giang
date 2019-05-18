#ifndef BALLTYPES_H
#define BALLTYPES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Common.h"

#define MAX_CHARACTER 4



class Ball;
class BallTypes
{
    public:
        BallTypes(sf::RenderWindow * window);
        virtual ~BallTypes();

        void update(Ball* ball);

        void draw();

        bool checkChooseCharacter(sf::Sprite sprite);

        void loadSpriteChar(sf::Texture & texture, sf::Sprite & sprite, std::string path, float width, float height);

    private:
        sf::RenderWindow * m_window;

        sf::Texture m_texture_background;
        sf::Sprite m_sprite_background;

        sf::Texture m_texture_character[MAX_CHARACTER];
        sf::Sprite m_sprite_character[MAX_CHARACTER];

        sf::Texture m_texture_character_copy[MAX_CHARACTER];
        sf::Sprite m_sprite_character_copy[MAX_CHARACTER];



};

#endif // BALLTYPES_H
