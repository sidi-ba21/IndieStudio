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

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    float x = 0;
    float y = 0;

    InitWindow(screenWidth, screenHeight, "BOOOOOMBERMAAN");
    Camera3D camera = (Camera3D){(Vector3){-5, 8, -5}, (Vector3){0, 2, 0}, (Vector3){0, 2, 0}, 45, CAMERA_PERSPECTIVE};
    float cam_radius = 20;
    float cam_angle = 1.57;
    ToggleFullscreen();
    SetCameraMode(camera, CAMERA_FREE);

    Model model_test = LoadModel("../assets/robo6.iqm");
    unsigned int animsCount = 2;
    ModelAnimation *anims = LoadModelAnimations("../assets/robo6.iqm", &animsCount);
    int animFrameCounter = 0;

    // Load model texture

    Texture2D player = LoadTexture("../assets/txr.png");
    SetMaterialTexture(&model_test.materials[0], MATERIAL_MAP_DIFFUSE, player);

    Image image = LoadImage("../Png/2.png");          // Load cubicmap image (RAM)
    Texture2D cubicmap = LoadTextureFromImage(image); // Convert image to texture to display (VRAM)

    Mesh mesh = GenMeshCubicmap(image, (Vector3){1.0f, 1.0f, 1.0f});
    Model model = LoadModelFromMesh(mesh);

    // NOTE: By default each cube is mapped to one part of texture atlas
    Texture2D texture = LoadTexture("../Png/cubicmap_atlas.png");    // Load map texture
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture; // Set map diffuse texture

    Vector3 mapPosition = {-16.0f, 0.0f, -8.0f}; // Set model position

    UnloadImage(image); // Unload cubesmap image from RAM, already uploaded to VRAM

    SetCameraMode(camera, CAMERA_ORBITAL); // Set an orbital camera mode

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        UpdateCamera(&camera); // Update camera

        if (IsKeyDown('Q'))
            cam_angle += 0.12;
        if (IsKeyDown('E'))
            cam_angle -= 0.12;
        camera.position.x = cam_radius * cos(cam_angle);
        camera.position.z = cam_radius * sin(cam_angle);

        /* UPDATE ANIMATION */

        if (IsKeyDown(KEY_SPACE))
        {
            UpdateModelAnimation(model_test, anims[1], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[1].frameCount)
                animFrameCounter = 0;
        }

        if (IsKeyDown(KEY_UP))
        {
            UpdateModelAnimation(model_test, anims[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[0].frameCount)
                animFrameCounter = 0;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            UpdateModelAnimation(model_test, anims[2], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[2].frameCount)
                animFrameCounter = 0;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawModel(model_test, (Vector3){x, 0.1, y}, 1, WHITE);

        if (IsKeyDown(KEY_LEFT))
            x += 0.02;
        if (IsKeyDown(KEY_RIGHT))
            x -= 0.02;
        if (IsKeyDown(KEY_UP))
            y += 0.02;
        if (IsKeyDown(KEY_DOWN))
            y -= 0.02;

        DrawModel(model, mapPosition, 1.0f, WHITE);
        EndMode3D();

        DrawTextureEx(cubicmap, (Vector2){screenWidth - cubicmap.width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
        DrawRectangleLines(screenWidth - cubicmap.width * 4 - 20, 20, cubicmap.width * 4, cubicmap.height * 4, GREEN);

        DrawText("cubicmap image used to", 658, 90, 10, GRAY);
        DrawText("generate map 3d model", 658, 104, 10, GRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(cubicmap); // Unload cubicmap texture
    UnloadTexture(texture);  // Unload map texture
    UnloadModel(model);      // Unload map model

    for (unsigned int i = 0; i < animsCount; i++)
        UnloadModelAnimation(anims[i]);
    RL_FREE(anims);

    UnloadModel(model_test);

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}