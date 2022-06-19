/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#pragma once

#include "raylib.h"
#include <iostream>
#include "../../core/Time.hpp"
#include "../Box/Box.hpp"
#include "../Map/Map.hpp"
#include "../Score/Score.hpp"
#include "../Player/Player.hpp"
#include "../AI/AI.hpp"

#ifndef BOMB_HPP_
#define BOMB_HPP_

namespace Bomberman {

    class Bomb : public Raylib::Draw, public Time {
        public:
            Bomb();
            ~Bomb();
            void init();
            void update();
            void time_bomb();
            std::tuple<float, float, float> get_pos();
            void pose_bomb(float x, float y, float z);
            void explosion(Bomberman::Box &box, Bomberman::Map &map, Bomberman::Score &score, int n,
                           Bomberman::AI &ai, Bomberman::Player &player);
            void wait_bomb();

        protected:
        private:
            std::tuple<float, float, float> _pos;
            bool _ispressed = false;
    };

}

#endif /* !BOMB_HPP_ */
