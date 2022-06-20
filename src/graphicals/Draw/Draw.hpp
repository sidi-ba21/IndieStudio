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
            void draw_score(std::vector<int> &score, std::string hightscore, float time);
            void draw_text_player(std::vector<int> &life);
            void draw_speed_up(Texture2D texture);
            void draw_speed_down(Texture2D texture);
            void draw_map(std::size_t n = 0);
            void draw_player(std::size_t n = 0);
            void draw_background(std::size_t n = 0);
            void draw_bomb(std::size_t n = 0);
            void draw_box(std::size_t n, std::size_t x, std::size_t y, float z, std::size_t h);
            void remove_box(float x, float y);
            void set_image(std::string &path) {
                _image.push_back(LoadImage(path.c_str()));
            }
            void del_image() {
                if (_image.size() > 0) {
                    if (_image[0].data != nullptr)
                        UnloadImage(_image[0]);
                    _image.pop_back();
                }
            }
            void set_texture(std::string &path) {
                _texture.push_back(LoadTexture(path.c_str()));
            }
            void set_texturefromImage(std::size_t n = 0) {
                _texture.push_back(LoadTextureFromImage(_image[n]));
            }
            void del_texturefromImage() {
                if (_texture.size() > 0) {
                    if (_texture[0].id != 0)
                        UnloadTexture(_texture[0]);
                    _texture.pop_back();
                }
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
            void del_meshCubicmap() {
                if (_mesh.size() > 0) {
                    if (_mesh[0].vaoId != 0)
                        UnloadMesh(_mesh[0]);
                    _mesh.pop_back();
                }
            }
            void set_modelfromMesh(std::size_t n = 0) {
                _model.push_back(LoadModelFromMesh(_mesh[n]));
            }
            void del_modelfromMesh() {
                if (_mesh.size() > 0) {
                    if (_mesh[0].vaoId != 0)
                        UnloadMesh(_mesh[0]);
                    _mesh.pop_back();
                }
            }
            void set_colorfromImage(std::size_t n = 0) {
                _color.push_back(LoadImageColors(_image[n]));
            }
            void del_colorfromImage() {
                if (_color.size() > 0) {
                    if (_color[0] != nullptr)
                        UnloadImageColors(_color[0]);
                    _color.pop_back();
                }
            }
            void set_model(std::string &path) { 
                _model.push_back(LoadModel(path.c_str()));
            }
            void del_model() {
                if (_model.size() > 0) {
                    if (_model[0].meshes != nullptr)
                        UnloadModel(_model[0]);
                    _model.pop_back();
                }
            }
            void set_modelAnim(std::string &path, unsigned int animcount) {
                _anim.push_back(LoadModelAnimations(path.c_str(), &animcount));
            }
            void set_cameraMode(std::size_t n) {
                SetCameraMode(_camera, n);
            }
            void set_rect(float x, float y, float height, float width) {
                rect = Rectangle{x, y, height, width};
            }
            void del_vector3() {
                if (!_vector3.empty())
                    _vector3.pop_back();
            }
            void del_texture() {
                if (_texture.size() == 5) {
                   for (int i = 0; i < 5; i++) {
                        if (_texture[i].id != 0)
                            UnloadTexture(_texture[i]);
                        _texture.pop_back();
                   }
                }
            }
            std::size_t get_texturesize() {
                return _texture.size();
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
            Camera3D get_camera3D() { return _camera; }
            Rectangle get_rectangle() { return rect; }
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
            Rectangle rect;
            Camera3D _camera; //= (Camera3D){(Vector3){-5, 8, -5}, (Vector3){0, 2, 0}, (Vector3){0, 2, 0}, 45, CAMERA_PERSPECTIVE};
    };

}

#endif /* !DRAW_HPP_ */
