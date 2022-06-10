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
            float Player_move();
            Model get_Model();
            Model get_Model2();
            Vector3 get_pos(int player = 1);
            void setPos(Vector3 chk_pos)
            {
                _pos2 = chk_pos;
            }
            ModelAnimation *get_anim2()
            {
                return _anim2;
            }
            int get_anifram()
            {
                return _animFrameCounter;
            }

        protected:
        private:
            unsigned int _animCount{2};
            int _animFrameCounter{0};
            float rotation{0};
            float rotation2{0};

            Vector3 _pos1{14, 0.1, 6};
            Vector3 _pos2{-15, 0.1, -7};
            Model _model;
            Model _model2;
            ModelAnimation *_anim;
            ModelAnimation *_anim2;
            Texture2D _texture;
            Texture2D _texture2;
    };
}

#endif /* !PLAYER_HPP_ */
