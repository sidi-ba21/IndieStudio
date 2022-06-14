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
    int x = 1;
    _score1 = _score1 + x;
}

void Bomberman::Score::update2()
{
    int x = 1;
    _score2 = _score2 + x;
}

void Bomberman::Score::update_AI()
{
    int x = 1;
    _score_AI = _score_AI + x;
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