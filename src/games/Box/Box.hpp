/*
** EPITECH PROJECT, 2022
** Box
** File description:
** Box
*/

#include "raylib.h"

#ifndef BOX_HPP_
#define BOX_HPP_

namespace Bomberman
{
    class Box {
        public:
            Box();
            ~Box();
            void init();
            Texture2D get_breakable_texture();
            Texture2D get_grass_texture();
            Texture2D get_brick_texture();
            Rectangle get_rectGrass();

        protected:
        private:
            Texture2D _breakable_texture;
            Texture2D _grass_texture;
            Texture2D _brick_texture;
            Rectangle _rectGrass;
        };

}

#endif /* !BOX_HPP_ */
