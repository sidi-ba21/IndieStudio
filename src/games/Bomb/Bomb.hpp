/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#include "raylib.h"
#include <iostream>
#include "../../core/Time.hpp"
#include "../Box/Box.hpp"
#include "../Map/Map.hpp"
#include "../Score/Score.hpp"

#ifndef BOMB_HPP_
#define BOMB_HPP_

namespace Bomberman {

    class Bomb : public Time{
        public:
            Bomb();
            ~Bomb();
            void init();
            void update();
            void time_bomb();
            Vector3 get_pos();
            void draw_bomb();
            void pose_bomb(Vector3 pos);
            void explosion(Bomberman::Box box, Bomberman::Map map, Bomberman::Score score, int n);
            void wait_bomb();

        protected:
        private:
            Vector3 _pos = {-16.0f, 0.0f, -8.0f}; //set model position
            bool _ispressed = false;
            float _time_bomb;
            //Mesh _mesh;
            //Model _model;
    };

}

#endif /* !BOMB_HPP_ */
