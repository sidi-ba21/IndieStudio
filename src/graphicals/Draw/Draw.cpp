/*
** EPITECH PROJECT, 2022
** Draw
** File description:
** Draw
*/

#include "Draw.hpp"

void Raylib::Draw::initWindow()
{
    InitWindow(screenWidth, screenHeight, "Bomberman");
    if (!IsWindowReady())
        throw GraphicsError("Failed to create window");
    ToggleFullscreen();
    SetTargetFPS(60);
}

void Raylib::Draw::closeWindow()
{
    CloseWindow();
}

bool Raylib::Draw::game_loop()
{
    return !WindowShouldClose();
}

void Raylib::Draw::draw_map(std::size_t n)
{
    DrawTextureEx(_texture[n], (Vector2){screenWidth - _texture[n].width * 4.0f - 20, 20.0f}, 0.0, 4.0, WHITE);
    DrawRectangleLines(screenWidth - _texture[n].width * 4 - 20, 20, _texture[n].width * 4, _texture[n].height * 4, GREEN);
}

void Raylib::Draw::draw_background(std::size_t n)
{
    DrawTextureV(_texture[n], Vector2{0, 0}, WHITE);
}

void Raylib::Draw::draw_bomb(std::size_t n)
{
    DrawSphere(_vector3[n], 0.3, BLACK);
    DrawSphereWires(_vector3[n], 0.3, 10, 10, BROWN);
}

void Raylib::Draw::draw_box(std::size_t n, std::size_t x, std::size_t y, std::size_t h)
{
    DrawCubeTexture(get_texture(n), Vector3{x - 16.0f, 0.5, y - 8.f}, 1, h, 1, WHITE);
}

void Raylib::Draw::remove_box(float x, float y)
{
    DrawCube(Vector3{x, 0.1, y}, 1, 1, 1, RED);
}