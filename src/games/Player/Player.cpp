/*
** EPITECH PROJECT, 2022
** Player
** File description:
** Player
*/

#include "Player.hpp"

//Bomberman::Player::Player()
//{
//}

void Bomberman::Player::init()
{
    _model = LoadModel("assets/robo6.iqm");
    _anim = LoadModelAnimations("assets/robo6.iqm", &_animCount);
    _texture = LoadTexture("assets/txr.png");

    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}

Bomberman::Player::~Player()
{
    UnloadModel(_model);
    UnloadTexture(_texture);
    for (unsigned int i = 0; i < _animCount; i++)
       UnloadModelAnimation(_anim[i]);
    RL_FREE(_anim);   
}

void Bomberman::Player::Player_animation()
{
    if (IsKeyDown(KEY_SPACE)) {
        UpdateModelAnimation(_model, _anim[1], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim[1].frameCount)
            _animFrameCounter = 0;
    }
    if (IsKeyDown(KEY_UP)) {
        UpdateModelAnimation(_model, _anim[0], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
            _animFrameCounter = 0;
    }
    if (IsKeyDown(KEY_DOWN)) {
        UpdateModelAnimation(_model, _anim[2], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim[2].frameCount)
            _animFrameCounter = 0;
    }
}

void Bomberman::Player::Player_move()
{
    if (IsKeyDown(KEY_Q))
        _pos1.x += 0.2;
    if (IsKeyDown(KEY_E))
        _pos1.x -= 0.2;
    if (IsKeyDown(KEY_W))
        _pos1.z += 0.2;
    if (IsKeyDown(KEY_S))
        _pos1.z -= 0.2;

    if (IsKeyDown(KEY_LEFT))
        _pos2.x += 0.2;
    if (IsKeyDown(KEY_RIGHT))
        _pos2.x -= 0.2;
    if (IsKeyDown(KEY_UP))
        _pos2.z += 0.2;
    if (IsKeyDown(KEY_DOWN))
        _pos2.z -= 0.2;
}

Model Bomberman::Player::get_Model()
{
    return _model;
}

Vector3 Bomberman::Player::get_pos(int player)
{
    if (player == 1)
        return _pos1;
    else
        return _pos2;
}
