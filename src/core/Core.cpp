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
    _background.init();
    _map.init();
    _player.init();
    _ai.init_AI();
    _camera.init();
    _menu.init();
    _box.init();
    SetTargetFPS(60); 
}

void Bomberman::Core::game_loop()
{
    while (!WindowShouldClose()) {
        if (_menu.get_pause() == false) {
            _ai.move_AI(_map.get_color(), _map.get_cubicTexture());
            _player.Player_move1(_map.get_color(), _map.get_cubicTexture());
            _player.Player_move2(_map.get_color(), _map.get_cubicTexture());
            _map.update();
            _camera.Camera_move();
        }
        Draw();
        _menu.update();
    }
}

void Bomberman::Core::Draw()
{
    BeginDrawing();

    _background.draw();
    ClearBackground(RAYWHITE);
    if (_menu.get_game() == true) {
        Draw2d();
        Draw3d();
        if (_menu.get_pause() == true)
            _menu.pause();
    }
    else
        _menu.loop();

    EndDrawing();
}

void Bomberman::Core::Draw2d()
{
    DrawTextureEx(_map.get_cubicTexture(), (Vector2){screenWidth - _map.get_cubicTexture().width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(screenWidth - _map.get_cubicTexture().width * 4 - 20, 20, _map.get_cubicTexture().width * 4, _map.get_cubicTexture().height * 4, GREEN);
    DrawText("The map generated is : ", 1410, 20, 30, MAGENTA);
    DrawFPS(10, 1060);

    DrawText(TextFormat("SCORE PLAYER1: %i", _score.get_score1()), 15, 80, 30, MAGENTA);
    DrawText(TextFormat("SCORE PLAYER2: %i", _score.get_score2()), 15, 120, 30, MAGENTA);
    DrawText(TextFormat("SCORE AI: %i", _score.get_score_AI()), 15, 160, 30, MAGENTA);
    _score.writeScore(std::to_string(_score.get_score1()));
    _score.writeScore(std::to_string(_score.get_score2()));
    _score.writeScore(std::to_string(_score.get_score_AI()));
    DrawText(TextFormat("HI-SCORE: %s", _score.getHightScore().c_str()), 15, 20, 40, RED);
    auto tmp = GetTime();
    auto minutes = (float)(int)tmp / 60;
    auto seconds = (float)((int)tmp % 60);
    DrawText(TextFormat("Elapsed Time: %02.0f : %02.0f", minutes, seconds), 800, 100, 40, MAGENTA);
}

void Bomberman::Core::Draw_breakabke()
{
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 32; x++) {
            if (COLOR_EQUAL(_map.get_color()[y * this->_map.get_cubicTexture().width + x], RED)) {
                DrawCubeTexture(_box.get_breakable_texture(), Vector3{x - 16.0f, 0.5, y - 8.f},
                                1, 1, 1, WHITE);
            }
            if (COLOR_EQUAL(_map.get_color()[y * this->_map.get_cubicTexture().width + x], BLACK)) {
                DrawCubeTextureRec(_box.get_grass_texture(), _box.get_rectGrass(), {x - 16.0f, 0.1, y - 8.f},
                                   1, 0, 1, WHITE);
            }
            if (COLOR_EQUAL(_map.get_color()[y * this->_map.get_cubicTexture().width + x], WHITE)) {
                DrawCubeTexture(_box.get_brick_texture(), {x - 16.0f, 0.5, y - 8.f},
                                1, 1, 1, WHITE);
            }
        }
    }
}

