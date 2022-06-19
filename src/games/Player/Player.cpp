/*
** EPITECH PROJECT, 2022
** Player
** File description:
** Player
*/

#include "Player.hpp"

void Bomberman::Player::init()
{
    _model = LoadModel("assets/robo6.iqm");
    _model2 = LoadModel("assets/robo6.iqm");
    _anim = LoadModelAnimations("assets/robo6.iqm", &_animCount);
    _anim2 = LoadModelAnimations("assets/robo6.iqm", &_animCount);
    _texture = LoadTexture("Png/zombie.png");
    _texture2 = LoadTexture("Png/meme_player.png");
    _player_face1 = LoadTexture("Png/player_face1.png");
    _player_face2 = LoadTexture("Png/player_face2.png");
    _player_face_AI = LoadTexture("Png/player_face_AI.png");

    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
    SetMaterialTexture(&_model2.materials[0], MATERIAL_MAP_DIFFUSE, _texture2);
    del = 1;
}

Bomberman::Player::~Player()
{
    if (!del) {
        UnloadModel(_model);
        UnloadTexture(_texture);
        UnloadModel(_model2);
        UnloadTexture(_texture2);
        UnloadTexture(_player_face1);
        UnloadTexture(_player_face2);
        UnloadTexture(_player_face_AI);
        for (unsigned int i = 0; i < _animCount; i++)
        {
            UnloadModelAnimation(_anim[i]);
            UnloadModelAnimation(_anim2[i]);
        }
        RL_FREE(_anim);
    }
}

void Bomberman::Player::Power_up1()
{
    if (_pos1.x > -14 && _pos1.x < -12 && _pos1.z > -5 && _pos1.z < -3)
        spd1 = spd1 + 0.01;
    if (_pos1.x > -15 && _pos1.x < -13 && _pos1.z > 3 && _pos1.z < 5)
        spd1 = spd1 + 0.01;
    if (_pos1.x > 13 && _pos1.x < 15 && _pos1.z > 3 && _pos1.z < 5)
        spd1 = spd1 + 0.01;
    if (_pos1.x > 12 && _pos1.x < 14 && _pos1.z > -6 && _pos1.z < -4)
        spd1 = spd1 + 0.01;
    if (_pos1.x > -10 && _pos1.x < -8 && _pos1.z > -4 && _pos1.z < -2)
        spd1 = spd1 + 0.01;
    if (_pos1.x > -8 && _pos1.x < -6 && _pos1.z > 4 && _pos1.z < 6)
        spd1 = spd1 + 0.01;
    if (_pos1.x > 4 && _pos1.x < 6 && _pos1.z > -8 && _pos1.z < -6)
        spd1 = spd1 + 0.01;
    if (_pos1.x > 9 && _pos1.x < 11 && _pos1.z > 1 && _pos1.z < 3)
        spd1 = spd1 + 0.01;
    if (spd1 > 0.1)
        spd1 = 0.1;
}

void Bomberman::Player::Power_up2()
{
    if (_pos2.x > -14 && _pos2.x < -12 && _pos2.z > -5 && _pos2.z < -3) 
        spd2 = spd2 + 0.01;
    if (_pos2.x > -15 && _pos2.x < -13 && _pos2.z > 3 && _pos2.z < 5)
        spd2 = spd2 + 0.01;
    if (_pos2.x > 13 && _pos2.x < 15 && _pos2.z > 3 && _pos2.z < 5)
        spd2 = spd2 + 0.01;
    if (_pos2.x > 12 && _pos2.x < 14 && _pos2.z > -6 && _pos2.z < -4)
        spd2 = spd2 + 0.01;
    if (_pos2.x > -10 && _pos2.x < -8 && _pos2.z > -4 && _pos2.z < -2)
        spd2 = spd2 + 0.01;
    if (_pos2.x > -8 && _pos2.x < -6 && _pos2.z > 4 && _pos2.z < 6)
        spd2 = spd2 + 0.01;
    if (_pos2.x > 4 && _pos2.x < 6 && _pos2.z > -8 && _pos2.z < -6)
        spd2 = spd2 + 0.01;
    if (_pos2.x > 9 && _pos2.x < 11 && _pos2.z > 1 && _pos2.z < 3)
        spd2 = spd2 + 0.01;
    if (spd2 > 0.1)
        spd2 = 0.1;
}

