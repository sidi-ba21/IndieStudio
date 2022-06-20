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
    _texture_AI = LoadTexture("Png/girl.png");
    SetMaterialTexture(&_Model_AI.materials[0], MATERIAL_MAP_DIFFUSE, _texture_AI);
    _life = 100;
    _Rotate_AI = 0;
    _Pos_AI = Vector3{-15, 0.1, 6};
    _time = std::time(nullptr);
    del = 1;
}

Bomberman::AI::~AI()
{
    if (!del) {
        UnloadModel(_Model_AI);
        UnloadTexture(_texture_AI);
        for (unsigned int i = 0; i < _animCount_AI; i++){
            UnloadModelAnimation(_Anim_AI[i]);
        }
        RL_FREE(_Anim_AI);
    }
}

bool Bomberman::AI::Check_collision_AI(Vector3 pos, int direction,
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
    if (COLOR_EQUAL(mapPixels[y*_cubicTexture.width + x], WHITE) || COLOR_EQUAL(mapPixels[prey*_cubicTexture.width + prex], WHITE)
    || COLOR_EQUAL(mapPixels[y*_cubicTexture.width + x], RED) || COLOR_EQUAL(mapPixels[prey*_cubicTexture.width + prex], RED)) {
        return (true);
    }
    return false;
}

void Bomberman::AI::move_AI(Color *mapPixels, Texture2D _cubicTexture)
{
    auto now = std::time(nullptr);
    if (now - _time > 3) {
        _check = GetRandomValue(0, 3);
        _time = std::time(nullptr);
    }
    if (_check == 0 && (now - _time) <= GetRandomValue(0, 2) && !Check_collision_AI(_Pos_AI, 2, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_Model_AI, _Anim_AI[0], _AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
            _AnimFrameCounter_AI = 0;
        _Pos_AI.z -= 0.05;
        _Rotate_AI = 180;
        setPos(_Pos_AI);
    }

    if (_check == 1 && (now - _time) <= GetRandomValue(0, 2) && !Check_collision_AI(_Pos_AI, 1, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
           _AnimFrameCounter_AI = 0;
        _Pos_AI.z += 0.05;
        _Rotate_AI = 0;
    }

    if (_check == 2 && (now - _time) <= GetRandomValue(0, 2) && !Check_collision_AI(_Pos_AI, 3, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
           _AnimFrameCounter_AI = 0;
        _Pos_AI.x -= 0.05;
        _Rotate_AI = -90;
    }

    if (_check == 3 && (now - _time) <= GetRandomValue(0, 2) && !Check_collision_AI(_Pos_AI, 4, mapPixels, _cubicTexture)) {
        UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
        _AnimFrameCounter_AI++;
        if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
           _AnimFrameCounter_AI = 0;
        _Pos_AI.x += 0.05;
        _Rotate_AI = 90;
    }
}

void Bomberman::AI::draw()
{
    if (_life > 0)
        DrawModelEx(get_Model(), get_pos(), (Vector3){0, 1, 0}, get_rotate(), (Vector3){1, 1, 1}, WHITE);
}