/*
** EPITECH PROJECT, 2022
** Draw
** File description:
** Draw
*/

#include "raylib.h"
#include "../../core/Error.hpp"

#ifndef DRAW_HPP_
    #define DRAW_HPP_

namespace Raylib {

    class Draw {
        public:
            Draw();
            ~Draw();
            void initWindow();
            int get_dimscreen() {
                return screenWidth;
            }
            bool game_loop();
            void draw_box();
            void draw_map();
            void draw_player();
            void set_image(std::string &path) {
                _image = LoadImage(path.c_str());
            }
            void set_texture(std::string &path) {
                _texture = LoadTexture(path.c_str());
            }
            void set_texturefromImage() {
                _texture2 = LoadTextureFromImage(_image);
            }
            void set_vector2(std::vector<float> &vect) {
                _vector2 = (Vector2){vect[0], vect[1]};
            }
            void set_vector3(std::vector<float> &vect) {
                _vector3 = (Vector3){vect[0], vect[1], vect[2]};
            }
            void set_meshCubicmap() {
                _mesh = GenMeshCubicmap(_image, _vector3);
            }
            void set_modelfromMesh() {
                _model = LoadModelFromMesh(_mesh);
            }
            void set_colorfromImage() {
                _color = LoadImageColors(_image);
            }
            void set_model(std::string &path) { 
                _model = LoadModel(path.c_str());
            }
            void set_modelAnim(std::string &path, unsigned int animcount) {
                _anim = LoadModelAnimations(path.c_str(), &animcount);
            }
            Model get_model() { return _model; }
            Vector2 get_vector2() { return _vector2; }
            Vector3 get_vector3() { return _vector3; }
            Texture2D get_texture() { return _texture; }
            Texture2D get_texture2() { return _texture2; }
            Image get_image() { return _image; }
            Color *get_color() { return _color; }

        protected:
        private:
            const int screenWidth{1920};
            const int screenHeight{1080};
            Vector3 _vector3;
            Vector2 _vector2;
            Image _image;
            Texture2D _texture;
            Texture2D _texture2;
            ModelAnimation *_anim;
            Mesh _mesh;
            Model _model;
            Color *_color;
    };

}

#endif /* !DRAW_HPP_ */
