#include "Crossbar.h"

Crossbar::Crossbar(sf::RenderWindow * window,float yPos)
{
    this->m_window = window;
    this->m_texture_crossbar.loadFromFile("Image/crossbar.png");
    this->m_texture_crossbar.setSmooth(true);
    this->m_sprite_crossbar.setTexture(this->m_texture_crossbar);
    this->m_sprite_crossbar.setOrigin(this->m_texture_crossbar.getSize().x/2, this->m_texture_crossbar.getSize().y/2);
    this->m_sprite_crossbar.setPosition(rand()% 280 + 26, yPos);
}

void Crossbar::update()
{
    m_sprite_crossbar.move(0, -SPEED);

}

void Crossbar::draw()
{
    this->m_window->draw(this->m_sprite_crossbar);
}

sf::Vector2f Crossbar::getPosition()
{
    return this->m_sprite_crossbar.getPosition();
}

