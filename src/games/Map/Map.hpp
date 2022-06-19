/*
** EPITECH PROJECT, 2022
** Map
** File description:
** Map
*/

//#include "raylib.h"
#include "../../graphicals/Draw/Draw.hpp"
#include <cmath>

#ifndef COLOR_EQUAL
    #define COLOR_EQUAL(col1, col2) ((col1.r == col2.r)&&(col1.g == col2.g)&&(col1.b == col2.b)&&(col1.a == col2.a))
#endif
#ifndef MAP_HPP_
    #define MAP_HPP_

namespace Bomberman {

    class Map : public Raylib::Draw {
        public:
            Map() = default;
            ~Map();
            void init();
            void update();
            void random_maps();
            void draw();
            //Model get_model();
            //Vector3 get_pos();
            //Texture2D get_cubicTexture();
            //Image get_image();
            //Color *get_color();

        protected:
        private:
            Vector3 _pos = {-16.0f, 0.0f, -8.0f}; //set model position
            Image _image;
            Texture2D _cubicTexture;
            Texture2D _texture;
            Mesh _mesh;
            Model _model;
            Color *_color;
            int del{0};
    };

}

#endif /* !MAP_HPP_ */
