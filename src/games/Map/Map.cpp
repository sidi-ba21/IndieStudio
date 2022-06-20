/*
** EPITECH PROJECT, 2022
** Map
** File description:
** Map
*/

#include "Map.hpp"

void Bomberman::Map::init()
{
    del_image();
    random_maps();
    del_texturefromImage();
    set_texturefromImage();
    set_vector3(1.0, 1.0, 1.0);
    del_meshCubicmap();
    set_meshCubicmap();
    del_modelfromMesh();
    set_modelfromMesh();
    del_colorfromImage();
    set_colorfromImage();
    del = 1;
}

void Bomberman::Map::random_maps()
{
    std::string tab[] = {
        "Png/test_map.png",
        "Png/test_map1.png",
        "Png/test_map2.png",
        "Png/test_map3.png",
        "Png/test_map4.png",
        "Png/test_map5.png",
        "Png/test_map6.png",
        "Png/test_map7.png",
        "Png/test_map8.png",
    };
    set_image(tab[rand() % 9]);
}

void Bomberman::Map::draw()
{
    draw_map();
}


void Bomberman::Map::update()
{
}

Bomberman::Map::~Map()
{
    if (!del)
    {
        free_image();
        free_mesh();
        free_model();
        free_texture();
        free_color();
    }
}
