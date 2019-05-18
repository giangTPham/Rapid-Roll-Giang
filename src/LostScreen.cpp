#include "LostScreen.h"

LostScreen::LostScreen(sf::RenderWindow * window)
{
    this->m_window = window;

    this->m_texture_lostScreen.loadFromFile("Image/Gameover.png");
    this->m_texture_lostScreen.setSmooth(true);
    this->m_sprite_lostScreen.setTexture(m_texture_lostScreen);

    this->m_font.loadFromFile("Font/Brushsbi.ttf");
    this->m_text_gameover.setFont(this->m_font);
    this->m_text_gameover.setString("GAME OVER");
    this->m_text_gameover.setFillColor(sf::Color::White);

    float width = this->m_window->getSize().x;
    float height = this->m_window->getSize().y;
    this->m_text_gameover.setPosition(width / 4, height / 4);

    this->m_text_score.setFont(this->m_font);
    this->m_text_score.setFillColor(sf::Color::White);
    this->m_text_score.setPosition(width / 4, height / 4 * 2);

    this->m_high_score.setFont(this->m_font);
    this->m_high_score.setFillColor(sf::Color::White);
    this->m_high_score.setPosition(width / 8, height / 4 * 3);



}

void LostScreen::draw(int finalScore)
{
   this->m_window->draw(this->m_sprite_lostScreen);

   int printScore = finalScore - (finalScore % 10);
   this->m_text_score.setString("SCORE: " + std::to_string(printScore));

   this->m_high_score.setString("HIGHSCORE: " + std::to_string(HIGHSCORE));

   this->m_window->draw(this->m_text_gameover);
   this->m_window->draw(this->m_text_score);
   this->m_window->draw(this->m_high_score);

}

