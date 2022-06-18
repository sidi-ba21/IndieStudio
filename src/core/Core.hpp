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
#include "../games/AI/AI.hpp"
#include "../games/Background/Background.hpp"
#include "../menu/menu.hpp"
#include "../games/Box/Box.hpp"
#include "../games/Bomb/Bomb.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <vector>
#include "Time.hpp"

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
        void Draw_text();
        void Draw_map();
        void Draw_ai();
        void Draw_speed_up();
        void Draw_speed_down();
        void Draw_player();
        void score();
        void Draw2d();
        void Draw3d();
        void set_bomb();
        Core(const Core &) = delete;
        Core &operator=(const Core &) = delete;
        Core(Core &&) = delete;
        Core &operator=(Core &&) = delete;

    protected:
    private:
        const int screenWidth{1920};
        const int screenHeight{1080};
        Background _background;
        Player _player;
        Camera _camera;
        Score _score;
        Box _box;
        Map _map;
        Menu _menu;
        AI _ai;
        Bomb _bombP1;
        Bomb _bombP2;
        Bomb _bombAI;
        std::vector<Bomb> _bomb{_bombAI, _bombP1, _bombP2};
        Time _time;
    };
}

#endif /* !CORE_HPP_ */
