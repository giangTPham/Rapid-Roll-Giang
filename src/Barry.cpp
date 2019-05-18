#include "Barry.h"

Barry::Barry(sf::RenderWindow * window, float yPos)
{
    this->m_window = window;
    this->m_texture_barry.loadFromFile("Image/barry.png");
    this->m_texture_barry.setSmooth(true);
    this->m_sprite_barry.setTexture(this->m_texture_barry);
    this->m_sprite_barry.setOrigin(this->m_texture_barry.getSize().x/2, this->m_texture_barry.getSize().y/2);
    this->m_sprite_barry.setPosition(rand() % 280 + 26, yPos);


}

void Barry::update()
{
    this->m_sprite_barry.move(0, -SPEED);


}

void Barry::draw()
{
    this->m_window->draw(this->m_sprite_barry);
}

sf::Vector2f Barry::getPosition()
{
    return this->m_sprite_barry.getPosition();
}
