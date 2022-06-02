/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

#include "raylib.h"
#include <math.h>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Bomberman");
    ToggleFullscreen();

    Vector3 cubePosition = {0.0f, .0f, 10.0f};
    Vector3 cubePosition1 = {0.0f, .0f, -10.0f};
    Vector3 cubePosition2 = {-10.0f, .0f, 0.0f};
    Vector3 cubePosition3 = {10.0f, .0f, 0.0f};
    Vector3 cubePosition4 = {0.0f, .0f, 0.0f};

    Camera3D camera = (Camera3D){(Vector3){-5, 8, -5}, (Vector3){0, 2, 0}, (Vector3){0, 2, 0}, 45, CAMERA_PERSPECTIVE};

    float cam_radius = 15;
    float cam_angle = 1.57;
    int size = 20;
    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera); // Update camera

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);
        if (IsKeyDown('Q'))
            cam_angle += 0.12;
        if (IsKeyDown('E'))
            cam_angle -= 0.12;
        camera.position.x = cam_radius * cos(cam_angle);
        camera.position.z = cam_radius * sin(cam_angle);
        BeginMode3D(camera);

        for (float cube = 0.0; cube < size; cube++)
        {
            DrawCube(cubePosition, cube, 2.0f, 1.0f, RED);
               DrawCubeWires(cubePosition, cube, 2, 1, BLACK);
            DrawCube(cubePosition1, cube, 2.0f, 1.0f, RED);
         DrawCubeWires(cubePosition1, cube, 2, 1, BLACK);
            DrawCube(cubePosition2, 1, 2.0f, cube, RED);
              DrawCubeWires(cubePosition2, 1, 2, cube, BLACK);
            DrawCube(cubePosition3, 1, 2.0f, cube, RED);
              DrawCubeWires(cubePosition3, 1, 2, cube, BLACK);
            DrawCube(cubePosition4, cube, 1.0f, cube, GRAY);
            //  DrawCubeWires(cubePosition4, cube, 1, cube, BLACK);
        }

        DrawCube(cubePosition4, 1, 3.0f, 1, BLACK);
        DrawGrid(size, 1.0f);

        EndMode3D();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}