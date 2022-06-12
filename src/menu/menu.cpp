/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

#include "menu.hpp"

void Bomberman::Menu::game()
{
    this->is_game = true;
    this->is_title = false;
    //BeginDrawing();
    //    ClearBackground(RAYWHITE);
    //    DrawText("GAME THINGY", 100, 100, 100, BLACK);
    //EndDrawing();
}

void Bomberman::Menu::options()
{
    Vector2 temp = this->get_mousepos();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if  ((temp.x > screenHeight/4 && temp.x < screenHeight/4 + 50) && (temp.y > 270 && temp.y < 270 + 50))
            minus();
        else if  ((temp.x > screenHeight/4 && temp.x < screenHeight/4 + 50) && (temp.y > 810 && temp.y < 810 + 50))
            minus();
        else if  ((temp.x > 1440 && temp.x < 1440 + 50) && (temp.y > 270 && temp.y < 270 + 50))
            plus();
        else if  ((temp.x > 1440 && temp.x < 1440 + 50) && (temp.y > 810 && temp.y < 810 + 50))
            plus();
    }
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("OPTIONS", 0, 0, 100, WHITE);
        DrawRectangle(455, 270, 100, 100, RED);
        DrawText("-", screenHeight/4, 270, 100, WHITE);
        DrawRectangle(455, 810, 100, 100, RED);
        DrawText("-", screenHeight/4, 810, 100, WHITE);
        DrawRectangle(1415, 270, 100, 100, RED);
        DrawText("+", 1440, 270, 100, WHITE);
        DrawRectangle(1415, 810, 100, 100, RED);
        DrawText("+", 1440, 810, 100, WHITE);
    //EndDrawing();   
}

void Bomberman::Menu::adios()
{
    (void)mousepos;
    CloseAudioDevice();
    CloseWindow();
    exit(0);
}

void Bomberman::Menu::minus()
{
    (void)mousepos;
    musiic.set_volume(musiic.get_volume() - 2);
}

void Bomberman::Menu::plus()
{
    (void)mousepos;
    musiic.set_volume(musiic.get_volume() + 2);
}

Bomberman::Menu::Menu() {}

void Bomberman::Menu::init()
{
//    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitAudioDevice();
    this->musiic.init("./ressources/menu.mp3", 10, false);
    this->sfx.init("./ressources/explosion8bit.wav", 5, false);
    PlayMusicStream(musiic.get_ost());
}

void Bomberman::Menu::update()
{
    Vector2 temp = this->get_mousepos();

    UpdateMusicStream(musiic.get_ost());
    UpdateMusicStream(sfx.get_ost());
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    mousepos = GetMousePosition();
    if ((GetMusicTimePlayed(sfx.get_ost())/GetMusicTimeLength(sfx.get_ost())) > 1)
        StopMusicStream(sfx.get_ost());
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_title == true) {
        printf("click title\n");
        StopMusicStream(sfx.get_ost());
        PlayMusicStream(sfx.get_ost());
        if  ((temp.x > screenWidth/2 - 50 && temp.x < screenWidth/2 + 50) && (temp.y > 100 -50  && temp.y < 100 + 50))
            i = 0;
        else if  ((temp.x > screenWidth/4 -50 && temp.x < screenWidth/4 + 50) && (temp.y > screenHeight*0.75 -50 && temp.y < screenHeight*0.75 + 50))
            i = 1;
        else if  ((temp.x > screenWidth/6 -50 && temp.x < screenWidth/6 + 50) && (temp.y > screenHeight/4 -50 && temp.y < screenHeight/4 + 50))
            i = 2;
        else
            i = 3;
        (i == 3) ? is_title = true : is_title = false;
    }
    (IsKeyPressed(KEY_T)) ? (is_title = true) : true;
    (IsKeyPressed(KEY_SPACE)) ? musiic.set_pause() : (void)1;
}

void Bomberman::Menu::game_options()
{
    Vector2 temp = this->get_mousepos();

    if  (i == 0) {
        game();
    } else if  (i == 1) {
        options();
    } else if  (i == 2) {
        adios();
    }
}

void Bomberman::Menu::loop()
{
    if (is_title == true) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(screenWidth/2 - 50, 75, 100, 100, RED);
            DrawText("GAME", screenWidth/2 - 30, 100, 20, BLACK);
            DrawRectangle(screenWidth/4 -50, screenHeight*0.75 - 50, 100, 100, GREEN);
            DrawText("OPTIONS", screenWidth/4 -50, screenHeight*0.75, 20, BLACK);
            DrawRectangle(screenWidth/6 - 50, screenHeight/4, 100, 100, BLUE);
            DrawText("EXIT", screenWidth/6 - 30, screenHeight/4 + 50, 20, BLACK);
            DrawLine(18, 42, screenWidth - 18, 42, BLACK);
        //EndDrawing();
    } else 
        game_options();
}

Bomberman::Menu::~Menu()
{
}