void Bomberman::Player::Power_down1()
{
    if (_pos1.x > -13 && _pos1.x < -11 && _pos1.z > -2 && _pos1.z < 0)
        spd1 = spd1 - 0.01;
    if (_pos1.x > -12 && _pos1.x < -10 && _pos1.z > 4 && _pos1.z < 6)
        spd1 = spd1 - 0.01;
    if (_pos1.x > 5 && _pos1.x < 7 && _pos1.z > -2 && _pos1.z < 0)
        spd1 = spd1 - 0.01;
    if (_pos1.x > 11 && _pos1.x < 13 && _pos1.z > -8 && _pos1.z < -6)
        spd1 = spd1 - 0.01;
    if (_pos1.x > -6 && _pos1.x < -4 && _pos1.z > -8 && _pos1.z < -6)
        spd1 = spd1 - 0.01;
    if (_pos1.x > -5 && _pos1.x < -3 && _pos1.z > -1 && _pos1.z < 1)
        spd1 = spd1 - 0.01;
    if (_pos1.x > 1 && _pos1.x < 3 && _pos1.z > -5 && _pos1.z < -3)
        spd1 = spd1 - 0.01;
    if (_pos1.x > -1 && _pos1.x < 1 && _pos1.z > 5 && _pos1.z < 7)
        spd1 = spd1 - 0.01;
    if (spd1 < 0.02)
        spd1 = 0.02;
}

void Bomberman::Player::Power_down2()
{
    if (_pos2.x > -13 && _pos2.x < -11 && _pos2.z > -2 && _pos2.z < 0)
        spd2 = spd2 - 0.01;
    if (_pos2.x > -12 && _pos2.x < -10 && _pos2.z > 4 && _pos2.z < 6)
        spd2 = spd2 - 0.01;
    if (_pos2.x > 5 && _pos2.x < 7 && _pos2.z > -2 && _pos2.z < 0)
        spd2 = spd2 - 0.01;
    if (_pos2.x > 11 && _pos2.x < 13 && _pos2.z > -8 && _pos2.z < -6)
        spd2 = spd2 - 0.01;
    if (_pos2.x > -6 && _pos2.x < -4 && _pos2.z > -8 && _pos2.z < -6)
        spd2 = spd2 - 0.01;
    if (_pos2.x > -5 && _pos2.x < -3 && _pos2.z > -1 && _pos2.z < 1)
        spd2 = spd2 - 0.01;
    if (_pos2.x > 1 && _pos2.x < 3 && _pos2.z > -5 && _pos2.z < -3)
        spd2 = spd2 - 0.01;
    if (_pos2.x > -1 && _pos2.x < 1 && _pos2.z > 5 && _pos2.z < 7)
        spd2 = spd2 - 0.01;
    if (spd2 < 0.02)
        spd2 = 0.02;
}

bool Bomberman::Player::Check_collision(Vector3 pos, int direction,
                                        Color *mapPixels, Texture2D _cubicTexture)
{
    Vector3 newPos = pos;

    if (direction == 1)
        newPos.z += 0.05;
    else if (direction == 2)
        newPos.z -= 0.05;
    else if (direction == 3)
        newPos.x -= 0.05;
    else if (direction == 4)
        newPos.x += 0.05;
    if (newPos.x < -15 || newPos.z < -7 || newPos.x > 14 || newPos.z > 6)
        return (true);
    float tmpz = newPos.z + 8.f;
    float tmpx = newPos.x + 16.f;
    auto x = abs(tmpx + 0.6);
    auto y = abs(tmpz + 0.4);
    auto prex = abs(tmpx);
    auto prey = abs(tmpz + 0.4);
    if (fabs(tmpz) - (float)abs(tmpz) < 0.3)
        y = abs(tmpz);
    if (fabs(tmpx) - (float)abs(tmpx) < 0.2)
        x = abs(tmpx);
    if (COLOR_EQUAL(mapPixels[y * _cubicTexture.width + x], WHITE) || COLOR_EQUAL(mapPixels[prey * _cubicTexture.width + prex], WHITE) || COLOR_EQUAL(mapPixels[y * _cubicTexture.width + x], RED) || COLOR_EQUAL(mapPixels[prey * _cubicTexture.width + prex], RED))
    {
        return (true);
    }
    return false;
}

