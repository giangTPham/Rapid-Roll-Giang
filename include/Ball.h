#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Common.h"

#define PI 3.1415926535897

class Ball
{
    public:
        Ball(sf::RenderWindow * window, float posX, float posY);

        void update();
        void draw();
        sf::Vector2f getPosition();
        void setPosition(Ball * ball, sf::Vector2f newPos);

        void loadSprite(std::string pathCharacter);
        void moveLeft(sf::Vector2f & ballPos);
        void moveRight(sf::Vector2f & ballPos);

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_ball;
        sf::Sprite m_sprite_ball;

};
#endif // BALL_H
