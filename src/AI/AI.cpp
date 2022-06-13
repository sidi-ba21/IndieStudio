/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Ai
*/

#include "AI.hpp"
#include <memory>
#include <list>

void Bomberman::AI::init_AI()
{
    _Model_AI = LoadModel("assets/robo6.iqm");
    _Anim_AI = LoadModelAnimations("assets/robo6.iqm", &_animCount_AI);
    _texture_AI = LoadTexture("Png/meme_player.png");
    SetMaterialTexture(&_Model_AI.materials[0], MATERIAL_MAP_DIFFUSE, _texture_AI);
}

Bomberman::AI::~AI()
{
    UnloadModel(_Model_AI);
    UnloadTexture(_texture_AI);
    for (unsigned int i = 0; i < _animCount_AI; i++){
        UnloadModelAnimation(_Anim_AI[i]);
    }
    RL_FREE(_Anim_AI);
}

float Bomberman::AI::move_AI()
{
    auto now = std::time(nullptr);

    if (now - _time > 6) {
        printf("reset\n");
        _check = GetRandomValue(0, 3);
        _time = std::time(nullptr);
    }

    if (_check == 0 && (now - _time) <= GetRandomValue(2, 6)) {
        printf("ok1\n");
        UpdateModelAnimation(_Model_AI, _Anim_AI[0], _AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
            _AnimFrameCounter_AI = 0;
        _Pos_AI.z -= 0.05;
        Rotation_AI = 180;
        setPos(_Pos_AI);
    }

    if (_check == 1 && (now - _time) <= GetRandomValue(2, 6)) {
        printf("ok2\n");
        UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
           _AnimFrameCounter_AI = 0;
        _Pos_AI.z += 0.05;
        Rotation_AI = 0;
    }

    if (_check == 2 && (now - _time) <= GetRandomValue(2, 6)) {
        printf("ok3\n");
        UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
           _AnimFrameCounter_AI = 0;
        _Pos_AI.x -= 0.05;
        Rotation_AI = -90;
    }

    if (_check == 3 && (now - _time) <= GetRandomValue(2, 6)) {
        printf("ok4\n");
        UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
           _AnimFrameCounter_AI = 0;
        _Pos_AI.x += 0.05;
        Rotation_AI = 90;
    }
    return (Rotation_AI);
}