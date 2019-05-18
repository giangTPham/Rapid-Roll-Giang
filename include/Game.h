#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Ball.h"
#include "Crossbar.h"
#include "Barry.h"
#include "Nails.h"
#include "Heart.h"
#include "Score.h"
#include "Background.h"
#include "LifeAid.h"
#include "Common.h"
#include "Sound.h"

class Game
{
    public:
        Game(sf::RenderWindow * window);
        bool update(bool cheat_enable);
        void reset(int choice, std::vector<bool>& checkLevel);
        void draw();
        int getFinalScore();

        void initCrossbar();
        void initBarry();
        void setupBall();
        void updateCrossbar();
        void updateBarry();
        void updateLifeAid();
        void processBallTouchCrossbar();
        void processBallTouchBarry();
        void processBallTouchGround();
        void processBallTouchNails();
        void processBallTouchLifeAid();
        void generateCrossbarAndBarry();
        void generateLifeAid();
        void boostDifficulty();
        void drawCrossbar();
        void drawBarry();
        void drawLifeAid();

        Ball* get_m_ball() {return m_ball;}


    private:
        sf::RenderWindow * m_window;
        Nails * m_nails;

        Ball * m_ball;
        //Ball * m_ball_other;

        std::vector <Crossbar*> m_crossbar;
        std::vector <Barry*> m_barry;

        sf::Time m_time;
        sf::Clock m_clock;

        sf::Time m_time_LifeAid;
        sf::Clock m_clock_LifeAid;

        sf::Clock m_clock_Game;
        sf::Time m_time_Game;

        Heart * m_heart;

        Score * m_score;
        Background * m_background;

        std::vector <LifeAid*> m_LifeAid;

        int MENU = 0, START = 1, CONTINUE = 2, INSTRUCTION = 3, LEVEL = 4;

        Sound m_sound;


};

#endif // GAME_H
