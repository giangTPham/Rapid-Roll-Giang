#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>

class Music
{
    public:
        Music();
        virtual ~Music();

        void play(std::string file);
        void stop();

    private:
        sf::Music m_music;
        std::string m_file;
};

#endif // MUSIC_H
