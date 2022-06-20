/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

#include <unistd.h>
#include "menu.hpp"


void Bomberman::Menu::title_button()
{
    if (is_options == true || is_tuto == true)
        btns[10].btnBounds = (Rectangle){680, 200, 540, 120};
    else
        btns[10].btnBounds = (Rectangle){700, 600, 540, 120};
    if (CheckCollisionPointRec(mousepos, btns[10].btnBounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            (btns[10].sourceRec.y = 344);
        } else
            btns[10].sourceRec.y = 175;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            if (is_options == true && is_pause == true) {
                is_options = false;
                is_pause = true;
                is_game = true;
                is_title = false;
                is_tuto = false;
                already_clicked = false;
            }else {
                is_options = false;
                is_pause = false;
                is_game = false;
                is_title = true;
                is_tuto = false;
                already_clicked = true;
            }
        }
    } else
        btns[10].sourceRec.y = 0;
    DrawTextureRec(btns[10].button, btns[10].sourceRec, (Vector2){ btns[10].btnBounds.x, btns[10].btnBounds.y }, RAYWHITE);
}

void Bomberman::Menu::update()
{
    UpdateMusicStream(musiic.get_ost());
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    mousepos = GetMousePosition();
    static size_t limit = 0;
    if (is_title == true && !is_options) {
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
                (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) ? btns[i].sourceRec.y = 344 : btns[i].sourceRec.y = 175;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) break;
            } else
                btns[i].sourceRec.y = 0;
        }
    }
    if (i != limit) (is_title = false);
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) (PlaySound(this->sfx));
    if ((IsKeyPressed(KEY_T) && (is_game == false)) || (i == 10)){
        is_options = false;
        is_pause = false;
        is_game = false;
        is_title = true;
        is_tuto = false;
        already_clicked = true;
    }
    if (IsKeyPressed(KEY_SPACE)) {
        (musiic.set_pause());
        if (musiic.get_pause() == true)
            SetSoundVolume(sfx, 0);
        else
            SetSoundVolume(sfx, 2);
    }
    if (IsKeyPressed(KEY_P)) (is_pause = !is_pause);
    if ((i == 8) && !is_options) (is_pause = !is_pause);
    if (i == 11 || i == 2) adios();
    if (i == 1 || i == 9 || is_options) options();
    if (IsKeyPressed(KEY_U)) {
        is_title = false;
        is_options = false;
        is_game = false;
        is_pause = false;
        is_tuto = false;
        is_finished = true;
    }
}


void Bomberman::Menu::game_options()
{
    handle_volume();
    if (is_finished) {
        the_end();
    }
    if (i == 0 || is_game) {
        game();
    } else if (i == 1 || i == 9 || is_options) {
        options();
    } else if  (i == 2 || i == 11)
        adios();
    if (i == 3 || is_tuto == true) tuto();
    if (is_pause && !is_options) (pause());
}

void Bomberman::Menu::handle_volume()
{
    static float volumesfx = 1.0;

    if (i == 4) (this->musiic.set_volume(this->musiic.get_volume() + 2));
    if (i == 5) (volumesfx += 2);
    if (i == 6) (this->musiic.set_volume(this->musiic.get_volume() - 2));
    if (i == 7) (volumesfx -= 2);
    if (volumesfx < 0) volumesfx = 0;
    if (this->musiic.get_volume() <= 0) this->musiic.set_volume(0);
    SetSoundVolume(this->sfx, volumesfx);
    if (musiic.get_pause() == true)
        SetSoundVolume(this->sfx, 0);
    SetMusicVolume(this->musiic.get_ost(), this->musiic.get_volume());
}

void Bomberman::Menu::loop()
{
    if (is_title == true) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (size_t i = 0; i < 4; i++)
               DrawTextureRec(btns[i].button, btns[i].sourceRec, (Vector2){ btns[i].btnBounds.x, btns[i].btnBounds.y }, RAYWHITE);
    } else
        game_options();
}
