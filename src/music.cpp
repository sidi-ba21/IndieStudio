/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** music
*/

#include "music.hpp"

ost::ost(std::string name, size_t vol, bool paus)
{
    _music_name = name;
    _is_paused = false;
    _mp3 = LoadMusicStream(_music_name.c_str());
    _volume = 10;
    SetMusicVolume(_mp3, _volume);
}

ost::~ost()
{
    UnloadMusicStream(_mp3);
}

void ost::set_volume(size_t vol)
{
    _volume = vol;
    SetMusicVolume(_mp3, vol);
}

size_t ost::get_volume()
{
    return _volume;
}

void ost::set_pause()
{
    _is_paused = !_is_paused;
    if (_is_paused == true)
        ResumeMusicStream(_mp3);
    else
        PauseMusicStream(_mp3);
}

bool ost::get_pause()
{
    return _is_paused;
}

void ost::set_ost(Music obj)
{
    _mp3 = obj;
}

Music ost::get_ost()
{
    return _mp3;
}