#include "BallTypes.h"
#include "Ball.h"
BallTypes::BallTypes(sf::RenderWindow * window)
{
    this->m_window = window;

    this->m_texture_background.loadFromFile("Image/BackgroundChooseBall.png");
    this->m_texture_background.setSmooth(true);
    this->m_sprite_background.setTexture(this->m_texture_background);

    float width = this->m_window->getSize().x;
    float height = this->m_window->getSize().y;

    loadSpriteChar(this->m_texture_character[0], this->m_sprite_character[0] , "Image/duongtangChonBong.png", width / 4, height / 3);

    loadSpriteChar(this->m_texture_character[1], this->m_sprite_character[1] , "Image/tonngokhongChonBong.png", width / 4 * 3, height / 3);

    loadSpriteChar(this->m_texture_character[2], this->m_sprite_character[2] , "Image/trubatgioiChonBong.png", width / 4, height / 3 * 2);

    loadSpriteChar(this->m_texture_character[3], this->m_sprite_character[3] , "Image/satangChonBong.png", width / 4 * 3, height / 3 * 2);

    loadSpriteChar(this->m_texture_character_copy[0], this->m_sprite_character_copy[0] , "Image/duongtangChonBong - Copy.png", width / 4, height / 3);

    loadSpriteChar(this->m_texture_character_copy[1], this->m_sprite_character_copy[1] , "Image/tonngokhongChonBong - Copy.png", width / 4*3, height / 3);

    loadSpriteChar(this->m_texture_character_copy[2], this->m_sprite_character_copy[2] , "Image/trubatgioiChonBong - Copy.png", width / 4, height / 3*2);

    loadSpriteChar(this->m_texture_character_copy[3], this->m_sprite_character_copy[3] , "Image/satangChonBong - Copy.png", width / 4*3, height / 3*2);

}

BallTypes::~BallTypes()
{
    //dtor
}

void BallTypes::update(Ball* ball)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(checkChooseCharacter(this->m_sprite_character[0])) CHARACTER = 0;
        if (checkChooseCharacter(this->m_sprite_character[1])) CHARACTER = 1;
        if (checkChooseCharacter(this->m_sprite_character[2])) CHARACTER = 2;
        if (checkChooseCharacter(this->m_sprite_character[3])) CHARACTER = 3;
    }
    ball->loadSprite(characterPath[CHARACTER]);
}

void BallTypes::draw()
{
    this->m_window->draw(this->m_sprite_background);
    for (int i = 0; i < MAX_CHARACTER; i++)
    {
        this->m_window->draw(this->m_sprite_character[i]);
    }

    for (int i = 0; i < MAX_CHARACTER; i++)
    {
        if (checkChooseCharacter(this->m_sprite_character_copy[i]))
            this->m_window->draw(this->m_sprite_character_copy[i]);
    }
}

bool BallTypes::checkChooseCharacter(sf::Sprite sprite)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*(this->m_window));

        int distanceX = abs(sprite.getPosition().x - mousePos.x);
        int distanceY = abs(sprite.getPosition().y - mousePos.y);
        return (distanceX < 50 and distanceY < 60);

}

void BallTypes::loadSpriteChar(sf::Texture & texture, sf::Sprite & sprite, std::string path, float width, float height)
{
    texture.loadFromFile(path);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(width, height);
}



