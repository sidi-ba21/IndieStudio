/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"

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

typedef struct lt
{
    std::pair <float, float>coords;
    void (*lt2)(void);
}lt;

static void game()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("GAME THINGY", 100, 100, 100, BLACK);
    EndDrawing();
}

static void options()
{
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("OPTIONS", 100, 100, 100, WHITE);
    EndDrawing();   
}

static void adios()
{
    std::cout << "tocard" << std::endl;
    CloseAudioDevice();
    CloseWindow();
    exit(0);
}

static const lt tab[3] =
{
    {{960, 100}, &game},
    {{480, 700}, &options},
    {{320, 400}, &adios}
};

int main(void)
{
    bool is_paused = false;
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    Vector2 mousepos = { -100.0f, -100.0f };
    bool is_title = true;
    int i = -1;
    Music menu;
    Music sfx;

    InitWindow(screenWidth, screenHeight, "INDIE STUDIO");
    InitAudioDevice();
    menu = LoadMusicStream("./ressources/menu.mp3");
    sfx = LoadMusicStream("./ressources/explosion8bit.wav");
    PlayMusicStream(menu);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateMusicStream(menu);
        UpdateMusicStream(sfx);
        mousepos = GetMousePosition();
        SetMusicVolume(menu, 10);
        SetMusicVolume(sfx, 5);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            StopMusicStream(sfx);
            PlayMusicStream(sfx);
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
        if (IsKeyPressed(KEY_SPACE)) {
            is_paused = !is_paused;
            (is_paused == false) ? PauseMusicStream(menu) : ResumeMusicStream(menu);
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
            tab[i].lt2();
    }
    UnloadMusicStream(menu);
    //UnloadMusicStream(sfx);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}