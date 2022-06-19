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

void Bomberman::Bomb::draw_bomb()
{
    DrawSphere(_pos, 0.3, BLACK);
    DrawSphereWires(_pos, 0.3, 10, 10, BROWN);
}

void Bomberman::Bomb::pose_bomb(Vector3 player_pos)
{
    elapsed();
    if (getTime() > 6 || !_ispressed) {
        _pos = player_pos;
        reset();
        draw_bomb();
        _ispressed = 1;
    }
}

void Bomberman::Bomb::explosion(Bomberman::Box &box, Bomberman::Map &map, Bomberman::Score &score,
    int n, Bomberman::AI &ai, Bomberman::Player &player)
{
    elapsed();
    if (getTime() > 3 && getTime() < 3.5) {
        box.remove_breakable(map, _pos, player);
        auto i = box.Damage(map, _pos, player, n);
        if (i != -1)
            player.set_life(-1, i);
        score.update(n);
    }
}

void Bomberman::Bomb::wait_bomb()
{
    elapsed();
    if (getTime() > 0 && getTime() < 3)
        draw_bomb();
}

Vector3 Bomberman::Bomb::get_pos()
{
    return _pos;
}

Bomberman::Bomb::~Bomb()
{
}
