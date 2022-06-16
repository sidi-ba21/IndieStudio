/*
** EPITECH PROJECT, 2022
** Background
** File description:
** Background
*/

#include <raylib.h>

#ifndef BACKGROUND_HPP_
    #define BACKGROUND_HPP_

namespace Bomberman {

    class Background {
        public:
            Background() = default;
            ~Background() {
                UnloadTexture(_texture);
            }
            void init() {
                _texture = LoadTexture("Png/space_background.png");
            }
            void draw() {
                DrawTextureV(_texture, Vector2{0, 0}, WHITE);
            }
        protected:
        private:
            Texture2D _texture;
    };
}

#endif /* !BACKGROUND_HPP_ */
