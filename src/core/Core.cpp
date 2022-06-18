/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "Core.hpp"
#include <unistd.h>
#include <chrono>

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
    while (!WindowShouldClose())
    {
        if (_menu.get_pause() == false)
        {
            _ai.move_AI(_map.get_color(), _map.get_cubicTexture());
            _player.Player_move1(_map.get_color(), _map.get_cubicTexture());
            _player.Player_move2(_map.get_color(), _map.get_cubicTexture());
            _map.update();
            _camera.Camera_move();
        }
        Draw();
        _menu.update();
        _time.elapsed();
    }
}

void Bomberman::Core::Draw()
{
    BeginDrawing();

    _background.draw();
    ClearBackground(RAYWHITE);
    if (_menu.get_game() == true)
    {
        if (_menu.get_pause() == true)
            _menu.pause();
        else
        {
            Draw2d();
            Draw3d();
        }
    }
    else
        _menu.loop();
    EndDrawing();
}

void Bomberman::Core::score()
{
    _score.writeScore(std::to_string(_score.get_score1()));
    _score.writeScore(std::to_string(_score.get_score2()));
    _score.writeScore(std::to_string(_score.get_score_AI()));
}

void Bomberman::Core::Draw_text()
{
    DrawText("The map generated is : ", 1410, 20, 30, MAGENTA);
    DrawText(TextFormat("SCORE PLAYER1: %i", _score.get_score1()), 15, 80, 30, MAGENTA);
    DrawText(TextFormat("SCORE PLAYER2: %i", _score.get_score2()), 15, 120, 30, MAGENTA);
    DrawText(TextFormat("SCORE AI: %i", _score.get_score_AI()), 15, 160, 30, MAGENTA);
    DrawText(TextFormat("HI-SCORE: %s", _score.getHightScore().c_str()), 15, 20, 40, RED);
    auto tmp = GetTime();
    auto minutes = (float)(int)tmp / 60;
    auto seconds = (float)((int)tmp % 60);
    DrawText(TextFormat("Elapsed Time: %02.0f : %02.0f", minutes, seconds), 800, 100, 40, MAGENTA);
}

void Bomberman::Core::Draw_map()
{
    DrawTextureEx(_map.get_cubicTexture(), (Vector2){screenWidth - _map.get_cubicTexture().width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(screenWidth - _map.get_cubicTexture().width * 4 - 20, 20, _map.get_cubicTexture().width * 4, _map.get_cubicTexture().height * 4, GREEN);
}

void Bomberman::Core::Draw2d()
{
    DrawFPS(10, 1060);
    // std::cout << "bomb == " << _bomb.getTime() << std::endl;
    Draw_map();
    Draw_text();
    score();
}

void Bomberman::Core::set_Bomb_AI()
{
    if (pressed_AI)
        _time_bomb += _time.getTime();
    if (!pressed_AI)
    {
        _bomb_pos_AI = _ai.get_pos();
        pressed_AI = 1;
    }
    if (_time_bomb > 0 && _time_bomb < 3)
        Draw_bomb(_bomb_pos_AI);
    if (_time_bomb > 3 && _time_bomb < 3.5)
    {
        _box.remove_breakable(_map, _bomb_pos_AI);
        _score.update_AI();
    }
    if (_time_bomb > 6)
    {
        pressed_AI = 0;
        _time_bomb = 0;
    }
}

void Bomberman::Core::set_bomb_player()
{
    // Player 1
    if (pressed)
        _time_bomb2 += _time.getTime();
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && !pressed)
    {
        _bomb_pos = _player.get_pos(1);
        pressed = 1;
    }
    if (_time_bomb2 > 0 && _time_bomb2 < 3)
        Draw_bomb(_bomb_pos);
    if (_time_bomb2 > 3 && _time_bomb2 < 3.5)
    {
        _box.remove_breakable(_map, _bomb_pos);
        _score.update1();
    }
    if (_time_bomb2 > 6)
    {
        pressed = 0;
        _time_bomb2 = 0;
    }

    // Player 2
    if (pressed2)
        _time_bomb3 += _time.getTime();
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT)) && !pressed2)
    {
        _bomb_pos2 = _player.get_pos(2);
        pressed2 = 1;
    }
    if (_time_bomb3 > 0 && _time_bomb3 < 3)
        Draw_bomb(_bomb_pos2);
    if (_time_bomb3 > 3 && _time_bomb3 < 3.5)
    {
        _box.remove_breakable(_map, _bomb_pos2);
        _score.update2();
    }
    if (_time_bomb3 > 6)
    {
        _time_bomb3 = 0;
        pressed2 = 0;
    }
}

void Bomberman::Core::Draw_ai()
{
    DrawModelEx(_ai.get_Model(), _ai.get_pos(), (Vector3){0, 1, 0}, _ai.get_rotate(), (Vector3){1, 1, 1}, WHITE);
}

void Bomberman::Core::Draw_bomb(Vector3 centerPos)
{
    DrawSphere(centerPos, 0.3, BLACK);
    DrawSphereWires(centerPos, 0.3, 10, 10, BROWN);
}

void Bomberman::Core::Draw_player()
{
    DrawModelEx(_player.get_Model(), _player.get_pos(1), (Vector3){0, 1, 0}, _player.get_rotate1(), (Vector3){1, 1, 1}, WHITE);
    DrawModelEx(_player.get_Model2(), _player.get_pos(2), (Vector3){0, 1, 0}, _player.get_rotate2(), (Vector3){1, 1, 1}, WHITE);
}

void Bomberman::Core::Draw3d()
{
    BeginMode3D(_camera.get_Camera());

    Draw_ai();
    Draw_player();
    _box.draw_breakable(_map);
    set_Bomb_AI();
    set_bomb_player();
    EndMode3D();
}

Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
