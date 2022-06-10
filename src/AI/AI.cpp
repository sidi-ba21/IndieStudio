/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Ai
*/

#include "AI.hpp"
#include <memory>
#include <list>

Bomberman::AI::AI()
{
    _Pos2 = get_pos(2);
    _Model2 = get_Model2();
    _Anim2 = get_anim2();
    _AnimFrameCounter = get_anifram();
}

float Bomberman::AI::move_AI()
{
    //_time = ;
    UpdateModelAnimation(_Model2, _Anim2[0], _AnimFrameCounter);
    _AnimFrameCounter++;
    if (_AnimFrameCounter >= _Anim2[0].frameCount)
        _AnimFrameCounter = 0;
    _Pos2.z -= 20;
    Rotation2 = 180;
    setPos(_Pos2);

    /*UpdateModelAnimation(_Model2, _Anim2[0],_AnimFrameCounter);
    _AnimFrameCounter++;
    if (_AnimFrameCounter >= _Anim2[0].frameCount)
       _AnimFrameCounter = 0;
    _Pos2.z += 0.05;
    Rotation2 = 0;

    UpdateModelAnimation(_Model2, _Anim2[0],_AnimFrameCounter);
    _AnimFrameCounter++;
    if (_AnimFrameCounter >= _Anim2[0].frameCount)
       _AnimFrameCounter = 0;
    _Pos2.x -= 0.05;
    Rotation2 = -90;

    UpdateModelAnimation(_Model2, _Anim2[0],_AnimFrameCounter);
   _AnimFrameCounter++;
    if (_AnimFrameCounter >= _Anim2[0].frameCount)
       _AnimFrameCounter = 0;
    _Pos2.x += 0.05;
    Rotation2 = 90;

    return Rotation2;*/
}