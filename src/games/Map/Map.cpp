/*
** EPITECH PROJECT, 2022
** Map
** File description:
** Map
*/

#include "Map.hpp"

void Bomberman::Map::init()
{
    random_maps();
    random_textures();
    _cubicTexture = LoadTextureFromImage(_image); // Convert image to texture to display (VRAM)
    _mesh = GenMeshCubicmap(_image, (Vector3){1.0f, 1.0f, 1.0f});
    _model = LoadModelFromMesh(_mesh);
    _color = LoadImageColors(_image);

 //   _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture; // Set map diffuse texture
    del = 1;
}

void Bomberman::Map::random_maps()
{
  const char *tab[] = {
        (char *)"Png/test_map.png",
        (char *)"Png/test_map1.png",
        (char *)"Png/test_map2.png",
        (char *)"Png/test_map3.png",
        (char *)"Png/test_map4.png",
        (char *)"Png/test_map5.png",
        (char *)"Png/test_map6.png",
        (char *)"Png/test_map7.png",
        (char *)"Png/test_map8.png",
    };
    _image = LoadImage(tab[random() % 9]);
}

void Bomberman::Map::random_textures()
{
   const char *tab1[] = {
        (char *)"Png/brickstone_cube.png",
        (char *)"Png/fullgrass_cube.png",
        (char *)"Png/brickstone_cube.png",
        (char *)"Png/fullgrass_cube.png",
    };
    _texture = LoadTexture(tab1[random() % 5]);
}

void Bomberman::Map::update()
{
}

Model Bomberman::Map::get_model()
{
    return _model;
}

Image Bomberman::Map::get_image()
{
    return _image;
}

Vector3 Bomberman::Map::get_pos()
{
    return _pos;
}

Texture2D Bomberman::Map::get_cubicTexture()
{
    return _cubicTexture;
}

Color *Bomberman::Map::get_color()
{
    return _color;
}

Bomberman::Map::~Map()
{
    if (!del)
    {
        UnloadImage(_image);          // Unload cubesmap image from RAM, already uploaded to VRAM
        UnloadTexture(_cubicTexture); // Unload cubicmap texture
        UnloadTexture(_texture);      // Unload map texture
        UnloadModel(_model);          // Unload map model
        UnloadImageColors(_color);
    }
}
