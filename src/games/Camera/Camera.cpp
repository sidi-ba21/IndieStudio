/*
** EPITECH PROJECT, 2022
** Camera
** File description:
** Camera
*/

#include "Camera.hpp"

void Bomberman::Camera::init()
{
    SetCameraMode(_camera, CAMERA_FREE);
    SetCameraMode(_camera, CAMERA_ORBITAL); // Set an orbital camera mode
}

void Bomberman::Camera::Camera_move()
{
    UpdateCamera(&_camera);
    if (IsKeyDown(KEY_ONE))
        _angle += 0.12;
    if (IsKeyDown(KEY_TWO))
        _angle -= 0.12;
    _camera.position.x = _radius * cos(_angle);
    _camera.position.z = _radius * sin(_angle);
}

Camera3D Bomberman::Camera::get_Camera()
{
    return _camera;
}