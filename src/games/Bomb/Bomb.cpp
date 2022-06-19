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

void Bomberman::Bomb::pose_bomb(int x, int y, int z)
{
    elapsed();
    if (getTime() > 6 || !_ispressed) {
        set_vector3(x, y, z);
        draw_bomb();
        reset();
        _ispressed = 1;
    }
}

void Bomberman::Bomb::explosion(Bomberman::Box &box, Bomberman::Map &map, Bomberman::Score &score,
    int n, Bomberman::AI &ai, Bomberman::Player &player)
{
    elapsed();
    //(void) ai;
    if (getTime() > 3 && getTime() < 3.5) {
        box.remove_breakable(map, get_vector3(), player);
        score.update(n);
    }
}

void Bomberman::Bomb::wait_bomb()
{
    elapsed();
    if (getTime() > 0 && getTime() < 3)
        draw_bomb();
}

Bomberman::Bomb::~Bomb()
{
}
