#include "StartScreen.h"

StartScreen::StartScreen(sf::RenderWindow * window)
{
    this->m_window = window;
    this->m_texture_startScreen.loadFromFile("Image/hinhnen.png");
    this->m_texture_startScreen.setSmooth(true);
    this->m_sprite_startScreen.setTexture(this->m_texture_startScreen);

}

StartScreen::~StartScreen()
{
    //dtor
}

void StartScreen::draw()
{
    this->m_window->draw(this->m_sprite_startScreen);
}
