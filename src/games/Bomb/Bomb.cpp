/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomberman::Bomb::Bomb()
{
}

void Bomberman::Bomb::init()
{
}

void Bomberman::Bomb::update()
{

}

void Bomberman::Bomb::time_bomb()
{
    if (_ispressed)
        _time_bomb += getTime();
}

void Bomberman::Bomb::pose_bomb(Vector3 player_pos)
{
    //_pos = player_pos;
    //_ispre
    //std::cout << "x == " << _pos.x << "y == " << _pos.z << std::endl;

}

void Bomberman::Bomb::explosion(Vector3 pos)
{
    
}

void Bomberman::Bomb::wait_bomb()
{

}

Vector3 Bomberman::Bomb::get_pos()
{
    return _pos;
}

Bomberman::Bomb::~Bomb()
{
}
