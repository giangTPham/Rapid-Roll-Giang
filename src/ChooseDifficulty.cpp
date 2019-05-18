#include "ChooseDifficulty.h"

ChooseDifficulty::ChooseDifficulty(sf::RenderWindow * window, float width, float height)
{
    this->m_window = window;

    this->m_texture_backgroundDifficulty.loadFromFile("Image/difficultyBackground.png");
    this->m_texture_backgroundDifficulty.setSmooth(true);
    this->m_sprite_backgroundDifficulty.setTexture(this->m_texture_backgroundDifficulty);

    this->m_font.loadFromFile("Font/Brushsbi.ttf");

    loadText(this->m_difficulty[1], "Easy", sf::Color::Red, width / 2 - 35, height / (MAX_NUMBER_OF_DIFFICULTIES + 1) * 1);

    loadText(this->m_difficulty[2], "Normal", sf::Color::Yellow, width / 2 - 35, height / (MAX_NUMBER_OF_DIFFICULTIES + 1) * 2);

    loadText(this->m_difficulty[3], "Hard", sf::Color::Yellow, width / 2 - 35, height / (MAX_NUMBER_OF_DIFFICULTIES + 1) * 3);

    selectedLevel = 0;
}

ChooseDifficulty::~ChooseDifficulty()
{
    //dtor
}

void ChooseDifficulty::moveUp()
{
    if (selectedLevel < 1) selectedLevel++;
    if (selectedLevel > 1)
    {
        this->m_difficulty[selectedLevel].setFillColor(sf::Color::Yellow);
        selectedLevel--;
        this->m_difficulty[selectedLevel].setFillColor(sf::Color::Red);
    }
}

void ChooseDifficulty::moveDown()
{
    if (selectedLevel < 1) selectedLevel++;
    if (selectedLevel < 3)
    {
        this->m_difficulty[selectedLevel].setFillColor(sf::Color::Yellow);
        selectedLevel++;
        this->m_difficulty[selectedLevel].setFillColor(sf::Color::Red);
    }
}

void ChooseDifficulty::draw()
{
    this->m_window->draw(this->m_sprite_backgroundDifficulty);
    for (int i = 1; i <= MAX_NUMBER_OF_DIFFICULTIES; i++)
    {
        this->m_window->draw(this->m_difficulty[i]);
    }
}

int& ChooseDifficulty::getSelectedLevel()
{
    return this->selectedLevel;
}

void ChooseDifficulty::loadText(sf::Text & text, std::string level, sf::Color color, float width, float height)
{
    text.setFont(this->m_font);
    text.setString(level);
    text.setFillColor(color);
    text.setPosition(width, height);
}
