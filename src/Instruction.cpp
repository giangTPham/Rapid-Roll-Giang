#include "Instruction.h"

Instruction::Instruction(sf::RenderWindow * window)
{
    this->m_window = window;

    this->m_font.loadFromFile("Font/Brushsbi.ttf");

    this->m_text_instruction.setFont(this->m_font);
    this->m_text_instruction.setString("INSTRUCTION");
    this->m_text_instruction.setFillColor(sf::Color::Red);

    float width = this->m_window->getSize().x;
    float height = this->m_window->getSize().y;
    this->m_text_instruction.setPosition(width / 6, 0);

    this->m_texture_insBackground.loadFromFile("Image/instructionBackground.jpg");
    this->m_texture_insBackground.setSmooth(true);
    this->m_sprite_insBackground.setTexture(this->m_texture_insBackground);

    loadImageInstruction(this->m_texture_rightbutton, this->m_sprite_rightbutton, "Image/rightbutton.png", width / 6 * 5, height / 5);
    loadWordInstruction(this->m_text_rightbutton, "Press right button to move right", 10, height / 5, 22);

    loadImageInstruction(this->m_texture_leftbutton, this->m_sprite_leftbutton, "Image/leftbutton.png", 10, height / 5 * 2);
    loadWordInstruction(this->m_text_leftbutton, "Press left button to move left", 70, height / 5 * 2, 22);

    loadImageInstruction(this->m_texture_barry, this->m_sprite_barry, "Image/barry.png", width / 6 * 5, height / 5 * 3);
    loadWordInstruction(this->m_text_barry, "Jump on barry and lose a life", 10, height / 5 * 3, 22);

    loadImageInstruction(this->m_texture_crossbar, this->m_sprite_crossbar, "Image/crossbar.png", 10, height / 5 * 4 - 14);
    loadWordInstruction(this->m_text_crossbar, "Jump on crossbar please!!", 70, height / 5 * 4 - 20, 22);
}

Instruction::~Instruction()
{
    //dtor
}

void Instruction::draw()
{
    this->m_window->draw(this->m_sprite_insBackground);
    this->m_window->draw(this->m_text_instruction);
    this->m_window->draw(this->m_sprite_rightbutton);
    this->m_window->draw(this->m_text_rightbutton);
    this->m_window->draw(this->m_sprite_leftbutton);
    this->m_window->draw(this->m_text_leftbutton);
    this->m_window->draw(this->m_sprite_barry);
    this->m_window->draw(this->m_text_barry);
    this->m_window->draw(this->m_sprite_crossbar);
    this->m_window->draw(this->m_text_crossbar);
}

void Instruction::loadImageInstruction(sf::Texture & texture, sf::Sprite & sprite, std::string name, float posX, float posY)
{
    texture.loadFromFile(name);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

void Instruction::loadWordInstruction(sf::Text & text, std::string instruction, float posX, float posY, int charSize)
{
    text.setFont(this->m_font);
    text.setString(instruction);
    text.setCharacterSize(charSize);
    text.setFillColor(sf::Color::Red);
    text.setPosition(posX, posY);
}
