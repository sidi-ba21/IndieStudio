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
    _draw.initWindow();
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
}

void Bomberman::Core::game_loop()
{
    while (_draw.game_loop())
    {
        if (_menu.get_pause() == false)
        {
            if (_ai.get_life() > 0)
                _ai.move_AI(_map.get_color(), _map.get_texture());
            if (_player.get_life() > 0) {
                _player.Player_move1(_map.get_color(), _map.get_texture());
                _Buff.Power_up1(_player);
                _Buff.Power_down1(_player);
            }
            if (_player.get_life(2) > 0) {
                _player.Player_move2(_map.get_color(), _map.get_texture());
                _Buff.Power_up2(_player);
                _Buff.Power_down2(_player);
            }
            _map.update();
            _camera.Camera_move();
            if ((_player.get_life() <= 0) && (_player.get_life(2) <= 0)){
                _menu.set_id(0);
                _menu.set_score(_score.get_score_AI());
                _menu.set_finish(true);
                _menu.set_gamebool(false);
            } else if ((_player.get_life(2) <= 0) && (_ai.get_life() <= 0)) {
                _menu.set_id(1);
                _menu.set_score(_score.get_score1());
                _menu.set_finish(true);
                _menu.set_gamebool(false);
            } else if ((_player.get_life() <= 0) && (_ai.get_life() <= 0)) {
                _menu.set_id(2);
                _menu.set_score(_score.get_score2());
                _menu.set_finish(true);
                _menu.set_gamebool(false);
            }
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

    _background.draw_background();
    ClearBackground(RAYWHITE);
    if (_menu.get_game() == true)
    {
        if (_menu.get_pause() == true)
            _menu.pause();
        else {
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
    DrawText(TextFormat("SCORE       : %u", _score.get_score1()), 15, 120, 30, MAGENTA);
    DrawText(TextFormat("SCORE       : %u", _score.get_score2()), 15, 220, 30, MAGENTA);
    DrawText(TextFormat("SCORE       : %u", _score.get_score_AI()), 15, 320, 30, MAGENTA);
    DrawText(TextFormat("HI-SCORE: %s", _score.getHightScore().c_str()), 15, 20, 40, RED);
    auto tmp = GetTime();
    auto minutes = (float)(int)(tmp / 60);
    auto seconds = (float)((int)tmp % 60);

    DrawText(TextFormat("Elapsed Time: %02.0f : %02.0f", minutes, seconds), 800, 100, 40, MAGENTA);
    if (_player.get_life() > 0)
        DrawText(TextFormat("LIFE       : %u / 100", _player.get_life()), 1600, 120, 30, MAGENTA);
    else if (_player.get_life() <= 0){
        DrawText(TextFormat("LIFE       : "), 1600, 120, 30, MAGENTA);
        DrawText(TextFormat("DEAD"), 1790, 120, 30, RED);
    }
    if (_player.get_life(2) > 0)
        DrawText(TextFormat("LIFE       : %u / 100", _player.get_life(2)), 1600, 220, 30, MAGENTA);
    else if (_player.get_life(2) <= 0) {
        DrawText(TextFormat("LIFE       : "), 1600, 220, 30, MAGENTA);
        DrawText(TextFormat("DEAD"), 1790, 220, 30, RED);
    }
    if (_ai.get_life() > 0)
        DrawText(TextFormat("LIFE       : %u / 100", _ai.get_life()), 1600, 320, 30, MAGENTA);
    else if (_ai.get_life() <= 0) {
        DrawText(TextFormat("LIFE       : "), 1600, 320, 30, MAGENTA);
        DrawText(TextFormat("DEAD"), 1790, 320, 30, RED);
    }
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
    _map.draw();
    _player.draw_face();
    Draw_text();
    score();
}

void Bomberman::Core::set_bomb()
{
    if (_ai.get_life() > 0)
        _bomb[0].pose_bomb(_ai.get_pos().x, _ai.get_pos().y, _ai.get_pos().z);
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && _player.get_life() > 0)
        _bomb[1].pose_bomb(_player.get_pos(1).x, _player.get_pos(1).y, _player.get_pos(1).z);
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT))
    && _player.get_life(2) > 0)
        _bomb[2].pose_bomb(_player.get_pos(2).x, _player.get_pos(2).y, _player.get_pos(2).z);

    for (std::size_t i = 0; i < _bomb.size(); i++) {
        _bomb[i].wait_bomb();
        _bomb[i].explosion(_box, _map, _score, i, _ai, _player);
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
    _draw.closeWindow();
}