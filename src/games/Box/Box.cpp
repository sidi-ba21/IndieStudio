/*
** EPITECH PROJECT, 2022
** Box
** File description:
** Box
*/

#include "Box.hpp"

void Bomberman::Box::init()
{
    std::vector<std::string> tab = {
        "Png/speed.png",
        "Png/speed_down.png",
        "Png/grass_floor.png",
    };
    del_texture();
    for (auto &tmp : tab)
        set_texture(tmp);
    random_walls();
    random_breackable();
    del = 1;
}

void Bomberman::Box::random_walls()
{
    std::vector<std::string> tab = {
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
    set_texture(tab[rand() % 11]);

}

void Bomberman::Box::random_breackable()
{
    std::vector<std::string> tab = {
        "Png/woodx_brick.png",
        "Png/tnt_cube.png",
        "Png/chest_cube.png",
        "Png/wooden_cube.png",
        "Png/wood.png",
        "Png/fire_cube.png",
        "Png/oldchest_cube.png",

    };
    set_texture(tab[rand() % 7]);
}

void Bomberman::Box::draw_breakable(Bomberman::Map map)
{
    for (std::size_t y = 0; y < 16; y++) {
        for (std::size_t x = 0; x < 32; x++) {
            if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], RED))
                draw_box(BREAKABLE, x, y, 0.5 , 1);
            if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], BLACK))
                draw_box(GRASS_TEXTURE, x, y, 0.1, 0);
            if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], WHITE))
                draw_box(BRICK, x, y, 0.5, 1);
        }
    }
}

void Bomberman::Box::remove_breakable(Bomberman::Map map, Vector3 pos)
{
    int x = ((int)(pos.x + 16));
    int y = ((int)(pos.z + 8));

    if (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], RED) || COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x], BLACK)) {
        map.get_color()[y * map.get_texture().width + x] = BLACK;
        remove_box(x - 16, y - 8);
    }
    if (x < 31 && (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x + 1], RED) || COLOR_EQUAL(map.get_color()[y * map.get_texture().width + x + 1], BLACK))) {
        map.get_color()[y * map.get_texture().width + x + 1] = BLACK;
        remove_box(x + 1 - 16, y - 8);
    }
    if (x > 0 && (COLOR_EQUAL(map.get_color()[y * map.get_texture().width + (x - 1)], RED) || COLOR_EQUAL(map.get_color()[y * map.get_texture().width + (x - 1)], BLACK))) {
        map.get_color()[y * map.get_texture().width + x - 1] = BLACK;
        remove_box(x - 1 - 16, y - 8);
    }
    if (y < 15 && (COLOR_EQUAL(map.get_color()[(y + 1) * map.get_texture().width + x], RED) || COLOR_EQUAL(map.get_color()[(y + 1) * map.get_texture().width + x], BLACK))) {
        map.get_color()[(y + 1) * map.get_texture().width + x] = BLACK;
        remove_box(x - 16, y + 1 - 8);
    }
    if (y > 0 && (COLOR_EQUAL(map.get_color()[(y - 1) * map.get_texture().width + x], RED) || COLOR_EQUAL(map.get_color()[(y - 1) * map.get_texture().width + x], BLACK))) {
        map.get_color()[(y - 1) * map.get_texture().width + x] = BLACK;
        remove_box(x - 16, y - 1 - 8);
    }
}

int Bomberman::Box::Damage(Vector3 pos, Bomberman::Player player, Bomberman::AI ai, int n)
{
    auto posP1 = player.get_pos();
    auto posP2 = player.get_pos(2);
    auto posA1 = ai.get_pos();
    int x = ((int)(pos.x + 16));
    int y = ((int)(pos.z + 8));

    if ((int)posP1.x == (x - 16) && (int)posP1.z == (y - 8))
        return 1;
    if ((int)posP2.x == (x - 16) && (int)posP2.z == (y - 8))
        return 2;
    if ((int)posP1.x == (x + 1 - 16) && (int)posP1.z == (y - 8))
        return 1;
    if ((int)posP2.x == (x + 1 - 16) && (int)posP2.z == (y - 8))
        return 2;
    if ((int)posP1.x == (x - 1 - 16) && (int)posP1.z == (y - 8))
        return 1;
    if ((int)posP2.x == (x - 1 - 16) && (int)posP2.z == (y - 8))
        return 2;
    if ((int)posP1.x == (x - 16) && (int)posP1.z == (y + 1 - 8))
        return 1;
    if ((int)posP2.x == (x - 16) && (int)posP2.z == (y + 1 - 8))
        return 2;
    if ((int)posP1.x == (x - 16) && (int)posP1.z == (y - 1 - 8))
        return 1;
    if ((int)posP2.x == (x - 16) && (int)posP2.z == (y - 1 - 8))
        return 2;
    
    if (n != 0) {
        if ((int)posA1.x == (x - 16) && (int)posA1.z == (y - 8))
            return 0;
        if ((int)posA1.x == (x + 1 - 16) && (int)posA1.z == (y - 8))
            return 0;
        if ((int)posA1.x == (x - 1 - 16) && (int)posA1.z == (y - 8))
            return 0;
        if ((int)posA1.x == (x - 16) && (int)posA1.z == (y + 1 - 8))
            return 0;
        if ((int)posA1.x == (x - 16) && (int)posA1.z == (y - 1 - 8))
            return 0;
    }
    return (-1);
}

Bomberman::Box::~Box()
{
    if (!del) {
        for (std::size_t i = 0; i < 4; i++)
            free_texture(i);
    }
}
