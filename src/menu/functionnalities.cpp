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
    is_game = false;
    is_options = true;
    is_tuto = false;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("OPTIONS", 0, 0, 80.0, MAGENTA);
        DrawText("MUSIC", 820, 425, 80.0, BLACK);
        DrawText("SOUND EFFECTS", 660, 725, 70.0, BLACK);
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
        DrawText("TUTORIAL", 0, 0, 80, MAGENTA);
        DrawText("Explode your ennemies to survive the arena!", 50, 350, 80, RAYWHITE);
        if (i != 0) DrawTextureEx(cmd, (Vector2){500, 500}, 0, 0.5, RAYWHITE);
        title_button();
}

void Bomberman::Menu::the_end()
{
    static int i = 0;
    size_t p = 0;
    if (i == 0) {
        face[0] = LoadTexture("Png/player_face_AI.png");
        face[1] = LoadTexture("Png/player_face2x.png");
        face[2] = LoadTexture("Png/player_face1x.png");
        face[3] = LoadTexture("Png/victory.png");
        immg.push_back(Bomberman::Button("Png/basic_home.png", (Rectangle){0, 0, 540, 120}, (Rectangle){200, 900, 540, 120}));
        immg.push_back(Bomberman::Button("Png/basic_exit.png",(Rectangle){0, 0, 540, 120}, (Rectangle){1100, 900, 540, 120}));
        immg[0].init();
        immg[1].init();
        (i++);
    } else {
        SetSoundVolume(sfx, 0);
        SetMusicVolume(musiic.get_ost(), 0);
        is_game = false;
        is_options = false;
        is_title = false;
        is_tuto = false;
        is_pause = false;
        is_finished = true;
        for (p = 0; p < immg.size(); p++) {
            if (CheckCollisionPointRec(mousepos, immg[p].btnBounds)) {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                    (immg[p].sourceRec.y = 344);
                } else
                    immg[p].sourceRec.y = 175;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                    break;
            } else
                immg[p].sourceRec.y = 0;
        }
    }
    if (p == 0) {
        is_finished = false;
        is_title = true;
        already_clicked = true;
    }
    if (p == 1) {
        is_finished = false;
        adios();
    }
    BeginDrawing();
        //ClearBackground(RAYWHITE);
        DrawText("ENDING", 0, 0, 80, MAGENTA);
        if (id != 0)
            DrawText(TextFormat("PLAYER %u WON !!", id), 50, 600, 80, YELLOW);
        else 
            DrawText("AI WON ! TOO BAD", 50, 600, 80, YELLOW);
        DrawTextureRec(immg[0].button, immg[0].sourceRec, (Vector2){ immg[0].btnBounds.x, immg[0].btnBounds.y }, RAYWHITE);
        DrawTextureRec(immg[1].button, immg[1].sourceRec, (Vector2){ immg[1].btnBounds.x, immg[1].btnBounds.y }, RAYWHITE);
        DrawText(TextFormat("SCORE : %u", score), 1200, 600, 80, YELLOW);
        DrawTextureEx(face[3], Vector2{610, -50}, 0, 0.85,  RAYWHITE);
        DrawTexture(face[id], 850, 500, RAYWHITE);
}