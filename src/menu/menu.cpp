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
    this->is_options = false;
}

void Bomberman::Menu::options()
{
    is_title = false;
    is_game = false;
    is_options = true;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("OPTIONS", 0, 0, 100.0, WHITE);
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
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitAudioDevice();
    this->musiic.init("./sounds/menu.mp3", 2, false);
    this->sfx = LoadSound("./sounds/explosion8bit.wav");

    this->btns.push_back(Bomberman::Button("Png/play.png", (Rectangle){900.0, 300.0, 100.0, 100.0}, (Rectangle){900.0, 300.0, 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/options.png", (Rectangle){200.0, 700.0, 100.0, 100.0}, (Rectangle){200.0, 700.0, 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/exit.png", (Rectangle){900.0, 700.0, 100.0, 100.0}, (Rectangle){900.0, 700.0, 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/tutorial.png",(Rectangle){1200.0, 700.0, 100.0, 100.0}, (Rectangle){1200.0, 700.0, 100.0, 100.0}));

    this->btns.push_back(Bomberman::Button("Png/+.png",(Rectangle){1300.0, 400.0, 100.0, 100.0}, (Rectangle){1300.0, 400.0, 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/+.png",(Rectangle){1300.0, 700.0, 100.0, 100.0}, (Rectangle){1300.0, 700.0, 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/-.png",(Rectangle){400.0, 400.0, 100.0, 100.0}, (Rectangle){400.0, 400.0, 100.0, 100.0}));
    this->btns.push_back(Bomberman::Button("Png/-.png",(Rectangle){400.0, 700.0, 100.0, 100.0}, (Rectangle){400.0, 700.0, 100.0, 100.0}));

    /*PAUSE
    this->btns.push_back(Bomberman::Button("",(Rectangle){}, (Rectangle){}));
    this->btns.push_back(Bomberman::Button("",(Rectangle){}, (Rectangle){}));
    this->btns.push_back(Bomberman::Button("",(Rectangle){}, (Rectangle){}));
    this->btns.push_back(Bomberman::Button("",(Rectangle){}, (Rectangle){}));
    this->btns.push_back(Bomberman::Button("",(Rectangle){}, (Rectangle){}));
    */
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
        limit = 12;
    }
    if (is_game || is_options || is_title || is_pause) {
        for (; i < limit; i++) {
            if (CheckCollisionPointRec(mousepos, btns[i].btnBounds)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    (btns[i].sourceRec.x = 200);
                else
                    btns[i].sourceRec.x = 100.0;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    break;
                }
            } else
                btns[i].sourceRec.x = 0;
        }
    }
    if (i != limit) (is_title = false);
    (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) ? PlaySound(this->sfx) : (void)1;
    (IsKeyPressed(KEY_T)) ? (is_title = true) : true;
    (IsKeyPressed(KEY_SPACE)) ? musiic.set_pause() : (void)1;
}

void Bomberman::Menu::game_options()
{
    static float volumesfx = 1;


    if (i == 0 || is_game) {
        game();
    } else if  (i == 1 || is_options) {
        options();
    } else if  (i == 2) {
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