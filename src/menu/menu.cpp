/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

#include <unistd.h>
#include "menu.hpp"

void Bomberman::Menu::game()
{
    this->is_game = true;
    this->is_title = false;
    this->is_options = false;
    this->is_pause = false;
}

void Bomberman::Menu::options()
{
    is_title = false;
    is_game = false;
    is_options = true;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("OPTIONS", 0, 0, 80.0, WHITE);

        DrawRectangleGradientH(720, 380, 350, 110, PURPLE, SKYBLUE);
        DrawText("MUSIC", 770, 400, 80.0, WHITE);

        DrawRectangleGradientH(560, 680, 680, 110, PURPLE, SKYBLUE);
        DrawText("SOUND EFFECTS", 600, 700, 70.0, WHITE);
        for (size_t i = 4; i < 8; i++)
            DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
}

void Bomberman::Menu::adios()
{
    CloseAudioDevice();
    CloseWindow();
    exit(0);
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

    this->btns.push_back(Bomberman::Button("Png/basic_play.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 250.0,540, 120}));
    this->btns.push_back(Bomberman::Button("Png/basic_option.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 450.0, 540, 120}));
    this->btns.push_back(Bomberman::Button("Png/basic_exit.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 850.0, 540, 120}));
    this->btns.push_back(Bomberman::Button("Png/basic_tuto.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 650.0, 540, 120}));

    this->btns.push_back(Bomberman::Button("Png/+.png",(Rectangle){0, 0, 100, 100}, (Rectangle){1300.0, 400.0, 540, 120}));
    this->btns.push_back(Bomberman::Button("Png/+.png",(Rectangle){0, 0, 100, 100}, (Rectangle){1300.0, 700.0, 540, 120}));
    this->btns.push_back(Bomberman::Button("Png/-.png",(Rectangle){0, 0, 100, 100}, (Rectangle){400.0, 400.0, 540, 120}));
    this->btns.push_back(Bomberman::Button("Png/-.png",(Rectangle){0, 0, 100, 100}, (Rectangle){400.0, 700.0, 540, 120}));

    /*pause*/// this->btns.push_back(Bomberman::Button("Png/play.png",(Rectangle){0, 0, 100, 100}, (Rectangle){1800.0, 0.0, 100, 100}));
    /*options*/ this->btns.push_back(Bomberman::Button("Png/basic_resume.png", (Rectangle){0, 0, 540, 120}, (Rectangle){700.0, 300, 540, 120}));
    /*title*/ this->btns.push_back(Bomberman::Button("Png/basic_option.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700, 450, 540, 120}));
    /*resume*/ this->btns.push_back(Bomberman::Button("Png/basic_home.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700, 600, 540, 120}));
    /*quit*/ this->btns.push_back(Bomberman::Button("Png/basic_exit.png",(Rectangle){0, 0, 540, 120}, (Rectangle){700, 750, 540, 120}));
    /*filler*/this->btns.push_back(Bomberman::Button("Png/+.png", (Rectangle){0, 0, 0, 0}, (Rectangle){0, 0, 0, 0}));
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
    static size_t limit = 0;
    if (is_title == true) {
        i = 0;
        limit = 4;
    } else if (is_options == true) {
        i = 4;
        limit = 8; 
    } else if (is_pause == true) {
        i = 8;
        limit = 13;
    }
    if (is_game || is_options || is_title || is_pause) {
        for (; i < limit; i++) {
            if (CheckCollisionPointRec(mousepos, btns[i].btnBounds)) {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    (btns[i].sourceRec.y = 344);
                else
                    btns[i].sourceRec.y = 175;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    break;
                }
            } else
                btns[i].sourceRec.y = 0;
        }
    }
    if (i != limit) (is_title = false);
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) (PlaySound(this->sfx));
    if ((IsKeyPressed(KEY_T) || i == 10) && (is_game == false)) {
        is_options = false;
        is_pause = false;
        is_game = false;
        is_title = true;
    }
    if (IsKeyPressed(KEY_SPACE)) (musiic.set_pause());
    if (IsKeyPressed(KEY_P)) (is_pause = !is_pause);
    if ((i == 8 || i == 11) && !is_options) (is_pause = !is_pause);
    if (i == 10 || i == 9) {
        if (i == 10) {
            (is_title = true);
        } else
            (is_options = true);
        is_game = false;
        is_pause = false;
    }
    if (i == 12) adios();
}

void Bomberman::Menu::pause()
{
    BeginDrawing();
        for (size_t i = 8; i < btns.size(); i++)
            DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
}

void Bomberman::Menu::game_options()
{
    static float volumesfx = 1;

    if (i == 0 || is_game) {
        game();
    } else if  (i == 1 || i == 9 || is_options) {
        is_pause = false;
        is_game = false;
        is_title = false;
        is_options = true;
        options();
    } else if  (i == 2 || i == 12) {
        adios();
    }
    //tuto if (i == 3) exit(0);
    if (i == 4) (this->musiic.set_volume(this->musiic.get_volume() + 2));
    if (i == 5) (volumesfx += 2);
    if (i == 6) (this->musiic.set_volume(this->musiic.get_volume() - 2));
    if (i == 7) (volumesfx -= 2);
    if (volumesfx < 0)
        volumesfx = 0;
    SetSoundVolume(this->sfx, volumesfx);
    if (is_pause) (pause());
}

void Bomberman::Menu::loop()
{
    if (is_title == true) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (size_t i = 0; i < 4; i++)
               DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
    } else {
        game_options();
    }
}

Bomberman::Menu::~Menu()
{
    UnloadSound(this->sfx);
    CloseAudioDevice();
    for (size_t i = 0; i < this->btns.size(); i++)
        UnloadTexture(this->btns[i].button);
}