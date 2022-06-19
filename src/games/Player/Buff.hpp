/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Buff
*/

#include "Player.hpp"

#ifndef BUFF_HPP_
#define BUFF_HPP_

namespace Bomberman
{
    class Buff
    {
    public:
        Buff() = default;
        ~Buff() = default;
        void Power_up2(Bomberman::Player &_player);
        void Power_up1(Bomberman::Player &_player);
        void Power_down1(Bomberman::Player &_player);
        void Power_down2(Bomberman::Player &_player);

    protected:
    private:
        int upchk = 0;
        int upchk1 = 0;
        int upchk2 = 0;
        int upchk3 = 0;
        int upchk4 = 0;
        int upchk5 = 0;
        int upchk6 = 0;
        int upchk7 = 0;
        int upchek = 0;
        int upchek1 = 0;
        int upchek2 = 0;
        int upchek3 = 0;
        int upchek4 = 0;
        int upchek5 = 0;
        int upchek6 = 0;
        int upchek7 = 0;
        int dwchk = 0;
        int dwchk1 = 0;
        int dwchk2 = 0;
        int dwchk3 = 0;
        int dwchk4 = 0;
        int dwchk5 = 0;
        int dwchk6 = 0;
        int dwchk7 = 0;
        int dwchek = 0;
        int dwchek1 = 0;
        int dwchek2 = 0;
        int dwchek3 = 0;
        int dwchek4 = 0;
        int dwchek5 = 0;
        int dwchek6 = 0;
        int dwchek7 = 0;
    };
}

#endif /* !BUFF_HPP_ */
