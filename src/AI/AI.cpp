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
    
    _time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
    UpdateModelAnimation(_Model_AI, _Anim_AI[0], _AnimFrameCounter_AI);
    _AnimFrameCounter_AI++;
    if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
        _AnimFrameCounter_AI = 0;
    //_Pos_AI.z -= 0.05;
    //Rotation2 = 180;
    //setPos(_Pos_AI);

    UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
    _AnimFrameCounter_AI++;
    if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
       _AnimFrameCounter_AI = 0;
    //_Pos_AI.z += 0.05;
    //Rotation2 = 0;

    UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
    _AnimFrameCounter_AI++;
    if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
       _AnimFrameCounter_AI = 0;
   // _Pos_AI.x -= 0.05;
    //Rotation2 = -90;

    UpdateModelAnimation(_Model_AI, _Anim_AI[0],_AnimFrameCounter_AI);
   _AnimFrameCounter_AI++;
    if (_AnimFrameCounter_AI >= _Anim_AI[0].frameCount)
       _AnimFrameCounter_AI = 0;
    _Pos_AI.x += 0.05;
    //Rotation2 = 90;

    return (0);
}