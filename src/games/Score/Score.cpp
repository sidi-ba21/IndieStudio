/*
** EPITECH PROJECT, 2022
** Score
** File description:
** Score
*/

#include "Score.hpp"

void Bomberman::Score::init()
{
}

void Bomberman::Score::update()
{
    if (IsKeyPressed(KEY_SPACE)) {
        _score = GetRandomValue(1000, 2000);
        _highscore = GetRandomValue(2000, 4000);
    }
}

int Bomberman::Score::get_score()
{
    return _score;
}

int Bomberman::Score::get_highscore()
{
    return _highscore;
}