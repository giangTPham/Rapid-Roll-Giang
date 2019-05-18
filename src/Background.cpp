#include "Background.h"

Background::Background(sf::RenderWindow * window)
{
    this->m_window = window;
    this->m_texture_background.loadFromFile("Image/background_1.png");
    this->m_texture_background.setSmooth(true);
    this->m_sprite_background.setTexture(this->m_texture_background);

}

Background::~Background()
{

}

void Background::draw()
{
    this->m_window->draw(this->m_sprite_background);
}

