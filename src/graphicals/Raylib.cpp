/*
** EPITECH PROJECT, 2022
** raylib
** File description:
** raylib
*/

#include "Raylib.hpp"

Bomberman::Raylib::Raylib()
{
    InitWindow(800, 600, "Bomberman");
    SetTargetFPS(60);
    ToggleFullscreen();
}

Bomberman::Raylib::~Raylib()
{
    CloseWindow();
}

void Bomberman::Raylib::draw()
{
}

void Bomberman::Raylib::update()
{
    UpdateWindow();
}

void Bomberman::Raylib::clear()
{
    ClearBackground(RAYWHITE);
}
