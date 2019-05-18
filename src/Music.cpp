#include "Music.h"

Music::Music()
{
    //ctor
}

Music::~Music()
{
    //dtor
}

void Music::play(std::string file)
{
    this->m_file = file;
    this->m_music.openFromFile(this->m_file);
    this->m_music.setVolume(10);
    this->m_music.play();
    this->m_music.setLoop(true);
}

void Music::stop()
{
    this->m_music.stop();
}
