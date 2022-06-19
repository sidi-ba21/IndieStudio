/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-bill.on
** File description:
** main
*/

#include "raylib.h"
#include "Core.hpp"
#include <math.h>
#include <string>

int basic_error(int ac, char **av)
{
    (void) av;
    if (ac != 1) {
        std::cout << "Bomberman: Usage: ./Bomberman" << std::endl;
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (basic_error(ac, av) == 84)
        return 84;
    Bomberman::Core core;
    return 0;
}