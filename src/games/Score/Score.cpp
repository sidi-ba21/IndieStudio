/*
** EPITECH PROJECT, 2022
** Score
** File description:
** Score
*/

#include "Score.hpp"

void Bomberman::Score::init()
{
    _score1 = 0;
    _score2 = 0;
    _score_AI = 0;
}

void Bomberman::Score::update(int n)
{
    if (n == 0)
        _score_AI = _score_AI + 1;
    if (n == 1)
        _score1 = _score1 + 1;
    if (n == 2)
        _score2 = _score2 + 1;
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

Bomberman::Score::~Score()
{
}