/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

/* Circle shapes and lines
DrawCircle(screenWidth/5, 120, 35, DARKBLUE);
DrawCircleGradient(screenWidth/5, 220, 60, GREEN, SKYBLUE);
DrawCircleLines(screenWidth/5, 340, 80, DARKBLUE);*/

/* Triangle shapes and lines
DrawTriangle((Vector2){screenWidth/4.0f *3.0f, 80.0f},
             (Vector2){screenWidth/4.0f *3.0f - 60.0f, 150.0f},
             (Vector2){screenWidth/4.0f *3.0f + 60.0f, 150.0f}, VIOLET);
DrawTriangleLines((Vector2){screenWidth/4.0f*3.0f, 160.0f},
                  (Vector2){screenWidth/4.0f*3.0f - 20.0f, 230.0f},
                  (Vector2){screenWidth/4.0f*3.0f + 20.0f, 230.0f}, DARKBLUE);*/

/*Polygon shapes and lines
DrawPoly((Vector2){screenWidth/4.0f*3, 320}, 6, 80, 0, BROWN);
DrawPolyLinesEx((Vector2){screenWidth/4.0f*3, 320}, 6, 80, 0, 6, BEIGE);
*/

#include "menu.hpp"

int screenWidth = 480;
int screenHeight = 1080;

void game(ost &obj, Vector2 mousepos)
{
    (void)obj;
    (void)mousepos;
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("GAME THINGY", 100, 100, 100, BLACK);
    EndDrawing();
}

void options(ost &obj, Vector2 mousepos)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (int i = 3; i < 7; i++)
            if ((mousepos.x > tab[i].coords.first &&
            mousepos.x < tab[i].coords.first + 50) &&
            (mousepos.y > tab[i].coords.second &&
            mousepos.y < tab[i].coords.second + 50)) {
                tab[i].lt2(obj, mousepos);
                break;
        }
    }
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("OPTIONS", 0, 0, 100, WHITE);
        DrawRectangle(455, 270, 100, 100, RED);
        DrawText("-", 480, 270, 100, WHITE);
        DrawRectangle(455, 810, 100, 100, RED);
        DrawText("-", 480, 810, 100, WHITE);
        DrawRectangle(1415, 270, 100, 100, RED);
        DrawText("+", 1440, 270, 100, WHITE);
        DrawRectangle(1415, 810, 100, 100, RED);
        DrawText("+", 1440, 810, 100, WHITE);
    EndDrawing();   
}

void adios(ost &obj, Vector2 mousepos)
{
    (void)mousepos;
    (void)obj;
    CloseAudioDevice();
    CloseWindow();
    exit(0);
}

void minus(ost &obj, Vector2 mousepos)
{
    (void)mousepos;
    obj.set_volume(obj.get_volume() - 2);
}

void plus(ost &obj, Vector2 mousepos)
{
    (void)mousepos;
    obj.set_volume(obj.get_volume() + 2);
}


int main(void)
{
    Vector2 mousepos = { -100.0f, -100.0f };
    bool is_title = true;
    int i = -1;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitAudioDevice();
    ost menu("./ressources/menu.mp3", 10, false);
    ost sfx("./ressources/explosion8bit.wav", 5, false);

    InitWindow(screenWidth, screenHeight, "INDIE STUDIO");
    PlayMusicStream(menu.get_ost());

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
        UpdateMusicStream(menu.get_ost());
        UpdateMusicStream(sfx.get_ost());
        mousepos = GetMousePosition();
        if ((GetMusicTimePlayed(sfx.get_ost())/GetMusicTimeLength(sfx.get_ost())) > 1)
            StopMusicStream(sfx.get_ost());
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_title == true) {
            StopMusicStream(sfx.get_ost());
            PlayMusicStream(sfx.get_ost());
            for (i = 0; i < 3; i++)
                if ((mousepos.x > tab[i].coords.first &&
                mousepos.x < tab[i].coords.first + 100) &&
                (mousepos.y > tab[i].coords.second &&
                mousepos.y < tab[i].coords.second + 100)) {
                    is_title = false;
                    break;
                }
            (i == 3) ? is_title = true : i;
        }
        (IsKeyPressed(KEY_T)) ? (is_title = true) : true;
        if (IsKeyPressed(KEY_SPACE)) {
            menu.set_pause();
        }
        if (IsKeyPressed(KEY_R)) {
            StopMusicStream(menu.get_ost());
            PlayMusicStream(menu.get_ost());
        }
        if (is_title == true) {
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawRectangle(screenWidth/2, 100, 100, 100, RED);
                DrawText("GAME", screenWidth/2, 100, 20, BLACK);
                DrawRectangle(screenWidth/4, 700, 100, 100, GREEN);
                DrawText("OPTIONS", screenWidth/4, 700, 20, BLACK);
                DrawRectangle(screenWidth/6, 400, 100, 100, BLUE);
                DrawText("EXIt", screenWidth/6, 400, 20, BLACK);

                DrawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, GREEN);

                DrawLine(18, 42, screenWidth - 18, 42, BLACK);
            EndDrawing();
        } else 
            tab[i].lt2(menu, mousepos);
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}