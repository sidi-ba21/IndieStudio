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

void Bomberman::Score::update1()
{
    int x = GetRandomValue(1, 2);
    _score1 = _score1 + x;
}

void Bomberman::Score::update2()
{
    int x = GetRandomValue(1, 2);
    _score2 = _score2 + x;
    _highscore1 = GetRandomValue(200, 400);
}

int Bomberman::Score::get_score1()
{
    return _score1;
}

int Bomberman::Score::get_score2()
{
    return _score2;
}

int Bomberman::Score::get_highscore()
{
    return _highscore1;
}