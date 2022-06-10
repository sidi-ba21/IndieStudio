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
    class AI: public Bomberman::Player {
        public:
            AI();
            ~AI() = default;
            float move_AI();
        protected:
        private:
            Vector3 _Pos2;
            Vector3 _Chk_pos;
            Model _Model2;
            ModelAnimation *_Anim2;
            float Rotation2{0};
            int _AnimFrameCounter{0};
            std::chrono::seconds _time;
    };
}

#endif /* !AI_HPP_ */