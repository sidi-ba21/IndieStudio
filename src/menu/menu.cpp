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
    //    DrawText("GAME THINGY", 100.0, 100.0, 100.0, BLACK);
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
        DrawText("OPTIONS", 0, 0, 100.0, WHITE);
        DrawRectangle(455, 270, 100.0, 100.0, RED);
        DrawText("-", screenHeight/4, 270, 100.0, WHITE);
        DrawRectangle(455, 810, 100.0, 100.0, RED);
        DrawText("-", screenHeight/4, 810, 100.0, WHITE);
        DrawRectangle(1415, 270, 100.0, 100.0, RED);
        DrawText("+", 1440, 270, 100.0, WHITE);
        DrawRectangle(1415, 810, 100.0, 100.0, RED);
        DrawText("+", 1440, 810, 100.0, WHITE);
    //EndDrawing();   
}

void Bomberman::Menu::adios()
{
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

void Bomberman::Button::init()
{
    button = LoadTexture(filename.c_str());
}

void Bomberman::Menu::init()
{
//    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitAudioDevice();
    this->musiic.init("./sounds/menu.mp3", 2, false);
    this->sfx = LoadSound("./sounds/explosion8bit.wav");

    this->btns.push_back(Bomberman::Button("Png/play.png", (Rectangle){(float)(screenWidth/2.0), 100.0, 100.0, 100.0}, (Rectangle){(float)(screenWidth/2.0), 100.0, 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/options.png", (Rectangle){(float)(screenWidth/4.0), (float)(screenHeight*0.75), 100.0, 100.0}, (Rectangle){(float)(screenWidth/4.0), (float)(screenHeight*0.75), 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/exit.png", (Rectangle){(float)(screenWidth/6.0), (float)(screenHeight/4.0), 100.0, 100.0}, (Rectangle){(float)(screenWidth/6.0), (float)(screenHeight/4.0), 100.0, 100.0}));
    for (size_t i = 0; i < this->btns.size(); i++)
        this->btns[i].init();
    PlayMusicStream(musiic.get_ost());
}

void Bomberman::Menu::update()
{
    UpdateMusicStream(musiic.get_ost());
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    mousepos = GetMousePosition();
    for (i = 0; i < this->btns.size(); i++) {
        if (CheckCollisionPointRec(mousepos, btns[i].btnBounds)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                btns[i].sourceRec.x = 200;
                break;
            } else
                btns[i].sourceRec.x = 100.0;
        } else
            btns[i].sourceRec.x = 0;
    }
    (i == this->btns.size()) ? is_title = true : is_title = false;
    (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) ? PlaySound(this->sfx) : (void)1;
    (IsKeyPressed(KEY_T)) ? (is_title = true) : true;
    (IsKeyPressed(KEY_SPACE)) ? musiic.set_pause() : (void)1;
}

void Bomberman::Menu::game_options()
{
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
            for (size_t i = 0; i < btns.size(); i++)
                DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, GREEN);
        //EndDrawing();
    } else 
        game_options();
}

Bomberman::Menu::~Menu()
{

    UnloadSound(this->sfx);
    CloseAudioDevice();
    //for (size_t i = 0; i < this->btns.size(); i++)
    //    UnloadTexture(this->btns[i].button);
}