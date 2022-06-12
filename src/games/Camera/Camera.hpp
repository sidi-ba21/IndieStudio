/*
** EPITECH PROJECT, 2022
** Camera
** File description:
** Camera
*/

#include "raylib.h"
#include <cmath>

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

namespace Bomberman {

    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;
            void init();
            void Camera_move();
            Camera3D get_Camera();
    
        protected:
        private:
            float _radius{20};
            float _angle{1.57};
            Vector3 _position{-5, 20, -5};
            Vector3 _target{0, 2, 0};
            Vector3 _up{0, 2, 0};
            float _fovy{45};
            int _projection{CAMERA_PERSPECTIVE};
            Camera3D _camera = (Camera3D){_position, _target, _up, _fovy, _projection};
            //Camera3D _camera = (Camera3D){(Vector3){-5, 8, -5}, (Vector3){0, 2, 0}, (Vector3){0, 2, 0}, 45, CAMERA_PERSPECTIVE};
    };
}

#endif /* !CAMERA_HPP_ */
