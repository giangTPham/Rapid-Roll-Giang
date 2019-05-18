#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

#define MAX_NUMBER_OF_ITEMS 5
class Menu
{
    public:
        Menu(sf::RenderWindow * window, float width, float height);
        virtual ~Menu();
        void draw();
        void moveUp();
        void moveDown();
        int getPressedItem();

        void setTextMode(sf::Text & text, std::string mode, sf::Color color, float posX, float Posy);

    private:
        sf::RenderWindow * m_window;
        sf::Texture m_texture_menuBackground;
        sf::Sprite m_sprite_menuBackground;
        int selectedItemIndex;
        sf::Font m_font;
        sf::Text m_text[MAX_NUMBER_OF_ITEMS];

};

#endif // MENU_H
