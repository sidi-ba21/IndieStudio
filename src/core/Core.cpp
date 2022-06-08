/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "Core.hpp"

Bomberman::Core::Core()
{
    InitWindow(screenWidth, screenHeight, "BOOOOOMBERMAAN");
    ToggleFullscreen();
    init();
    game_loop();
}

void Bomberman::Core::init(void)
{
    this->model_test = LoadModel("assets/robo6.iqm");
    this->anims = LoadModelAnimations("assets/robo6.iqm", &animsCount);
    this->player = LoadTexture("assets/cubex.png");
    this->image = LoadImage("Png/perfect_map.png");   // Load cubicmap image (RAM)
    this->cubicmap = LoadTextureFromImage(image); // Convert image to texture to display (VRAM)
    this->mesh = GenMeshCubicmap(image, (Vector3){1.0f, 1.0f, 1.0f});
    this->model = LoadModelFromMesh(mesh);
    this->texture = LoadTexture("Png/grassbrick_cube.png"); // Load map texture

    SetCameraMode(camera, CAMERA_FREE);
    SetCameraMode(camera, CAMERA_ORBITAL); // Set an orbital camera mode
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    SetMaterialTexture(&model_test.materials[0], MATERIAL_MAP_DIFFUSE, player);

    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture; // Set map diffuse texture

    //--------------------------------------------------------------------------------------
}

void Bomberman::Core::game_loop()
{
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Camera();
        Player();
        Score();
        Draw();
    }
}


void Bomberman::Core::Camera()
{
    UpdateCamera(&camera); // Update camera

    if (IsKeyDown(KEY_ONE))
        cam_angle += 0.12;
    if (IsKeyDown(KEY_TWO))
        cam_angle -= 0.12;
    camera.position.x = cam_radius * cos(cam_angle);
    camera.position.z = cam_radius * sin(cam_angle);
}

void Bomberman::Core::Player()
{
    Player_animation();
    Player_move();
}

void Bomberman::Core::Player_animation()
{
        if (IsKeyDown(KEY_SPACE)) {
            UpdateModelAnimation(model_test, anims[1], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[1].frameCount)
                animFrameCounter = 0;
            score = GetRandomValue(1000, 2000);
            hiscore = GetRandomValue(2000, 4000);
        }
        if (IsKeyDown(KEY_UP)) {
            UpdateModelAnimation(model_test, anims[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[0].frameCount)
                animFrameCounter = 0;
            y -= 0.09;
            r = 180;
        }
        if (IsKeyDown(KEY_DOWN)) {
            UpdateModelAnimation(model_test, anims[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[0].frameCount)
                animFrameCounter = 0;
            y += 0.09;
            r = 0;
        }
        if (IsKeyDown(KEY_LEFT)) {
            UpdateModelAnimation(model_test, anims[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[0].frameCount)
                animFrameCounter = 0;
            x -= 0.09;
            r = -90;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            UpdateModelAnimation(model_test, anims[0], animFrameCounter);
            animFrameCounter++;
            if (animFrameCounter >= anims[0].frameCount)
                animFrameCounter = 0;
            x += 0.09;
            r = 90;
        }
}

void Bomberman::Core::Player_move()
{
    if (IsKeyDown(KEY_Q))
        q += 0.02;
    if (IsKeyDown(KEY_E))
        q -= 0.02;
    if (IsKeyDown(KEY_W))
        v += 0.02;
    if (IsKeyDown(KEY_S))
        v -= 0.02;
}

void Bomberman::Core::Score()
{
    if (IsKeyPressed(KEY_SPACE)) {
        score = GetRandomValue(1000, 2000);
        hiscore = GetRandomValue(2000, 4000);
    }
}

void Bomberman::Core::Draw()
{        
    BeginDrawing();

    ClearBackground(RAYWHITE);
    Draw3d();
    Draw2d();

    EndDrawing();
}

void Bomberman::Core::Draw2d()
{
    DrawTextureEx(cubicmap, (Vector2){screenWidth - cubicmap.width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(screenWidth - cubicmap.width * 4 - 20, 20, cubicmap.width * 4, cubicmap.height * 4, GREEN);
    DrawText("The map generated is : ", 1410, 20, 30, BLACK);
    //   DrawText(GetTime, 1410, 20, 30, GREEN);
    DrawFPS(10, 1060);
    DrawText(TextFormat("SCORE: %i", score), 860, 110, 40, BLACK);
    DrawText(TextFormat("HI-SCORE: %i", hiscore), 800, 50, 40, RED);
}

void Bomberman::Core::Draw3d()
{
    BeginMode3D(camera);

    DrawModelEx(model_test, (Vector3){x, 0.1, y}, (Vector3){ 0, 1, 0 }, r, (Vector3){1, 1, 1}, WHITE);
    DrawModel(model_test, (Vector3){q, 0.1, v}, 1, WHITE);
    DrawModel(model, mapPosition, 1.0f, WHITE);

    EndMode3D();
}


Bomberman::Core::~Core()
{
    UnloadImage(image); // Unload cubesmap image from RAM, already uploaded to VRAM
    UnloadTexture(cubicmap); // Unload cubicmap texture
    UnloadTexture(texture);  // Unload map texture
    UnloadModel(model);      // Unload map model

    for (unsigned int i = 0; i < animsCount; i++)
       UnloadModelAnimation(anims[i]);
    RL_FREE(anims);

    UnloadModel(model_test);
    CloseWindow(); // Close window and OpenGL context
}
