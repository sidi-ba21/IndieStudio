/*
** EPITECH PROJECT, 2022
** Box
** File description:
** Box
*/

#include "raylib.h"
#include "../Map/Map.hpp"
#include "../Player/Player.hpp"

#ifndef BOX_HPP_
    #define BOX_HPP_

namespace Bomberman
{
    class Box {
        public:
            Box();
            ~Box();
            void init();
            void draw_breakable(Bomberman::Map map);
            void remove_breakable(Bomberman::Map map, Vector3 pos, Player player);
            Texture2D get_breakable_texture();
            Texture2D get_speed_up_texture();
            Texture2D get_speed_down_texture();
            Texture2D get_grass_texture();
            Texture2D get_brick_texture();
            Rectangle get_rectGrass();
            void random_walls();
            void random_breackable();

        protected:
        private:
            Texture2D _breakable_texture;
            Texture2D _grass_texture;
            Texture2D _brick_texture;
            Texture2D _speed_up_texture;
            Texture2D _speed_down_texture;
            Rectangle _rectGrass;
        };

}

#endif /* !BOX_HPP_ */
