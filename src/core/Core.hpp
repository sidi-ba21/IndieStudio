/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#include "raylib.h"
#include "Error.hpp"
#include "../games/Player/Player.hpp"
#include <iostream>
#include <string>
//#include "../graphicals/Raylib.hpp"
#include <cmath>

#ifndef CORE_HPP_
#define CORE_HPP_

namespace Bomberman
{
    class Core
    {
        public:
            Core();
            ~Core();
            void init();
            void game_loop();
            void Camera();
            void Score();
            void Draw();
            void Draw2d();
            void Draw3d();
            Core(const Core &) = delete;
            Core &operator=(const Core &) = delete;
            Core(Core &&) = delete;
            Core &operator=(Core &&) = delete;
            float r{0};
            float rt{0};
        protected:
        private:
            const int screenWidth{1920};
            const int screenHeight{1080};

            int score{0};
            int hiscore{0};
            float cam_radius{20};
            float cam_angle{1.57};

            Camera3D camera = (Camera3D){(Vector3){-5, 8, -5}, (Vector3){0, 2, 0}, (Vector3){0, 2, 0}, 45, CAMERA_PERSPECTIVE};
            Vector3 mapPosition = {-16.0f, 0.0f, -8.0f};                // Set model position
            Player _player;
            Image image;
            Texture2D cubicmap;
            Mesh mesh;
            Model model;
            Texture2D texture;
            Texture2D background;
    };
}

#endif /* !CORE_HPP_ */
