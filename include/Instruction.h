#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>

class Instruction
{
    public:
        Instruction(sf::RenderWindow * window);
        virtual ~Instruction();

        void draw();
        void loadImageInstruction(sf::Texture & texture, sf::Sprite & sprite, std::string name, float posX, float posY);
        void loadWordInstruction(sf::Text & text, std::string instruction, float posX, float posY, int charSize);

    private:
        sf::RenderWindow * m_window;
        sf::Font m_font;
        sf::Text m_text_instruction;

        sf::Texture m_texture_insBackground;
        sf::Sprite m_sprite_insBackground;

        sf::Texture m_texture_rightbutton;
        sf::Sprite m_sprite_rightbutton;

        sf::Text m_text_rightbutton;

        sf::Texture m_texture_leftbutton;
        sf::Sprite m_sprite_leftbutton;

        sf::Text m_text_leftbutton;

        sf::Texture m_texture_barry;
        sf::Sprite m_sprite_barry;

        sf::Text m_text_barry;

        sf::Texture m_texture_crossbar;
        sf::Sprite m_sprite_crossbar;

        sf::Text m_text_crossbar;

};

#endif // INSTRUCTION_H
