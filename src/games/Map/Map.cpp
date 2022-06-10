/*
** EPITECH PROJECT, 2022
** Map
** File description:
** Map
*/

#include "Map.hpp"

//Bomberman::Map::Map()
//{
//}

void Bomberman::Map::init()
{
    _image = LoadImage("Png/perfect_map.png");   // Load cubicmap image (RAM)
    _cubicTexture = LoadTextureFromImage(_image); // Convert image to texture to display (VRAM)
    _mesh = GenMeshCubicmap(_image, (Vector3){1.0f, 1.0f, 1.0f});
    _model = LoadModelFromMesh(_mesh);
    _texture = LoadTexture("Png/grassbrick_cube.png"); // Load map texture

    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture; // Set map diffuse texture
}

void Bomberman::Map::update()
{
}

Model Bomberman::Map::get_model()
{
    return _model;
}

Vector3 Bomberman::Map::get_pos()
{
    return _pos;
}

Texture2D Bomberman::Map::get_cubicTexture()
{
    return _cubicTexture;
}

Bomberman::Map::~Map()
{
    UnloadImage(_image); // Unload cubesmap image from RAM, already uploaded to VRAM
    UnloadTexture(_cubicTexture); // Unload cubicmap texture
    UnloadTexture(_texture);  // Unload map texture
    UnloadModel(_model);      // Unload map model
}
