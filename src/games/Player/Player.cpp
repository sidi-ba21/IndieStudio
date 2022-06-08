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
    _texture = LoadTexture("assets/cubex.png");
    _texture2 = LoadTexture("assets/stone_cube.png");

    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
    SetMaterialTexture(&_model2.materials[0], MATERIAL_MAP_DIFFUSE, _texture2);
}

Bomberman::Player::~Player()
{
    UnloadModel(_model);
    UnloadTexture(_texture);
    UnloadModel(_model2);
    UnloadTexture(_texture2);
    for (unsigned int i = 0; i < _animCount; i++){
        UnloadModelAnimation(_anim[i]);
        UnloadModelAnimation(_anim2[i]);
    }
    RL_FREE(_anim);   
}

float Bomberman::Player::Player_animation()
{
    if (IsKeyDown(KEY_UP)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.z -= 0.09;
        rotation = 180;
    }
    if (IsKeyDown(KEY_DOWN)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.z += 0.09;
        rotation = 0;
    }
    if (IsKeyDown(KEY_LEFT)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.x -= 0.09;
        rotation = -90;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.x += 0.09;
        rotation = 90;
    }
    return rotation;
}

float Bomberman::Player::Player_move()
{
    if (IsKeyDown(KEY_W)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.z -= 0.09;
        rotation2 = 180;
    }
    if (IsKeyDown(KEY_S)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.z += 0.09;
        rotation2 = 0;
    }
    if (IsKeyDown(KEY_Q)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.x -= 0.09;
        rotation2 = -90;
    }
    if (IsKeyDown(KEY_E)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.x += 0.09;
        rotation2 = 90;
    }
    return rotation2;
}

Model Bomberman::Player::get_Model()
{
    return _model;
}

Model Bomberman::Player::get_Model2()
{
    return _model2;
}

Vector3 Bomberman::Player::get_position(int player)
{
    if (player == 1)
        return _pos1;
    else
        return _pos2;
}
