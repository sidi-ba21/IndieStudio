/*
** EPITECH PROJECT, 2022
** Map
** File description:
** Map
*/

#include "raylib.h"
#include <cmath>

#ifndef MAP_HPP_
    #define MAP_HPP_

namespace Bomberman {

    class Map {
        public:
            Map() = default;
            ~Map();
            void init();
            void update();
            Model get_model();
            Vector3 get_pos();
            Texture2D get_cubicTexture();
            Image get_image();

        protected:
        private:
            Vector3 _pos = {-16.0f, 0.0f, -8.0f}; //set model position
            Image _image;
            Texture2D _cubicTexture;
            Texture2D _texture;
            Mesh _mesh;
            Model _model;
    };

}

#endif /* !MAP_HPP_ */
