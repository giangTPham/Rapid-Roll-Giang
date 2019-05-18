#include "Ball.h"

Ball::Ball(sf::RenderWindow *window, float posX, float posY)
{
    this->m_window = window;
    loadSprite(characterPath[CHARACTER]);
    this->m_sprite_ball.setPosition(posX, posY);

}

void Ball::update()
{
    this->m_sprite_ball.move(0, SPEED);

    sf::Vector2f ballPos = m_sprite_ball.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        moveLeft(ballPos);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        moveRight(ballPos);
    }
    this->m_sprite_ball.setPosition(ballPos.x, ballPos.y);

    if (this->m_sprite_ball.getPosition().x <= this->m_texture_ball.getSize().x / 2)
        ballPos.x = this->m_texture_ball.getSize().x / 2;
    if (this->m_sprite_ball.getPosition().x >= this->m_window->getSize().x - this->m_texture_ball.getSize().x/2)
        ballPos.x = this->m_window->getSize().x - m_texture_ball.getSize().x/2;
    this->m_sprite_ball.setPosition(ballPos.x, ballPos.y);

}

void Ball::draw()
{

    this->m_window->draw(this->m_sprite_ball);

}

sf::Vector2f Ball::getPosition()
{
    return this->m_sprite_ball.getPosition();
}

void Ball::setPosition(Ball * ball, sf::Vector2f newPos)
{
    ball->m_sprite_ball.setPosition(newPos.x, newPos.y);
}

void Ball::loadSprite(std::string pathCharacter)
{
    this->m_texture_ball.loadFromFile(pathCharacter);
    this->m_texture_ball.setSmooth(true);
    this->m_sprite_ball.setTexture(this->m_texture_ball);
    this->m_sprite_ball.setOrigin(this->m_texture_ball.getSize().x / 2, this->m_texture_ball.getSize().y / 2);
}

void Ball::moveLeft(sf::Vector2f & ballPos)
{
        this->m_sprite_ball.rotate(-(SPEED / 8) * 180 / PI);
        ballPos.x -= SPEED;
}

void Ball::moveRight(sf::Vector2f & ballPos)
{
        this->m_sprite_ball.rotate((SPEED / 8) * 180 / PI);
        ballPos.x += SPEED;
}