void Bomberman::Core::Remove_breakable(Vector3 pos)
{
    int x = pos.x + 16;
    int y = pos.z + 8;
    
    if (COLOR_EQUAL(_map.get_color()[y * _map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(_map.get_color()[y * _map.get_cubicTexture().width + x], BLACK))
    {
        _map.get_color()[y * _map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), _bomb_pos.y, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (x < 15 && (COLOR_EQUAL(_map.get_color()[y * _map.get_cubicTexture().width + x + 1], RED) || COLOR_EQUAL(_map.get_color()[y * _map.get_cubicTexture().width + x + 1], BLACK)))
    {
        _map.get_color()[y * _map.get_cubicTexture().width + x + 1] = BLACK;
        DrawCube(Vector3{(float)(x + 1 - 16), _bomb_pos.y, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (x > -15 && (COLOR_EQUAL(_map.get_color()[y * _map.get_cubicTexture().width + x - 1], RED) || COLOR_EQUAL(_map.get_color()[y * _map.get_cubicTexture().width + x - 1], BLACK)))
    {
        _map.get_color()[y * _map.get_cubicTexture().width + x - 1] = BLACK;
        DrawCube(Vector3{(float)(x - 1 - 16), _bomb_pos.y, (float)(y - 8)}, 1, 1, 1, RED);
    }
    if (y < 7 && (COLOR_EQUAL(_map.get_color()[(y + 1) * _map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(_map.get_color()[(y + 1) * _map.get_cubicTexture().width + x], BLACK)))
    {
        _map.get_color()[(y + 1) * _map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), _bomb_pos.y, (float)(y + 1 - 8)}, 1, 1, 1, RED);
    }
    if (y > -7 && (COLOR_EQUAL(_map.get_color()[(y - 1) * _map.get_cubicTexture().width + x], RED) || COLOR_EQUAL(_map.get_color()[(y - 1) * _map.get_cubicTexture().width + x], BLACK)))
    {
        _map.get_color()[(y - 1) * _map.get_cubicTexture().width + x] = BLACK;
        DrawCube(Vector3{(float)(x - 16), _bomb_pos.y, (float)(y - 1 - 8)}, 1, 1, 1, RED);
    }
}

void Bomberman::Core::set_Bomb_AI()
{
    if (pressed_AI < 1)
    {
        _bomb_pos_AI = _ai.get_pos();
        printf("%2.f, %2.f\n", _bomb_pos_AI.x, _bomb_pos_AI.z);
        pressed_AI = 1;
        this->time1 = std::time(nullptr);
    }
    if (pressed_AI > 0 && pressed_AI < 3)
    {
        DrawSphere(Vector3{_bomb_pos_AI}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos_AI}, 0.3, 10, 10, BROWN);
    }
    pressed_AI = 2;
    if (pressed_AI == 2 || pressed_AI == 3)
    {
        std::time_t now = std::time(nullptr);
        if (now - time1 > 6)
            pressed_AI = 0;
        else if (now - time1 > 3)
        {
            Remove_breakable(_bomb_pos_AI);
            _score.update_AI();
            pressed_AI = 3;
        }
    }
}

void Bomberman::Core::Draw3d()
{
    BeginMode3D(_camera.get_Camera());
    DrawModelEx(_ai.get_Model(), _ai.get_pos(), (Vector3){0, 1, 0}, _ai.get_rotate(), (Vector3){1, 1, 1}, WHITE);
    DrawModelEx(_player.get_Model(), _player.get_pos(1), (Vector3){0, 1, 0}, _player.get_rotate1(), (Vector3){1, 1, 1}, WHITE);
    DrawModelEx(_player.get_Model2(), _player.get_pos(2), (Vector3){0, 1, 0}, _player.get_rotate2(), (Vector3){1, 1, 1}, WHITE);
    Draw_breakabke();
    set_Bomb_AI();
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && pressed < 1) {
        _bomb_pos = _player.get_pos(1);
        printf("%2.f, %2.f\n", _bomb_pos.x, _bomb_pos.z);
        pressed = 1;
        this->time1 = std::time(nullptr);
    }
    if (pressed > 0 && pressed < 3) {
        DrawSphere(Vector3{_bomb_pos}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos}, 0.3, 10, 10, BROWN);
    }
    if (IsKeyReleased(KEY_RIGHT_SHIFT)) {
        pressed = 2;
    }
    if (pressed == 2 || pressed == 3) {
        std::time_t now = std::time(nullptr);
        if (now - time1 > 6)
            pressed = 0;
        else if (now - time1 > 3) {
            Remove_breakable(_bomb_pos);
            _score.update1();
            pressed = 3;
        }
    }

    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT)) && pressed2 < 1)
    {
        _bomb_pos2 = _player.get_pos(2);
        pressed2 = 1;
        this->time2 = std::time(nullptr);
    }
    if (pressed2 > 0 && pressed2 < 3) {
        DrawSphere(Vector3{_bomb_pos2}, 0.3, BLACK);
        DrawSphereWires(Vector3{_bomb_pos2}, 0.3, 10, 10, BROWN);
    }
    if (IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyReleased(KEY_LEFT_SHIFT)) {
        pressed2 = 2;
    }
    if (pressed2 == 2 || pressed2 == 3) {
        std::time_t now2 = std::time(nullptr);
        if (now2 - time2 > 6)
            pressed2 = 0;
        else if (now2 - time2 > 3) {
            Remove_breakable(_bomb_pos2);
            _score.update2();
            pressed2 = 3;
        }
    }
    EndMode3D();
}

Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
