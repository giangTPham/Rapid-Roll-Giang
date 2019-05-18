#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Game.h"
#include "LostScreen.h"
#include "Common.h"
#include "Menu.h"
#include "ChooseDifficulty.h"
#include "StartScreen.h"
#include "Instruction.h"
#include "Sound.h"
#include "Music.h"
#include "BallTypes.h"

float SPEED = 1.75;
float APPEARANCEGAP = 0.44;
float SCOREGAP = 0.5;
int HIGHSCORE = 0;
int CHARACTER = 0;
 std::string characterPath[4] = {"Image/duongtang.png", "Image/tonngokhong.png", "Image/trubatgioi.png", "Image/satan.png"};

enum{MENU, START, CONTINUE,INSTRUCTION, LEVEL, CHOOSEBALL} choice;
std::vector<bool> checkLevel(3, false);



int main()
{
    checkLevel[0] = true;
    sf::RenderWindow window(sf::VideoMode(350, 500), "Rapid Roll", sf::Style::Close);
    window.setFramerateLimit(60);

    Game game(&window);
    Sound sound;
    Music music;
    LostScreen lostScreen(&window);
    BallTypes ballType(&window);

    bool cheat_enable = false;
    bool checkFocus = true;

    Menu menu(&window, window.getSize().x, window.getSize().y);
    ChooseDifficulty chooseDifficulty(&window, window.getSize().x, window.getSize().y);

    Instruction instruction(&window);


    music.play("Music/tayduky.wav");


    if (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        StartScreen startScreen(&window);
        window.clear();
        startScreen.draw();
        window.display();



    }
    Sleep(1000);
    while (window.isOpen())
    {

        bool gameStatus = true;
        bool checkEnterInGame = false;
        sf::Event event;


        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::LostFocus)
                checkFocus = false;
            if (event.type == sf::Event::GainedFocus)
                checkFocus = true;
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code ==  sf::Keyboard::Home)
                    checkEnterInGame = true;
            }
            if (event.type == sf::Event::KeyReleased and choice == MENU)
            {
                if (event.key.code == sf::Keyboard::Up)
                    menu.moveUp();
                if (event.key.code == sf::Keyboard::Down)
                    menu.moveDown();
                if (event.key.code == sf::Keyboard::Return)
                {
                    switch(menu.getPressedItem())
                    {
                    case 0:
                        choice = START;
                        game.reset(choice, checkLevel);
                        cheat_enable = false;
                        break;
                    case 1:
                        choice = CONTINUE;
                        break;
                    case 2:
                        choice = INSTRUCTION;
                        break;
                    case 3:
                        choice = LEVEL;
                        break;
                    case 4:
                        choice = CHOOSEBALL;
                        break;
                    default: break;
                    }
                }


            }

            if (event.type == sf::Event::KeyReleased and choice == LEVEL)
            {
                if (event.key.code == sf::Keyboard::Up)
                    chooseDifficulty.moveUp();
                if (event.key.code == sf::Keyboard::Down)
                    chooseDifficulty.moveDown();
                if (event.key.code == sf::Keyboard::Return)
                {
                    switch(chooseDifficulty.getSelectedLevel())
                    {
                    case 1:
                        SPEED = 1.75;
                        APPEARANCEGAP = 0.44;
                        chooseDifficulty.getSelectedLevel() = 0;
                        checkLevel[0] = true; checkLevel[1] = false; checkLevel[2] = false;
                        choice = MENU;
                        break;
                    case 2:
                        SPEED = 3.03;
                        APPEARANCEGAP = 0.312;
                        chooseDifficulty.getSelectedLevel() = 0;
                        checkLevel[0] = false; checkLevel[1] = true; checkLevel[2] = false;
                        choice = MENU;
                        break;
                    case 3:
                        SPEED = 4.07;
                        APPEARANCEGAP = 0.208;
                        chooseDifficulty.getSelectedLevel() = 0;
                        checkLevel[0] = false; checkLevel[1] = false; checkLevel[2] = true;
                        choice = MENU;
                        break;
                    }
                }
            }

            if (choice == INSTRUCTION and event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Home) choice = MENU;
            }

            if (choice == CHOOSEBALL and event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Home) choice = MENU;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)
               && sf::Keyboard::isKeyPressed(sf::Keyboard::O)
               && sf::Keyboard::isKeyPressed(sf::Keyboard::P))
               {
                   cheat_enable = true;
               }


        }

        if (checkFocus)
        {
            window.clear();
            if (choice == MENU)
                menu.draw();

            if (choice == START or choice == CONTINUE)
            {

                gameStatus = game.update(cheat_enable);
                if(gameStatus)
                {
                    game.draw();
                    if (checkEnterInGame) choice = MENU;
                }
                else
                {
                    int printScore = game.getFinalScore() - (game.getFinalScore() % 10);
                    if (printScore > HIGHSCORE) HIGHSCORE = printScore;

                    lostScreen.draw(game.getFinalScore());
                    sound.play("Music/Lost.wav");
                    gameStatus = false;
                    cheat_enable = false;
                    choice = MENU;
                }
            }
        }

            if (choice == INSTRUCTION)
            {
                instruction.draw();
            }

            if (choice == LEVEL)
            {
                chooseDifficulty.draw();

            }
            if (choice == CHOOSEBALL)
            {
                ballType.update(game.get_m_ball());
                ballType.draw();
            }
            window.display();
            if (!gameStatus)
            {
                Sleep(3000);
            }


        }

    return 0;
}
