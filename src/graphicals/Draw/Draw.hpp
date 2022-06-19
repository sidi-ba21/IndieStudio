/*
** EPITECH PROJECT, 2022
** Draw
** File description:
** Draw
*/

#include "raylib.h"
#include "../../core/Error.hpp"
#include <vector>

#ifndef DRAW_HPP_
    #define DRAW_HPP_

namespace Raylib {

    class Draw {
        public:
            Draw() = default;
            ~Draw() = default;
            void initWindow();
            void closeWindow();
            std::size_t get_dimscreen() {
                return screenWidth;
            }
            bool game_loop();
            void draw_box(std::size_t n = 0);
            void draw_map(std::size_t n = 0);
            void draw_player(std::size_t n = 0);
            void draw_background(std::size_t n = 0);
            void draw_bomb(std::size_t n = 0);
            void set_image(std::string &path) {
                _image.push_back(LoadImage(path.c_str()));
            }
            void set_texture(std::string &path) {
                _texture.push_back(LoadTexture(path.c_str()));
            }
            void set_texturefromImage(std::size_t n = 0) {
                _texture.push_back(LoadTextureFromImage(_image[n]));
            }
            void set_vector2(float x, float y) {
                _vector2.push_back((Vector2){x, y});
            }
            void set_vector3(float x, float y, float z) {
                _vector3.push_back((Vector3){x, y, z});
            }
            void set_meshCubicmap(std::size_t n = 0) {
                _mesh.push_back(GenMeshCubicmap(_image[n], _vector3[n]));
            }
            void set_modelfromMesh(std::size_t n = 0) {
                _model.push_back(LoadModelFromMesh(_mesh[n]));
            }
            void set_colorfromImage(std::size_t n = 0) {
                _color.push_back(LoadImageColors(_image[n]));
            }
            void set_model(std::string &path) { 
                _model.push_back(LoadModel(path.c_str()));
            }
            void set_modelAnim(std::string &path, unsigned int animcount) {
                _anim.push_back(LoadModelAnimations(path.c_str(), &animcount));
            }
            void free_texture(std::size_t n = 0) {
                if (_texture.size() - 1 >= n && _texture[n].id != 0)
                    UnloadTexture(_texture[n]);
                else
                    throw GraphicsError("texture already free");
            }
            void free_image(std::size_t n = 0) {
                if (_image.size() - 1 >= n && _image[n].data != nullptr)
                    UnloadImage(_image[n]);
                else
                    throw GraphicsError("Image already free");
            }
            void free_model(std::size_t n = 0) {
                if (_model.size() - 1 >= n && (_model[n].meshes != nullptr || _model[n].materials != nullptr))
                    UnloadModel(_model[n]);
                else
                    throw GraphicsError("Model already free");
            }
            void free_mesh(std::size_t n = 0) {
                if (_mesh.size() - 1 >= n && _mesh[n].vaoId != 0)
                    UnloadMesh(_mesh[n]);
                else
                    throw GraphicsError("mesh already free");
            }
            void free_color(std::size_t n = 0) {
                if (_color.size() - 1 >= n && _color[n] != nullptr)
                    UnloadImageColors(_color[n]);
                else
                    throw GraphicsError("color already free");
            }
            Model get_model(std::size_t n = 0) { return _model[n]; }
            Vector2 get_vector2(std::size_t n = 0) { return _vector2[n]; }
            Vector3 get_vector3(std::size_t n = 0) { return _vector3[n]; }
            Texture2D get_texture(std::size_t n = 0) { return _texture[n]; }
            Image get_image(std::size_t n = 0) { return _image[n]; }
            Color *get_color(std::size_t n = 0) { return _color[n]; }
            ModelAnimation *get_modelanim(std::size_t n = 0) { return _anim[n]; }

        protected:
        private:
            const int screenWidth{1920};
            const int screenHeight{1080};
            std::vector<Vector3> _vector3;
            std::vector<Vector2> _vector2;
            std::vector<Image> _image;
            std::vector<Texture2D> _texture;
            std::vector<ModelAnimation *> _anim;
            std::vector<Mesh> _mesh;
            std::vector<Model> _model;
            std::vector<Color *> _color;
    };

}

#endif /* !DRAW_HPP_ */
