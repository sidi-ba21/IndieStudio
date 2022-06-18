/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** music
*/

#include "menu.hpp"

Bomberman::ost::ost(std::string name, size_t vol, bool paus)
{
    _music_name = name;
    _is_paused = paus;
    _mp3 = LoadMusicStream(_music_name.c_str());
    _volume = vol;
    SetMusicVolume(_mp3, _volume);
}

Bomberman::ost::~ost()
{
    UnloadMusicStream(_mp3);
}

void Bomberman::ost::init(std::string str, size_t nb, bool b)
{
    this->set_ost(LoadMusicStream(str.c_str()));
    this->set_volume(nb);
    this->_is_paused = b;
    this->_music_name = str;
}

void Bomberman::ost::set_volume(int vol)
{
    _volume = vol;
    if (_volume <= 0)
        _volume = 0;
    //SetMusicVolume(_mp3, vol);
}

int Bomberman::ost::get_volume()
{
    return _volume;
}

void Bomberman::ost::set_pause()
{
    if (_is_paused == true)
        ResumeMusicStream(_mp3);
    else
        PauseMusicStream(_mp3);
    _is_paused = !_is_paused;
}

bool Bomberman::ost::get_pause()
{
    return _is_paused;
}

void Bomberman::ost::set_ost(Music obj)
{
    _mp3 = obj;
}

Music Bomberman::ost::get_ost()
{
    return _mp3;
}

void Bomberman::ost::operator=(const Bomberman::ost &obj)
{
    this->_music_name = obj._music_name;
    this->_volume = obj._volume;
    this->_is_paused = obj._is_paused;
    this->_mp3 = LoadMusicStream(obj._music_name.c_str());
}
