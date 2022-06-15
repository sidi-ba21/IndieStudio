/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include <raylib.h>
#include "Error.hpp"
#include "../graphicals/Raylib.hpp"
#include "../games/Player/Player.hpp"
#include "../games/Camera/Camera.hpp"
#include "../games/Score/Score.hpp"
#include "../games/Map/Map.hpp"
#include "../AI/AI.hpp"
#include "../menu/menu.hpp"
#include "../games/Box/Box.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

namespace Bomberman
{
    class Core
    {
    public:
        Core();
        ~Core();
        void init();
        void game_loop();
        void Draw();
        void Draw2d();
        void Draw3d();
        void Draw_breakabke();
        void Remove_breakable(Vector3 pos);
        void set_Bomb_AI();
        Core(const Core &) = delete;
        Core &operator=(const Core &) = delete;
        Core(Core &&) = delete;
        Core &operator=(Core &&) = delete;

    protected:
    private:
        const int screenWidth{1920};
        const int screenHeight{1080};
        int _chk_AI;
        float r{0};
        float _rotate_ai{0};
        float rt{0};
        Vector3 _bomb_pos;
        Vector3 _bomb_pos2;
        Vector3 _bomb_pos_AI;
        int pressed{0};
        int pressed2{0};
        int pressed_AI{0};
        Player _player;
        Camera _camera;
        Score _score;
        Map _map;
        Box _box;
        Menu _menu;
        Model model;
        Image image;
        Texture2D background;
        Texture2D texture;
        std::time_t time1;
        std::time_t time2;
        AI _ai;
    };
}

#endif /* !CORE_HPP_ */
