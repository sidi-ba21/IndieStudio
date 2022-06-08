/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** menu
*/

#pragma once

#include <utility>
#include <string>
#include <vector>
#include "music.hpp"

typedef struct lt
{
    std::pair <float, float>coords;
    void (*lt2)(ost &obj, Vector2 mousepos);
}lt;

void game(ost &obj, Vector2 mousepos);
void options(ost &obj, Vector2 mousepos);
void adios(ost &obj, Vector2 mousepos);
void minus(ost &obj, Vector2 mousepos);
void plus(ost &obj, Vector2 mousepos);

static const lt tab[7] =
{
    {{960, 100}, &game},
    {{480, 700}, &options},
    {{320, 400}, &adios},
    {{480, 270}, &minus},
    {{480, 810}, &minus},
    {{1440, 270}, &plus},
    {{1440, 810}, &plus}
};
