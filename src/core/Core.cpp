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
    _camera.init();
    _map.init();

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
}

void Bomberman::Core::game_loop()
{
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        this->rt = _player.Player_move();
        this->r =  _player.Player_animation();
        _map.update();
        _camera.Camera_move();
        _score.update();
        Draw();
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
    DrawTextureEx(_map.get_cubicTexture(), (Vector2){screenWidth - _map.get_cubicTexture().width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(screenWidth - _map.get_cubicTexture().width * 4 - 20, 20, _map.get_cubicTexture().width * 4, _map.get_cubicTexture().height * 4, GREEN);
    DrawText("The map generated is : ", 1410, 20, 30, BLACK);
    DrawFPS(10, 1060);
    DrawText(TextFormat("SCORE: %i", _score.get_score()), 860, 110, 40, BLACK);
    DrawText(TextFormat("HI-SCORE: %i", _score.get_highscore()), 800, 50, 40, RED);
}

void Bomberman::Core::Draw3d()
{
    BeginMode3D(_camera.get_Camera());

    DrawModelEx(_player.get_Model(), _player.get_pos(1), (Vector3){ 0, 1, 0 }, r, (Vector3){1, 1, 1}, WHITE);
    DrawModelEx(_player.get_Model2(), _player.get_pos(2), (Vector3){ 0, 1, 0 }, rt, (Vector3){1, 1, 1}, WHITE);
    DrawModel(_map.get_model(), _map.get_pos(), 1.0f, WHITE);

    EndMode3D();
}


Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
