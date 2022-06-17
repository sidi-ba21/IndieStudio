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
        throw FileWrongError("Bomberman: Usage: ./Bomberman");
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    basic_error(ac, av);
    //auto time1 = std::time(nullptr);
    //std::cout << time1 << std::endl;
    Bomberman::Core core;
    return 0;
}