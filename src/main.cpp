/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

#include <utility>
#include <iostream>
#include <string>
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
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    Vector2 mousepos = { -100.0f, -100.0f };
    bool is_title = true;
    int i = -1;

    InitWindow(screenWidth, screenHeight, "INDIE STUDIO");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        mousepos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            for (i = 0; i < 3; i++)
                if ((mousepos.x > tab[i].coords.first &&
                mousepos.x < tab[i].coords.first + 100) &&
                (mousepos.y > tab[i].coords.second &&
                mousepos.y < tab[i].coords.second + 100)) {
                    is_title = false;
                    break;
                }
            if (i == 3)
                is_title = true;
        }
        if (is_title == true) {
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY);

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
    CloseWindow();        // Close window and OpenGL context
    return 0;
}