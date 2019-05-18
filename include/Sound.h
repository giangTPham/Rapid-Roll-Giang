#ifndef SOUND_H
#define SOUND_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

class Sound
{
    public:
        Sound();
        virtual ~Sound();

        void play(std::string file);

    private:
        std::string m_file;
        sf::SoundBuffer m_soundBuffer;
        sf::Sound m_sound;

};

#endif // SOUND_H
