/*
** EPITECH PROJECT, 2022
** Box
** File description:
** Box
*/

#include "raylib.h"
#include "../Map/Map.hpp"
#include "../Player/Player.hpp"
#include "../AI/AI.hpp"
#include "../../graphicals/Draw/Draw.hpp"

#ifndef BOX_HPP_
    #define BOX_HPP_

namespace Bomberman
{
    class Box : public Raylib::Draw {
        public:
            Box() = default;
            ~Box();
            void init();
            void draw_breakable(Bomberman::Map map);
            void remove_breakable(Bomberman::Map map, Vector3 pos);
            int Damage(Vector3 pos, Bomberman::Player player,
            Bomberman::AI ai, int n);
            void random_walls();
            void random_breackable();

        protected:
        private:
            int del{0};
        };

    enum box {
        SPEED_UP = 0,
        SPEED_DOWN,
        GRASS_TEXTURE,
        BRICK,
        BREAKABLE,
    };
}

#endif /* !BOX_HPP_ */
