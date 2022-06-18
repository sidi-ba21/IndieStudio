/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** functionnalities
*/

#include "menu.hpp"

static Texture2D cmd;

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

        DrawRectangleGradientH(770, 380, 350, 110, PURPLE, SKYBLUE);
        DrawText("MUSIC", 820, 400, 80.0, WHITE);

        DrawRectangleGradientH(620, 680, 680, 110, PURPLE, SKYBLUE);
        DrawText("SOUND EFFECTS", 660, 700, 70.0, WHITE);
        for (size_t i = 4; i < 8; i++)
            DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
    title_button();
}

void Bomberman::Menu::adios()
{
    UnloadTexture(cmd);
    CloseAudioDevice();
    CloseWindow();
    exit(0);
}
void Bomberman::Menu::pause()
{
    btns[10].btnBounds = (Rectangle){700, 600, 540, 120};
    BeginDrawing();
        for (size_t i = 8; i < btns.size(); i++)
            DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
}

void Bomberman::Menu::tuto()
{
    static int i = 0;

    is_game = false;
    is_options = false;
    is_title = false;
    is_tuto = true;
    is_pause = false;
    if (i == 0) {
        (cmd = LoadTexture("Png/commands.png"));
        (i++);
    }
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("TUTORIAL", 0, 0, 80, RAYWHITE);
        DrawText("Explode your ennemies to survive the arena !", 50, 350, 80, RAYWHITE);
        if (i != 0) DrawTextureEx(cmd, (Vector2){500, 500}, 0, 0.5, RAYWHITE);
        title_button();
}

void Bomberman::Menu::the_end(int id)
{
    (void) id;
    is_game = false;
    is_options = false;
    is_title = false;
    is_tuto = false;
    is_pause = false;
    is_finished = true;

    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("ENDING", 0, 0, 80, RAYWHITE);
}