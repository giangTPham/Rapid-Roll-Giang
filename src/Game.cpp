#include "Game.h"



Game::Game(sf::RenderWindow * window)
{
    this->m_window = window;

    this->m_background = new Background(this->m_window);
    this->m_score = new Score(this->m_window);
    initCrossbar();
    initBarry();
    setupBall();
    this->m_heart = new Heart(this->m_window);
    this->m_nails = new Nails(this->m_window);

    this->m_clock.restart();
    this->m_clock_Game.restart();
    this->m_clock_LifeAid.restart();
}

bool Game::update(bool cheat_enable)
{

    if(cheat_enable && this->m_heart->countHeart() <= 1) this->m_heart->countHeart() = 1;

    if (this->m_heart->countHeart() < 0)
    {

        return false;
    }
    this->m_ball->update();
    //this->m_ball_other->update();

    this->m_score->update();

    updateCrossbar();
    updateBarry();
    updateLifeAid();
    processBallTouchCrossbar();
    processBallTouchBarry();
    processBallTouchGround();
    processBallTouchNails();
    processBallTouchLifeAid();
    generateCrossbarAndBarry();
    generateLifeAid();
    boostDifficulty();
    return true;



}

void Game::draw()
{
    this->m_background->draw();
    this->m_nails->draw();
    this->m_heart->draw();
    this->m_score->draw();
    this->m_ball->draw();
    //this->m_ball_other->draw();
    drawCrossbar();
    drawBarry();
    drawLifeAid();
}

void Game::initCrossbar()
{
    this->m_crossbar.push_back(new Crossbar(this->m_window, 272));

    this->m_crossbar.push_back(new Crossbar(this->m_window, 500));
}

void Game::initBarry()
{
    this->m_barry.push_back(new Barry(this->m_window, 158));
    this->m_barry.push_back(new Barry(this->m_window, 234));


}

void Game::setupBall()
{

    // set initial position for ball
    std::vector<Crossbar*>::iterator ptr_crossbar = m_crossbar.begin();
    float posX = (*ptr_crossbar)->getPosition().x;
    float posY = (*ptr_crossbar)->getPosition().y - 34;
    this->m_ball = new Ball(this->m_window,posX, posY);
}

void Game::updateCrossbar()
{
    //update and condition to delete crossbar
    if (m_crossbar.size() > 0)
    {
        for (std::vector<Crossbar*>::iterator it = m_crossbar.begin(); it != m_crossbar.end(); it++)
        {
            (*it) -> update();
        }
        if ((*m_crossbar.begin())->getPosition().y <= 44) m_crossbar.erase(m_crossbar.begin());
    }
}

void Game::updateBarry()
{
    //update and condition to delete barry
    if (m_barry.size() > 0)
    {
        for (std::vector<Barry*>::iterator it = m_barry.begin(); it!=m_barry.end(); it++)
            (*it) -> update();
        if ((*m_barry.begin())->getPosition().y <= 44) m_barry.erase(m_barry.begin());
    }
}

void Game::updateLifeAid()
{
    //update and condition to delete LifeAid
    if (m_LifeAid.size() > 0)
    {
        for (std::vector<LifeAid*>::iterator it = m_LifeAid.begin();it!=m_LifeAid.end(); it++)
        {
            (*it)->update();
        }
        if ((*m_LifeAid.begin())->getPosition().y <= 44) m_LifeAid.erase(m_LifeAid.begin());
    }
}

void Game::processBallTouchCrossbar()
{

    bool checkTouchCrossbar = false;
    for (std::vector<Crossbar*>::iterator it = m_crossbar.begin(); it!=m_crossbar.end(); it++)
    {
        // check if ball and crossbar touch and process
        float ballCrossDistanceX = abs(this->m_ball->getPosition().x - (*it)->getPosition().x);
        float ballCrossDistanceY = abs(this->m_ball->getPosition().y - (*it)->getPosition().y);

        if (ballCrossDistanceX < 33 and ballCrossDistanceY < 11 and this->m_ball->getPosition().y + 2 < (*it)->getPosition().y)
        {

            sf::Vector2f newPos;
            newPos.x = this->m_ball->getPosition().x;
            newPos.y = (*it)->getPosition().y - 12.5;

            this->m_ball->setPosition(this->m_ball, newPos);
            checkTouchCrossbar = true;
        }



    }
    if (!checkTouchCrossbar)
    {
        this->m_score->calculateScore()+=SCOREGAP;
        this->m_sound.play("Music/jumpOnCrossbar.wav");
    }
}

void Game::processBallTouchBarry()
{
    for (std::vector<Barry*>::iterator it = m_barry.begin(); it!=m_barry.end(); it++)
    {
        // check if ball and barry touch and process
        float ballCrossDistanceX = abs(this->m_ball->getPosition().x - (*it)->getPosition().x);
        float ballCrossDistanceY = abs(this->m_ball->getPosition().y - (*it)->getPosition().y);
        if (ballCrossDistanceX < 32 and ballCrossDistanceY < 19)
        {
            this->m_sound.play("Music/loseLife.wav");
            this->m_heart->countHeart()--;
            delete m_ball;
            // set initial position for ball after touches barry
            int beneathBarry = 0;

            std::vector<Crossbar*>::iterator ptr_crossbar;
            do
            {
                ptr_crossbar = m_crossbar.begin() + beneathBarry;
                beneathBarry++;


            } while(((ptr_crossbar) != m_crossbar.end() - 1) and (*ptr_crossbar)->getPosition().y < (*it)->getPosition().y);


            if (ptr_crossbar == m_crossbar.end() - 1) ptr_crossbar = m_crossbar.end() - 1;

            else ptr_crossbar += rand()%2;
            float posX = (*ptr_crossbar)->getPosition().x;
            float posY = (*ptr_crossbar)->getPosition().y - 34;
            this->m_ball = new Ball(this->m_window,posX, posY);
        }
    }
}

