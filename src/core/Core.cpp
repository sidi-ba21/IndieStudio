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

void Bomberman::Core::Draw_map()
{
    DrawTextureEx(_map.get_cubicTexture(), (Vector2){screenWidth - _map.get_cubicTexture().width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(screenWidth - _map.get_cubicTexture().width * 4 - 20, 20, _map.get_cubicTexture().width * 4, _map.get_cubicTexture().height * 4, GREEN);
}

void Bomberman::Core::Draw2d()
{
    DrawFPS(10, 1060);
    Draw_map();
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
    
    for (std::size_t i = 0; i < _bomb.size(); i++) {
        _bomb[i].wait_bomb();
        _bomb[i].explosion(_box, _map, _score, i);
    }
}

void Bomberman::Core::Draw_ai()
{
    DrawModelEx(_ai.get_Model(), _ai.get_pos(), (Vector3){0, 1, 0}, _ai.get_rotate(), (Vector3){1, 1, 1}, WHITE);
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
    set_bomb();
    EndMode3D();
}

Bomberman::Core::~Core()
{
    CloseWindow(); // Close window and OpenGL context
}
