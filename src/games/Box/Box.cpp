/*
** EPITECH PROJECT, 2022
** Box
** File description:
** Box
*/

#include "Box.hpp"

Bomberman::Box::Box()
{
}

void Bomberman::Box::init()
{
    _breakable_texture = LoadTexture("Png/woodx_brick.png");
    _grass_texture = LoadTexture("Png/grass_cube.png");
    _brick_texture = LoadTexture("Png/brick_cube.png");
    _rectGrass = Rectangle{(float)_grass_texture.width / 2,
    (float)_grass_texture.height / 2,
    (float)_grass_texture.width / 2, (float)_grass_texture.height / 2};
}

Texture2D Bomberman::Box::get_breakable_texture()
{
    return _breakable_texture;
}

Texture2D Bomberman::Box::get_grass_texture()
{
    return _grass_texture;
}

Texture2D Bomberman::Box::get_brick_texture()
{
    return _brick_texture;
}

Rectangle Bomberman::Box::get_rectGrass()
{
    return _rectGrass;
}

Bomberman::Box::~Box()
{
    UnloadTexture(_breakable_texture);
    UnloadTexture(_grass_texture);
    UnloadTexture(_brick_texture);
}
