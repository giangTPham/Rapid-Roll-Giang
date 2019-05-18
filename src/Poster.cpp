#include "Poster.h"

Poster::Poster(sf::RenderWindow * window)
{
    this -> m_window = window;
    this -> m_texture_poster.loadFromFile("Image/hinhnen.png");
    this -> m_texture_poster.setSmooth(true);
    this -> m_sprite_poster.setTexture(this->m_texture_poster);
}

Poster::~Poster()
{
    //dtor
}

void Poster::draw()
{
    this->m_window->draw(this->m_sprite_poster);
}



