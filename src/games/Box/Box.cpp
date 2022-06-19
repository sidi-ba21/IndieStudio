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
    _speed_up_texture = LoadTexture("Png/speed.png");
    _speed_down_texture = LoadTexture("Png/speed_down.png");
    _grass_texture = LoadTexture("Png/grass_cube.png");
    random_walls();
    random_breackable();
    _rectGrass = Rectangle{(float)_grass_texture.width / 2,
                           (float)_grass_texture.height / 2,
                           (float)_grass_texture.width / 2, (float)_grass_texture.height / 2};
}

void Bomberman::Box::random_walls()
{
    const char *tab1[11] = {
        "Png/wood_cube.png",
        "Png/stone_cube.png",
        "Png/fullgrass_cube.png",
        "Png/ice_cube.png",
        "Png/brick_cube.png",
        "Png/stone_cube.png",
        "Png/flowerbrick.png",
        "Png/flower_cube.png",
        "Png/cubex.png",
        "Png/face_cube.png",
        "Png/clearbrick_cube.png",
    };
    _brick_texture = LoadTexture(tab1[random() % 11]);
}

void Bomberman::Box::random_breackable()
{
    const char *tab1[7] = {
        "Png/woodx_brick.png",
        "Png/tnt_cube.png",
        "Png/chest_cube.png",
        "Png/wooden_cube.png",
        "Png/wood.png",
        "Png/fire_cube.png",
        "Png/oldchest_cube.png",

    };
    _breakable_texture = LoadTexture(tab1[random() % 7]);
}

void Bomberman::Box::draw_breakable(Bomberman::Map map)
{
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 32; x++)
        {
            if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], RED))
            {
                DrawCubeTexture(get_breakable_texture(), Vector3{x - 16.0f, 0.5, y - 8.f},
                                1, 1, 1, WHITE);
            }
            if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], BLACK))
            {
                DrawCubeTextureRec(get_grass_texture(), get_rectGrass(), {x - 16.0f, 0.1, y - 8.f},
                                   1, 0, 1, WHITE);
            }
            if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], WHITE))
            {
                DrawCubeTexture(get_brick_texture(), {x - 16.0f, 0.5, y - 8.f},
                                1, 1, 1, WHITE);
            }
        }
    }
}

void Bomberman::Box::remove_breakable(Bomberman::Map map, Vector3 pos, Player player)
{
    int x = (int)pos.x + 16;
    int y = (int)pos.z + 8;
    auto posP1 = player.get_pos();
    auto posP2 = player.get_pos(2);

    if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], RED) || COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], BLACK))
    {
        map.get_color()[y * map.get_texture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), 0.1, (float)(y - 8)}, 1, 1, 1, RED);
        if ((int)posP1.x + 16 == x && (int)posP1.z + 8 == y)
            player.set_life(-1);
        if ((int)posP2.x + 16 == x && (int)posP2.z + 8 == y)
            player.set_life(-1, 2);
    }
    if (x < 15 && (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x + 1], RED) || COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x + 1], BLACK)))
    {
        map.get_color()[y * map.get_texture().width + x + 1] = BLACK;
        DrawCube(Vector3{(float)(x + 1 - 16), 0.1, (float)(y - 8)}, 1, 1, 1, RED);
        if ((int)posP1.x + 16 == x + 1 && (int)posP1.z + 8 == y)
            player.set_life(-1);
        if ((int)posP2.x + 16 == x + 1 && (int)posP2.z + 8 == y)
            player.set_life(-1, 2);
    }
    if (x > -15 && (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x - 1], RED) || COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x - 1], BLACK)))
    {
        map.get_color()[y * map.get_texture().width + x - 1] = BLACK;
        DrawCube(Vector3{(float)(x - 1 - 16), 0.1, (float)(y - 8)}, 1, 1, 1, RED);
        if ((int)posP1.x + 16 == x - 1 && (int)posP1.z + 8 == y)
            player.set_life(-1);
        if ((int)posP2.x + 16 == x - 1 && (int)posP2.z + 8 == y)
            player.set_life(-1, 2);
    }
    if (y < 7 && (COLOR_EQUAL(map.get_color()[(y + 1) * map.get_texture().width + x], RED) || COLOR_EQUAL(map.get_color()[(y + 1) * map.get_texture().width + x], BLACK)))
    {
        map.get_color()[(y + 1) * map.get_texture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), 0.1, (float)(y + 1 - 8)}, 1, 1, 1, RED);
        if ((int)posP1.x + 16 == x && (int)posP1.z + 8 == y + 1)
            player.set_life(-1);
        if ((int)posP2.x + 16 == x && (int)posP2.z + 8 == y + 1)
            player.set_life(-1, 2);
    }
    if (y > -7 && (COLOR_EQUAL(map.get_color()[(y - 1) * map.get_texture().width + x], RED) || COLOR_EQUAL(map.get_color()[(y - 1) * map.get_texture().width + x], BLACK)))
    {
        map.get_color()[(y - 1) * map.get_texture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), 0.1, (float)(y - 1 - 8)}, 1, 1, 1, RED);
        if ((int)posP1.x + 16 == x && (int)posP1.z + 8 == y - 1)
            player.set_life(-1);
        if ((int)posP2.x + 16 == x && (int)posP2.z + 8 == y - 1)
            player.set_life(-1, 2);
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
