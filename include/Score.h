#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <Common.h>

class Score
{
    public:
        Score(sf::RenderWindow * window);
        double& calculateScore();
        int printScore();
        void update();
        void draw();

    private:
        sf::RenderWindow * m_window;
        double score;

        sf::Font m_font_score;
        sf::Text m_text_score;

};

#endif // SCORE_H