void Game::processBallTouchGround()
{
     //check if the ball touches the ground
    if (m_ball->getPosition().y >= 492)
    {
        this->m_sound.play("Music/loseLife.wav");
        this->m_heart->countHeart()--;
        delete m_ball;
        // set initial position for ball
        std::vector<Crossbar*>::iterator ptr_crossbar = m_crossbar.begin()+(rand() % m_crossbar.size());
        float posX = (*ptr_crossbar)->getPosition().x;
        float posY = (*ptr_crossbar)->getPosition().y - 34;
        this->m_ball = new Ball(this->m_window,posX, posY);
    }

}

void Game::processBallTouchNails()
{
        // check if the ball touches the nail
    if (this->m_ball->getPosition().y <= 40)
    {
        this->m_sound.play("Music/loseLife.wav");
        this->m_heart->countHeart()--;
        delete m_ball;
        std::vector<Crossbar*>::iterator ptr_crossbar = m_crossbar.begin()+(rand() % m_crossbar.size());
        float posX = (*ptr_crossbar)->getPosition().x;
        float posY = (*ptr_crossbar)->getPosition().y - 34;
        this->m_ball = new Ball(this->m_window,posX, posY);
    }

}

void Game::processBallTouchLifeAid()
{
     // check if the ball touches the LifeAid
    for (std::vector<LifeAid*>::iterator it = m_LifeAid.begin(); it!=m_LifeAid.end(); it++)
    {
        float distanceX = abs(m_ball->getPosition().x - (*it)->getPosition().x);
        float distanceY = abs(m_ball->getPosition().y - (*it)->getPosition().y);
        if (distanceX < 14 and distanceY < 13)
        {
            this->m_sound.play("Music/soundEatHeart.wav");
            if (m_heart->countHeart() < 6) m_heart->countHeart()++;
            m_LifeAid.erase(it);
            it--;
        }
    }

}

void Game::generateCrossbarAndBarry()
{
    // create new crossbar or barry
    this->m_time = this->m_clock.getElapsedTime();
    if (this->m_time.asSeconds() > APPEARANCEGAP)
    {
        int randNum = rand() % 100 + 1;
        if (randNum > 20)
            m_crossbar.push_back(new Crossbar(this->m_window, 510));
        else
        {
            m_barry.push_back(new Barry(this->m_window, 510));
        }
        this->m_clock.restart();

    }
}

void Game::generateLifeAid()
{
    //LifeAid appearance
    this->m_time_LifeAid = this->m_clock_LifeAid.getElapsedTime();
    if (m_time_LifeAid.asSeconds() > (rand()%10+5))
    {
        this->m_LifeAid.push_back(new LifeAid(this->m_window));
        std::vector<Crossbar*>::iterator ptr_crossbar = m_crossbar.end() - 1;
        float posX = (*ptr_crossbar)->getPosition().x;
        float posY = (*ptr_crossbar)->getPosition().y - 10;
        (*(this->m_LifeAid.end()-1))->setPosition(posX, posY);
        m_clock_LifeAid.restart();
    }
}

void Game::boostDifficulty()
{
        //Difficulty boost
    this->m_time_Game = this->m_clock_Game.getElapsedTime();
    if(this->m_time_Game.asSeconds() > 2.0)
    {
        if(SPEED < 4.71) SPEED += 0.08;
        if (APPEARANCEGAP > 0.144) APPEARANCEGAP -= 0.008;
        if (SCOREGAP < 5) SCOREGAP += 0.02;
        m_clock_Game.restart();
    }

}

void Game::drawCrossbar()
{
    if (m_crossbar.size() > 0)
    {
        for (std::vector<Crossbar*>::iterator it = m_crossbar.begin(); it != m_crossbar.end(); it++)
        {
            (*it) -> draw();
        }
    }
}

void Game::drawBarry()
{
    if (m_barry.size() > 0)
    {
        for (std::vector<Barry*>::iterator it = m_barry.begin(); it!=m_barry.end(); it++)
            (*it) -> draw();
    }
}

void Game::drawLifeAid()
{
    if (m_LifeAid.size() > 0)
    {
        for (std::vector<LifeAid*>::iterator it = m_LifeAid.begin(); it!=m_LifeAid.end(); it++)
            (*it) -> draw();
    }
}

void Game::reset(int choice,std::vector<bool>& checkLevel)
{
    if (choice == START)
     {
            this->m_heart->countHeart() = 2;
            this->m_score->calculateScore() = 0;
     }
     if (checkLevel[0])
     {
         SPEED = 1.75;
         APPEARANCEGAP = 0.44;
     }
     if (checkLevel[1])
     {
         SPEED = 3.03;
         APPEARANCEGAP = 0.312;
     }
     if (checkLevel[2])
     {
         SPEED = 4.07;
         APPEARANCEGAP = 0.208;
     }


}

int Game::getFinalScore()
{
    return int(this->m_score->calculateScore());
}
