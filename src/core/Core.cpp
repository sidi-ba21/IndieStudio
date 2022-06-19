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
        _time.reset();
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

void Bomberman::Core::Draw_speed_up()
{
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){-13, 0.1, -4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){-14, 0.1, 4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){14, 0.1, 4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){13, 0.1, -5}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){-9, 0.1, -3}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){-7, 0.1, 3}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){5, 0.1, -7}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_up_texture(), (Vector3){10, 0.1, 2}, 0.80f, 0.1f, 0.80f, WHITE);
}

void Bomberman::Core::Draw_speed_down()
{
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){-12, 0.1, -1}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){-11, 0.1, 5}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){6, 0.1, -1}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){12, 0.1, -7}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){-5, 0.1, -7}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){-4, 0.1, 0}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){2, 0.1, -4}, 0.80f, 0.1f, 0.80f, WHITE);
    DrawCubeTexture(_box.get_speed_down_texture(), (Vector3){0, 0.1, 6}, 0.80f, 0.1f, 0.80f, WHITE);
}

void Bomberman::Core::Draw2d()
{
    DrawFPS(10, 1060);
    _map.draw(screenWidth);
    _score.draw_face();
    Draw_text();
    score();
}

void Bomberman::Core::set_bomb()
{
    _bomb[0].pose_bomb(_ai.get_pos());
    if (IsKeyPressed(KEY_RIGHT_SHIFT))
        _bomb[1].pose_bomb(_player.get_pos(1));
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT)))
        _bomb[2].pose_bomb(_player.get_pos(2));

    for (std::size_t i = 0; i < _bomb.size(); i++)
    {
        _bomb[i].wait_bomb();
        _bomb[i].explosion(_box, _map, _score, i);
    }
}

void Bomberman::Core::Draw3d()
{
    BeginMode3D(_camera.get_Camera());

    _ai.draw();
    _player.draw();
    _box.draw_breakable(_map);
    Draw_speed_up();
    Draw_speed_down();
    set_bomb();
    EndMode3D();
}

Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
