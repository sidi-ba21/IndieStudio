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
#include "../games/Player/Player.hpp"

namespace Bomberman
{
    class AI {
        public:
            AI() = default;
            ~AI();
            void init_AI();
            float move_AI(Color *mapPixels, Texture2D _cubicTexture);
            Model get_Model()
            {
                return _Model_AI;
            }
            void setPos(Vector3 chk_pos)
            {
                _Pos_AI = chk_pos;
            }
            ModelAnimation *get_anim2()
            {
                return _Anim_AI;
            }
            int get_anifram()
            {
                return _AnimFrameCounter_AI;
            }
            Vector3 get_pos()
            {
                    return _Pos_AI;
            }
            bool Check_collision_AI(Vector3, int direction, Color *mapPixels, Texture2D _cubicTexture);
        protected:
        private:
            unsigned int _animCount_AI{2};
            int _AnimFrameCounter_AI{0};
            float Rotation_AI{0};

            Vector3 _Pos_AI{-15, 0.1, 6};
            Model _Model_AI;
            ModelAnimation *_Anim_AI;
            Texture2D _texture_AI;
            Vector3 _Chk_pos;

            int _check;
            std::time_t _time;
    };
}

#endif /* !AI_HPP_ */