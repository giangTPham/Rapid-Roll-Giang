#ifndef LOSTSCREEN_H
#define LOSTSCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Score.h"
#include "Game.h"
#include "Score.h"
#include "Common.h"

class LostScreen
{
public:
    LostScreen(sf::RenderWindow * window);
    void draw(int finalScore);
private:
    sf::RenderWindow * m_window;
    sf::Texture m_texture_lostScreen;
    sf::Sprite m_sprite_lostScreen;

    sf::Font m_font;
    sf::Text m_text_gameover;

    sf::Text m_text_score;

    sf::Text m_high_score;






};

#endif // LOSTSCREEN_H
