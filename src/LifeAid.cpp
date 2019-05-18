#include "LifeAid.h"

LifeAid::LifeAid(sf::RenderWindow * window)
{
    this->m_window = window;
    this->m_texture_LifeAid.loadFromFile("Image/heart.png");
    this->m_texture_LifeAid.setSmooth(true);
    this->m_sprite_LifeAid.setTexture(m_texture_LifeAid);
    this->m_sprite_LifeAid.setOrigin(this->m_texture_LifeAid.getSize().x/2, this->m_texture_LifeAid.getSize().y/2);

}

void LifeAid::setPosition(float newPosX, float newPosY)
{
    this->m_sprite_LifeAid.setPosition(newPosX, newPosY);
}

void LifeAid::update()
{
    this->m_sprite_LifeAid.move(0, -SPEED);
}

void LifeAid::draw()
{
    this->m_window->draw(this->m_sprite_LifeAid);
}

sf::Vector2f LifeAid::getPosition()
{
    return this->m_sprite_LifeAid.getPosition();
}

