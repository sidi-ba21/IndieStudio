/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "Core.hpp"
#include <unistd.h>

Bomberman::Core::Core()
{
    InitWindow(screenWidth, screenHeight, "BOOOOOMBERMAAN");
    ToggleFullscreen();
    init();
    game_loop();
}

void Bomberman::Core::init(void)
{
    this->background = LoadTexture("Png/game_background.png"); // Load map texture
    _player.init();
    _camera.init();
    _map.init();
    _menu.init();
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    this->mapPixels = LoadImageColors(_map.get_image());
}

void Bomberman::Core::game_loop()
{
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        DrawTextureV(background, Vector2{0, 0}, WHITE);
        this->rt = _player.Player_move();
        this->r = _player.Player_animation(this->mapPixels, this->_map.get_cubicTexture());
        _map.update();
        _camera.Camera_move();
        _score.update();
        _menu.update();
        Draw();
    }
}

void Bomberman::Core::Draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    if (_menu.get_game() == true)
    {
        Draw3d();
        Draw2d();
    }
    else
        _menu.loop();
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

    DrawModelEx(_player.get_Model(), _player.get_pos(1), (Vector3){0, 1, 0}, r, (Vector3){1, 1, 1}, WHITE);
    DrawModelEx(_player.get_Model2(), _player.get_pos(2), (Vector3){0, 1, 0}, rt, (Vector3){1, 1, 1}, WHITE);
    DrawModel(_map.get_model(), _map.get_pos(), 1.0f, WHITE);
    if (IsKeyPressed(KEY_RIGHT_SHIFT))
    {
        _bomb_pos = _player.get_pos(1);
        pressed = 1;
    }
    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT))
    {
        _bomb_pos2 = _player.get_pos(2);
        pressed2 = 1;
    }
    if (pressed == 1)
    {
        DrawSphere(Vector3{_bomb_pos}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos}, 0.3, 10, 10, BROWN);
    }
    if (pressed2 == 1)
    {
        DrawSphere(Vector3{_bomb_pos2}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos2}, 0.3, 10, 10, BROWN);
    }
    if (IsKeyReleased(KEY_RIGHT_SHIFT))
    {
        for (time = 0; time < 3; time++)
        {
            if (time == 3) {
            DrawRectangleLines(_bomb_pos.x, _bomb_pos.y, _bomb_pos.x + 1, _bomb_pos.y + 1, RED);
            pressed = 4;
            time = 0;
        }
        }
    }
    if (IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyReleased(KEY_LEFT_SHIFT))
    {
        pressed2 = 4;
    }
    EndMode3D();
}

Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
