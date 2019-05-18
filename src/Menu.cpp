#include "Menu.h"

Menu::Menu(sf::RenderWindow * window, float width, float height)
{
    this->m_window = window;

    this->m_font.loadFromFile("Font/Brushsbi.ttf");
    this->m_texture_menuBackground.loadFromFile("Image/menuBackground3.png");
    this->m_texture_menuBackground.setSmooth(true);
    this->m_sprite_menuBackground.setTexture(this->m_texture_menuBackground);
    this->m_sprite_menuBackground.setOrigin(this->m_texture_menuBackground.getSize().x/2, this->m_texture_menuBackground.getSize().y/2);

    setTextMode(this->m_text[0], "Play", sf::Color::Red, width / 2 - 35, height / (MAX_NUMBER_OF_ITEMS + 1) * 1);

    setTextMode(this->m_text[1], "Continue", sf::Color::White, width / 2 - 55, height / (MAX_NUMBER_OF_ITEMS + 1) * 2);

    setTextMode(this->m_text[2], "Instruction", sf::Color::White, width / 2 - 65, height / (MAX_NUMBER_OF_ITEMS + 1) * 3);

    setTextMode(this->m_text[3], "Difficulty", sf::Color::White, width / 2 - 57, height / (MAX_NUMBER_OF_ITEMS + 1) * 4);

    setTextMode(this->m_text[4], "Choose Ball", sf::Color::White, width / 2 - 65, height / (MAX_NUMBER_OF_ITEMS + 1) * 5);



    selectedItemIndex = 0;
}

Menu::~Menu()
{
    //dtor
}

void Menu::draw()
{

    this->m_window->draw(this->m_sprite_menuBackground);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        this->m_window->draw(this->m_text[i]);
    }
}

void Menu::moveUp()
{
    if (selectedItemIndex > 0)
    {
        this->m_text[this->selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex--;
        this->m_text[this->selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (this->selectedItemIndex < MAX_NUMBER_OF_ITEMS - 1)
    {
        this->m_text[this->selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex++;
        this->m_text[this->selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::getPressedItem()
{
    return this->selectedItemIndex;
}

void Menu::setTextMode(sf::Text& text, std::string mode, sf::Color color, float posX, float posY)
{
    text.setFont(this->m_font);
    text.setFillColor(color);
    text.setString(mode);
    text.setPosition(posX, posY);
}

