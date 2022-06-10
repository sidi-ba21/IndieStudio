/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** menu
*/

#pragma once

#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <raylib.h>

namespace Bomberman {
        class ost {
        public:
            ost();
            ost(std::string, size_t, bool);
            ~ost();
            void init(std::string, size_t, bool);
            void operator=(const ost &);
            void set_volume(size_t);
            size_t get_volume();
            void set_pause();
            bool get_pause();
            Music get_ost();
            void set_ost(Music);

            private:
            std::string _music_name;
            Music _mp3;
            size_t _volume;
            bool _is_paused;
    };
    class Menu {
        public:
            Menu();
            ~Menu();
            void init();
            void update();
            void loop();
            void operator=(const Menu &) = delete;
            void set_mousepos(Vector2 obj) {mousepos = obj;}
            Vector2 get_mousepos() { return mousepos;}
            void set_title(bool obj) { is_title = obj;}
            bool get_title() { return is_title;}
            int get_cmt() { return i;}
            void set_cmt(int p) {i = p;}
            bool get_game() { return is_game; }
            void set_gamebool(bool obj) { is_game = obj; }

            void game();
            void options();
            void adios();
            void minus();
            void plus();
            void game_options();

        private:
            Vector2 mousepos = { -100.0f, -100.0f };
            bool is_title = true;
            bool is_game = false;
            int i = -1;
            ost musiic;
            ost sfx;
            int screenWidth = 480;
            int screenHeight = 1080;

    };
}