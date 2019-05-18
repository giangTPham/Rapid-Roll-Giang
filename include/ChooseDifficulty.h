#ifndef CHOOSEDIFFICULTY_H
#define CHOOSEDIFFICULTY_H

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_DIFFICULTIES 3

class ChooseDifficulty
{
    public:
        ChooseDifficulty(sf::RenderWindow * window, float width, float height);
        virtual ~ChooseDifficulty();
        void moveUp();
        void moveDown();
        void draw();
        int& getSelectedLevel();
        void loadText(sf::Text & text, std::string level, sf::Color color, float width, float height);

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_backgroundDifficulty;
        sf::Sprite m_sprite_backgroundDifficulty;
        sf::Font m_font;
        sf::Text m_difficulty[MAX_NUMBER_OF_DIFFICULTIES + 1];

        int selectedLevel;
};

#endif // CHOOSEDIFFICULTY_H
