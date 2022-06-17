/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#include "raylib.h"
#include <iostream>

#ifndef BOMB_HPP_
#define BOMB_HPP_

namespace Bomberman {

    class Bomb {
        public:
            Bomb();
            ~Bomb();
            void init();
            void update();
            Vector3 get_pos();
            void pose_bomb(Vector3 pos);
            void explosion();
            void wait_bomb();

        protected:
        private:
            Vector3 _pos = {-16.0f, 0.0f, -8.0f}; //set model position
            int disp{0};
            //Mesh _mesh;
            //Model _model;
    };

}

#endif /* !BOMB_HPP_ */
