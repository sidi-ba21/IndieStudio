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
    _player.init();
    this->image = LoadImage("Png/perfect_map.png");   // Load cubicmap image (RAM)
    this->cubicmap = LoadTextureFromImage(image); // Convert image to texture to display (VRAM)
    this->mesh = GenMeshCubicmap(image, (Vector3){1.0f, 1.0f, 1.0f});
    this->model = LoadModelFromMesh(mesh);
    this->texture = LoadTexture("Png/grassbrick_cube.png"); // Load map texture

    SetCameraMode(camera, CAMERA_FREE);
    SetCameraMode(camera, CAMERA_ORBITAL); // Set an orbital camera mode
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture; // Set map diffuse texture

}

void Bomberman::Core::game_loop()
{
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Camera();
        _player.Player_move();
        _player.Player_animation();
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
    DrawFPS(10, 1060);
    DrawText(TextFormat("SCORE: %i", score), 860, 110, 40, BLACK);
    DrawText(TextFormat("HI-SCORE: %i", hiscore), 800, 50, 40, RED);
}

void Bomberman::Core::Draw3d()
{
    BeginMode3D(camera);

    DrawModel(_player.get_Model(), _player.get_position(1), 1, WHITE);
    DrawModel(_player.get_Model(), _player.get_position(2), 1, WHITE);
    DrawModel(model, mapPosition, 1.0f, WHITE);

    EndMode3D();
}


Bomberman::Core::~Core()
{
    UnloadImage(image); // Unload cubesmap image from RAM, already uploaded to VRAM
    UnloadTexture(cubicmap); // Unload cubicmap texture
    UnloadTexture(texture);  // Unload map texture
    UnloadModel(model);      // Unload map model

    CloseWindow(); // Close window and OpenGL context
}
