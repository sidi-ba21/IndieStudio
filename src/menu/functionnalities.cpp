/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** functionnalities
*/

#include "menu.hpp"

void Bomberman::Menu::game()
{
    this->is_game = true;
    this->is_title = false;
    this->is_options = false;
    this->is_tuto = false;
    this->is_pause = false;
}

void Bomberman::Menu::options()
{
    is_title = false;
    is_game = false;
    is_options = true;
    is_tuto = false;
    is_pause = false;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("OPTIONS", 0, 0, 80.0, WHITE);

        DrawRectangleGradientH(720, 380, 350, 110, PURPLE, SKYBLUE);
        DrawText("MUSIC", 770, 400, 80.0, WHITE);

        DrawRectangleGradientH(560, 680, 680, 110, PURPLE, SKYBLUE);
        DrawText("SOUND EFFECTS", 600, 700, 70.0, WHITE);
        for (size_t i = 4; i < 8; i++)
            DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
    title_button();
}

void Bomberman::Menu::adios()
{
    CloseAudioDevice();
    CloseWindow();
    exit(0);
}
void Bomberman::Menu::pause()
{
    BeginDrawing();
        for (size_t i = 8; i < btns.size(); i++)
            DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
}

void Bomberman::Menu::tuto()
{
    is_game = false;
    is_options = false;
    is_title = false;
    is_tuto = true;
    is_pause = false;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("TUTORIAL", 0, 0, 80, RAYWHITE);
        title_button();
}
