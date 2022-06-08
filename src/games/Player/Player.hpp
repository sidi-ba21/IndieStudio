/*
** EPITECH PROJECT, 2022
** Player
** File description:
** Player
*/

#include "raylib.h"
#include "cmath"

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

namespace Bomberman {

    class Player {
        public:
            Player() = default;
            ~Player();
            void init();
            float Player_animation();
            void Player_move();
            Model get_Model();
            Vector3 get_position(int player = 1);

        protected:
        private:
            unsigned int _animCount{2};
            int _animFrameCounter{0};
            float rotation{0};

            Vector3 _pos1{14, 0.1, 6};
            Vector3 _pos2{-15, 0.1, -7};
            Model _model;
            ModelAnimation *_anim;
            Texture2D _texture;
    };
}

#endif /* !PLAYER_HPP_ */