void Bomberman::Player::Player_move1(Color *mapPixels, Texture2D _cubicTexture)
{
    Power_up1();
    Power_down1();
    if (IsKeyDown(KEY_UP) && !Check_collision(_pos1, 2, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model, _anim[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
            _animFrameCounter = 0;
        _pos1.z -= spd1;
        _rotate1 = 180;
    }
    if (IsKeyDown(KEY_DOWN) && !Check_collision(_pos1, 1, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model, _anim[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
            _animFrameCounter = 0;
        _pos1.z += spd1;
        _rotate1 = 0;
    }
    if (IsKeyDown(KEY_LEFT) && !Check_collision(_pos1, 3, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model, _anim[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
            _animFrameCounter = 0;
        _pos1.x -= spd1;
        _rotate1 = -90;
    }
    if (IsKeyDown(KEY_RIGHT) && !Check_collision(_pos1, 4, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model, _anim[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
            _animFrameCounter = 0;
        _pos1.x += spd1;
        _rotate1 = 90;
    }
}

void Bomberman::Player::Player_move2(Color *mapPixels, Texture2D _cubicTexture)
{
    Power_up2();
    Power_down2();
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) || IsKeyDown(KEY_W)) && !Check_collision(_pos2, 2, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model2, _anim2[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
            _animFrameCounter = 0;
        _pos2.z -= spd2;
        _rotate2 = 180;
    }
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) || IsKeyDown(KEY_S)) && !Check_collision(_pos2, 1, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model2, _anim2[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
            _animFrameCounter = 0;
        _pos2.z += spd2;
        _rotate2 = 0;
    }
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) || IsKeyDown(KEY_A)) && !Check_collision(_pos2, 3, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model2, _anim2[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
            _animFrameCounter = 0;
        _pos2.x -= spd2;
        _rotate2 = -90;
    }
    if ((IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) || IsKeyDown(KEY_D)) && !Check_collision(_pos2, 4, mapPixels, _cubicTexture))
    {
        UpdateModelAnimation(_model2, _anim2[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
            _animFrameCounter = 0;
        _pos2.x += spd2;
        _rotate2 = 90;
    }
}

Texture2D Bomberman::Player::score_player_face1()
{
    return _player_face1;
}

Texture2D Bomberman::Player::score_player_face_AI()
{
    return _player_face_AI;
}

Texture2D Bomberman::Player::score_player_face_2()
{
    return _player_face2;
}

void Bomberman::Player::draw()
{
    if (this->get_life() > 0)
        DrawModelEx(get_Model(), get_pos(1), (Vector3){0, 1, 0}, get_rotate1(), (Vector3){1, 1, 1}, WHITE);
    if (this->get_life(2) > 0)
        DrawModelEx(get_Model2(), get_pos(2), (Vector3){0, 1, 0}, get_rotate2(), (Vector3){1, 1, 1}, WHITE);
}

void Bomberman::Player::draw_face()
{
    DrawTextureEx(_player_face1, (Vector2){130, 200}, 0, 0.9f, WHITE);
    DrawTextureEx(_player_face2, (Vector2){130, 100}, 0, 0.25f, WHITE);
    DrawTextureEx(_player_face_AI, (Vector2){130, 300}, 0, 0.25f, WHITE);
}

Model Bomberman::Player::get_Model()
{
    return _model;
}

Model Bomberman::Player::get_Model2()
{
    return _model2;
}

Vector3 Bomberman::Player::get_pos(int player)
{
    if (player == 1)
        return _pos1;
    else
        return _pos2;
}