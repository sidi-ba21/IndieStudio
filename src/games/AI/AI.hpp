/*
** EPITECH PROJECT, 2022
** indie
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include <chrono>
#include <functional>
#include <vector>
#include <iostream>
#include "../Player/Player.hpp"

namespace Bomberman
{
    class AI {
        public:
            AI() = default;
            ~AI();
            void init_AI();
            void move_AI(Color *mapPixels, Texture2D _cubicTexture);
            void draw();
            Model get_Model() {
                return _Model_AI;
            }
            void setPos(Vector3 chk_pos) {
                _Pos_AI = chk_pos;
            }
            ModelAnimation *get_anim2() {
                return _Anim_AI;
            }
            int get_anifram() {
                return _AnimFrameCounter_AI;
            }
            Vector3 get_pos() {
                    return _Pos_AI;
            }
            float get_rotate() {
                return _Rotate_AI;
            }
            bool Check_collision_AI(Vector3, int direction, Color *mapPixels, Texture2D _cubicTexture);
            int get_life() {
                return _life;
            }
            void set_life(int life) {
                _life += life;
            }

        protected:
        private:
            unsigned int _animCount_AI{2};
            int _AnimFrameCounter_AI{0};
            float _Rotate_AI{0};
            int _check{0};
            int _life{100};

            Vector3 _Pos_AI{-15, 0.1, 6};
            Model _Model_AI;
            ModelAnimation *_Anim_AI;
            Texture2D _texture_AI;
            Vector3 _Chk_pos;

            std::time_t _time{0};
            int del{0};
    };
}

#endif /* !AI_HPP_ */