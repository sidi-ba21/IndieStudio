/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "Core.hpp"
#include <unistd.h>
#include <chrono>

static int compare_score(int a, int b, int c)
{
    if (a > b && a > c)
        return 1;
    if (b > a && b > c)
        return 2;
    if (c > a && c > b)
        return 0;
    return 0;
}

Bomberman::Core::Core()
{
    _draw.initWindow();
    init();
    Intro_game();
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
    _score.init();
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
        if (_menu.get_title() && _menu.get_already_clicked()) {
            _box.init();
            _score.init();
             _map.init();
            _player.init();
            _ai.init_AI();
            _menu.set_already_clicked(false);
        }
    }
}

void Bomberman::Core::Draw()
{
    BeginDrawing();

    _background.draw_background();
    ClearBackground(RAYWHITE);
    if (_menu.get_game() == true)
    {
        end_Game.elapsed();
        if (end_Game.getTime() > 360) {
            auto i = compare_score(_score.get_score1(), _score.get_score2(), _score.get_score_AI());
            _menu.set_id(i);
            i == 0 ? _menu.set_score(_score.get_score_AI()) : i == 1 ?
            _menu.set_score(_score.get_score1()) : _menu.set_score(_score.get_score2());
            _menu.set_finish(true);
            _menu.set_gamebool(false);
            end_Game.reset();
        }
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
    std::vector<int> score = {_score.get_score1(), _score.get_score2(), _score.get_score_AI()};
    std::vector<int> life = {_player.get_life(1), _player.get_life(2), _ai.get_life()};
    _draw.draw_score(score, _score.getHightScore(), end_Game.getTime());
    _draw.draw_text_player(life);

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
        _bomb[0].pose_bomb(_ai.get_pos().x, _ai.get_pos().y + 0.3, _ai.get_pos().z);
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && _player.get_life() > 0)
        _bomb[1].pose_bomb(_player.get_pos(1).x, _player.get_pos(1).y + 0.3, _player.get_pos(1).z);
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) || IsKeyPressed(KEY_LEFT_SHIFT))
    && _player.get_life(2) > 0)
        _bomb[2].pose_bomb(_player.get_pos(2).x, _player.get_pos(2).y + 0.3, _player.get_pos(2).z);

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
    _draw.draw_speed_up(_box.get_texture(SPEED_UP));
    _draw.draw_speed_down(_box.get_texture(SPEED_DOWN));
    set_bomb();
    EndMode3D();
}

Bomberman::Core::~Core()
{
    _draw.closeWindow();
}