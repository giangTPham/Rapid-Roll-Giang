#include "Score.h"

Score::Score(sf::RenderWindow * window): score(0)
{
  this->m_window = window;
  this->m_font_score.loadFromFile("Font/Brushsbi.ttf");
  this->m_text_score.setFont(this->m_font_score);
  this->m_text_score.setString("Score: ");
  this->m_text_score.setPosition(175, 0);
}

double& Score::calculateScore()
{
    return this->score;
}

int Score::printScore()
{
    int printedScore = int(calculateScore()) - (int(calculateScore()) % 10);
    return printedScore;
}

void Score::update()
{
    int printedScore = printScore();
    this->m_text_score.setString("Score: " + std::to_string(printedScore));
}

void Score::draw()
{
    this->m_window->draw(this->m_text_score);
}

