#include "Sound.h"

Sound::Sound()
{

}

Sound::~Sound()
{
    //dtor
}

void Sound::play(std::string file)
{
    this->m_file = file;
    this->m_soundBuffer.loadFromFile(this->m_file);
    this->m_sound.setBuffer(this->m_soundBuffer);
    this->m_sound.setVolume(100);
    this->m_sound.play();
}
