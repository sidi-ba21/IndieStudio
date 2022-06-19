/*
** EPITECH PROJECT, 2022
** Score
** File description:
** Score
*/

#include "Score.hpp"

void Bomberman::Score::init()
{   
    _player_face1 = LoadTexture("Png/player_face1.png");
    _player_face2  = LoadTexture("Png/player_face2.png");
    _player_face_AI  = LoadTexture("Png/player_face_AI.png");  
}

void Bomberman::Score::update(int n)
{
    if (n == 0)
        _score_AI += 1;
    if (n == 1)
        _score1 += 1;
    if (n == 2)
        _score2 += 1;
}

int Bomberman::Score::get_score1()
{
    return _score1;
}

int Bomberman::Score::get_score2()
{
    return _score2;
}

int Bomberman::Score::get_score_AI()
{
    return _score_AI;
}

Texture2D Bomberman::Score::score_player_face1()
{
    return _player_face1;
}

Texture2D Bomberman::Score::score_player_face_AI()
{
    return _player_face_AI;
}

Texture2D Bomberman::Score::score_player_face_2()
{
    return _player_face2;
}

void Bomberman::Score::draw_face()
{
    DrawTexture(_player_face1, 20.0f, 20.0f, WHITE);
    DrawTexture(_player_face2, 30.0f, 20.0f, WHITE);
    DrawTexture(_player_face_AI, 40.0f, 20.0f, WHITE);
}
Bomberman::Score::~Score()
{
    UnloadTexture(_player_face1);
    UnloadTexture(_player_face2);
    UnloadTexture(_player_face_AI);
}