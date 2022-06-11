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
    _texture = LoadTexture("Png/meme_player.png");
    _texture2 = LoadTexture("Png/meme_player.png");

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
    if (fabs(tmpz) - (float) abs(tmpz) < 0.3)
        y = abs(tmpz);
    if (fabs(tmpx) - (float) abs(tmpx) < 0.2)
        x = abs(tmpx);
 //   printf("x = %d, z =%d, posx = %.3f, posz = %.3f\n", x, y, newPos.x, newPos.z);
    if ((mapPixels[y*_cubicTexture.width + x].r == 255) || (mapPixels[prey*_cubicTexture.width + prex].r == 255)) {
   //     printf("collision: %.3f, %.3f\n", pos.x, pos.z);
        return (true);
    }
    return false;
}

float Bomberman::Player::Player_animation(Color *mapPixels, Texture2D _cubicTexture)
{
    if (IsKeyDown(KEY_UP) && !Check_collision(_pos1, 2, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.z -= 0.05;
        rotation = 180;
    }
    if (IsKeyDown(KEY_DOWN) && !Check_collision(_pos1, 1, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.z += 0.05;
        rotation = 0;
    }
    if (IsKeyDown(KEY_LEFT) && !Check_collision(_pos1, 3, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.x -= 0.05;
        rotation = -90;
    }
    if (IsKeyDown(KEY_RIGHT) && !Check_collision(_pos1, 4, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model, _anim[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim[0].frameCount)
           _animFrameCounter = 0;
        _pos1.x += 0.05;
        rotation = 90;
    }
    return rotation;
}


float Bomberman::Player::Player_move(Color *mapPixels, Texture2D _cubicTexture)
{
    if (/*IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) || */IsKeyDown(KEY_W) && !Check_collision(_pos2, 2, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.z -= 0.05;
        rotation2 = 180;
    }
    if (/*IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) || */IsKeyDown(KEY_S) && !Check_collision(_pos2, 1, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.z += 0.05;
        rotation2 = 0;
    }
    if (/*IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) || */IsKeyDown(KEY_A) && !Check_collision(_pos2, 3, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.x -= 0.05;
        rotation2 = -90;
    }
    if (/*IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) || */IsKeyDown(KEY_D) && !Check_collision(_pos2, 4, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_model2, _anim2[0],_animFrameCounter);
       _animFrameCounter++;
        if (_animFrameCounter >= _anim2[0].frameCount)
           _animFrameCounter = 0;
        _pos2.x += 0.05;
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

Vector3 Bomberman::Player::get_pos(int player)
{
    if (player == 1)
        return _pos1;
    else
        return _pos2;
}
