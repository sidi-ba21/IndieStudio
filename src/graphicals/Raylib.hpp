/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#include <raylib.h>
#include "IGraphic.hpp"
#include "Window.hpp"
#include "RaylibException.hpp"
//#include "AudioDevice.hpp"
//#include "AudioStream.hpp"
//#include "BoundingBox.hpp"
//#include "Camera2D.hpp"
//#include "Camera3D.hpp"
//#include "Color.hpp"
//#include "Font.hpp"
//#include "Functions.hpp"
//#include "Gamepad.hpp"
//#include "Image.hpp"
//#include "Material.hpp"
//#include "Matrix.hpp"
//#include "Mesh.hpp"
//#include "Model.hpp"
//#include "ModelAnimation.hpp"
//#include "Mouse.hpp"
//#include "Music.hpp"
//#include "Ray.hpp"
//#include "RaylibException.hpp"
//#include "RayCollision.hpp"
//#include "Rectangle.hpp"
//#include "RenderTexture.hpp"
//#include "Shader.hpp"
//#include "Sound.hpp"
//#include "Text.hpp"
//#include "Texture.hpp"
//#include "Vector2.hpp"
//#include "Vector3.hpp"
//#include "Window.hpp"

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

namespace Bomberman {

    class Raylib : public IGraphic {
        public:
            Raylib();
            ~Raylib();
            Raylib(const Raylib&) = delete;
            Raylib& operator=(const Raylib&) = delete;
            Raylib(Raylib &&) = delete;
            Raylib& operator=(Raylib &&) = delete;
            void createWindow();
            void drawBackground(std::string);
            //void draw(std::shared_ptr<Arcade::IObject> obj);
            void clear();
            void update();
            //Arcade::Button getEvent();
        protected:
        private:
            //SDL_Window *_window;
            //SDL_Renderer *_renderer;
            //TTF_Font *_font;
            //Mix_Music *_sound;

    };

}

#endif /* !RAYLIB_HPP_ */
