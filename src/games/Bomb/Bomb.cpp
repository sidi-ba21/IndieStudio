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

void Bomberman::Bomb::pose_bomb(float x, float y, float z)
{
    elapsed();
    if (getTime() > 5) {
        reset();
        _ispressed = false;
        del_vector3();
    }
    if (!_ispressed) {
        set_vector3(x, y, z);
        draw_bomb();
        _ispressed = true;
    }
}

void Bomberman::Bomb::explosion(Bomberman::Box &box, Bomberman::Map &map, Bomberman::Score &score,
    int n, Bomberman::AI &ai, Bomberman::Player &player)
{
    elapsed();
    if (_ispressed && getTime() > 3 && getTime() < 3.5) {
        box.remove_breakable(map, get_vector3());
        auto i = box.Damage(get_vector3(), player, ai, n);
        if (i != -1 && i != 0)
            player.set_life(-1, i);
        if (i == 0)
            ai.set_life(-1);
        score.update(n);
    }
}

void Bomberman::Bomb::wait_bomb()
{
    elapsed();
    if (_ispressed && getTime() < 3)
        draw_bomb();
}

Bomberman::Bomb::~Bomb()
{
}
