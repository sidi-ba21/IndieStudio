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
//    this->mapPixels[7 * this->_map.get_cubicTexture().width + 15] = YELLOW;
    for (int y = 0; y < 16; y++)
        for (int x = 0; x < 32; x++)
        printf ("color %d, %d, %d, %d\n", this->mapPixels[y* this->_map.get_cubicTexture().width + x].r,
        this->mapPixels[y* this->_map.get_cubicTexture().width + x].g, this->mapPixels[y* this->_map.get_cubicTexture().width + x].b, this->mapPixels[y* this->_map.get_cubicTexture().width + x].a);
    auto red = RED;
    printf ("Red Color %d, %d, %d, %d\n", red.r, red.g, red.b, red.a);
}

void Bomberman::Core::game_loop()
{
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        DrawTextureV(background, Vector2{0, 0}, WHITE);
        this->rt = _player.Player_move(this->mapPixels, this->_map.get_cubicTexture());
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
    auto texture = LoadTexture("Png/woodx_brick.png");
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 32; x++) {
            if (COLOR_EQUAL(mapPixels[y* this->_map.get_cubicTexture().width + x], RED))
                DrawCubeTexture(texture, Vector3 {x - 16.0f, 0.5, y - 8.f},
                1,1,1, WHITE);
        }
    }
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && pressed < 1)
    {
        _bomb_pos = _player.get_pos(1);
        pressed = 1;
        this->time1 = std::time(nullptr);
    }
    if (pressed > 0 && pressed < 3)
    {
        DrawSphere(Vector3{_bomb_pos}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos}, 0.3, 10, 10, BROWN);
    }
        if (IsKeyReleased(KEY_RIGHT_SHIFT))
    {
        pressed = 2;
    }
    if (pressed == 2 || pressed == 3)
    {
        printf("%li\n", std::time(nullptr) - this->time1);
        std::time_t now = std::time(nullptr);
        if (now - time1 > 6)
            pressed = 0;
        else if (now - time1 > 3)
        {
            printf("%.2f, %.2f, %.2f\n", (float)(int)(_bomb_pos.x - 1), (float)(int)_bomb_pos.y, (float)(int)_bomb_pos.z);
            DrawCube(Vector3{(float)(int)(_bomb_pos.x - 1), _bomb_pos.y, (float)(int)_bomb_pos.z}, 3, 1, 1, RED);
            DrawCube(Vector3{(float)(int)(_bomb_pos.x - 1), _bomb_pos.y, (float)(int)(_bomb_pos.z)}, 1, 1, 3, RED);
            pressed = 3;
        }
    }

    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT)) && pressed2 < 1)
    {
        _bomb_pos2 = _player.get_pos(2);
        pressed2 = 1;
        this->time2 = std::time(nullptr);
    }
    if (pressed2 > 0 && pressed2 < 3)
    {
        DrawSphere(Vector3{_bomb_pos2}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos2}, 0.3, 10, 10, BROWN);
    }
    if (IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyReleased(KEY_LEFT_SHIFT))
    {
        pressed2 = 2;
    }
    if (pressed2 == 2 || pressed2 == 3)
    {
        printf("%li\n", std::time(nullptr) - this->time2);
        std::time_t now2 = std::time(nullptr);
        if (now2 - time2 > 6)
            pressed2 = 0;
        else if (now2 - time2 > 3)
        {
            printf("%.2f, %.2f, %.2f\n", (float)(int)(_bomb_pos2.x - 1), (float)(int)_bomb_pos2.y, (float)(int)_bomb_pos2.z);
            DrawCube(Vector3{(float)(int)(_bomb_pos2.x - 1), _bomb_pos2.y, (float)(int)_bomb_pos2.z}, 3, 1, 1, RED);
            DrawCube(Vector3{(float)(int)(_bomb_pos2.x - 1), _bomb_pos2.y, (float)(int)(_bomb_pos2.z)}, 1, 1, 3, RED);
            pressed2 = 3;
        }
    }
    EndMode3D();
}

Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
