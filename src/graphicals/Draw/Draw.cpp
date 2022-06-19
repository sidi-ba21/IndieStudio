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

void Raylib::Draw::draw_map()
{
    DrawTextureEx(_texture, (Vector2){screenWidth - _texture.width * 4.0f - 20, 20.0f}, 0.0, 4.0, WHITE);
    DrawRectangleLines(screenWidth - _texture.width * 4 - 20, 20, _texture.width * 4, _texture.height * 4, GREEN);
}

void Raylib::Draw::draw_background()
{
    DrawTextureV(_texture, Vector2{0, 0}, WHITE);
}

void Raylib::Draw::draw_bomb()
{
    DrawSphere(_vector3, 0.3, BLACK);
    DrawSphereWires(_vector3, 0.3, 10, 10, BROWN);
}