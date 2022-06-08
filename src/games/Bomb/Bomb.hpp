/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#include "raylib.h"

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

        protected:
        private:
            Vector3 _pos = {-16.0f, 0.0f, -8.0f}; //set model position
            Image _image;
            Texture2D _texture;
            //Mesh _mesh;
            //Model _model;
    };

}

#endif /* !BOMB_HPP_ */