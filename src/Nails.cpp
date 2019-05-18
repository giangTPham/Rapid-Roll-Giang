#include "Nails.h"

Nails::Nails(sf::RenderWindow * window)
{
    this->m_window = window;
    this->m_texture_nails.loadFromFile("Image/nails.png");
    this->m_texture_nails.setSmooth(true);
    this->m_sprite_nails.setTexture(this->m_texture_nails);

}

void Nails::draw()
{
    for (int i = 0; i < 35; i++)
    {
        this->m_sprite_nails.setPosition(10 * i, 30);
        this->m_window->draw(this->m_sprite_nails);
    }
}

