#include "Heart.h"

Heart::Heart(sf::RenderWindow * window): heartNumber(2)
{
    this->m_window = window;
    this->m_texture_heart.loadFromFile("Image/heart.png");
    this->m_texture_heart.setSmooth(true);
    this->m_sprite_heart.setTexture(this->m_texture_heart);

}

int& Heart::countHeart()
{
    return this->heartNumber;
}

void Heart::draw()
{
    for (int itHeart = 0; itHeart < countHeart(); itHeart++)
    {
        this->m_sprite_heart.setPosition(12 * itHeart, 9.5);
        this->m_window->draw(this->m_sprite_heart);
    }
}
