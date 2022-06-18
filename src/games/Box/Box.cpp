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
    _speed_up_texture = LoadTexture("Png/speed.png");
    _speed_down_texture = LoadTexture("Png/speed_down.png");
    _grass_texture = LoadTexture("Png/grass_cube.png");
    _brick_texture = LoadTexture("Png/brick_cube.png");
    _rectGrass = Rectangle{(float)_grass_texture.width / 2,
    (float)_grass_texture.height / 2,
    (float)_grass_texture.width / 2, (float)_grass_texture.height / 2};
}

void Bomberman::Box::draw_breakable(Bomberman::Map map)
{
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 32; x++) {
            if (COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x], RED)) {
                DrawCubeTexture(get_breakable_texture(), Vector3{x - 16.0f, 0.5, y - 8.f},
                                1, 1, 1, WHITE);
            }
            if (COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x], BLACK)) {
                DrawCubeTextureRec(get_grass_texture(), get_rectGrass(), {x - 16.0f, 0.1, y - 8.f},
                                   1, 0, 1, WHITE);
            }
            if (COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x], WHITE)) {
                DrawCubeTexture(get_brick_texture(), {x - 16.0f, 0.5, y - 8.f},
                                1, 1, 1, WHITE);
            }
        }
    }
}

void Bomberman::Box::remove_breakable(Bomberman::Map map, Vector3 pos)
{
    int x = pos.x + 16;
    int y = pos.z + 8;

    COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x], RED);
    COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x], BLACK);

    if (COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x], BLACK)) {
        map.get_color()[y * map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), 0.1, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (x < 15 && (COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x + 1], RED) || COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x + 1], BLACK))) {
        map.get_color()[y * map.get_cubicTexture().width + x + 1] = BLACK;
        DrawCube(Vector3{(float)(x + 1 - 16), 0.1, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (x > -15 && (COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x - 1], RED) || COLOR_EQUAL(map.get_color()[y * map.get_cubicTexture().width + x - 1], BLACK))) {
        map.get_color()[y * map.get_cubicTexture().width + x - 1] = BLACK;
        DrawCube(Vector3{(float)(x - 1 - 16), 0.1, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (y < 7 && (COLOR_EQUAL(map.get_color()[(y + 1) * map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(map.get_color()[(y + 1) * map.get_cubicTexture().width + x], BLACK))) {
        map.get_color()[(y + 1) * map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), 0.1, (float)(y + 1 - 8)}, 1, 1, 1, RED);
    }
    if (y > -7 && (COLOR_EQUAL(map.get_color()[(y - 1) * map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(map.get_color()[(y - 1) * map.get_cubicTexture().width + x], BLACK))) {
        map.get_color()[(y - 1) * map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), 0.1, (float)(y - 1 - 8)}, 1, 1, 1, RED);
    }
}

Texture2D Bomberman::Box::get_breakable_texture()
{
    return _breakable_texture;
}

Texture2D Bomberman::Box::get_speed_up_texture()
{
    return _speed_up_texture;
}

Texture2D Bomberman::Box::get_speed_down_texture()
{
    return _speed_down_texture;
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
    UnloadTexture(_speed_up_texture);
}
