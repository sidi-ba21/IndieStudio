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
            ost() = default;
            ost(std::string, size_t, bool);
            ~ost();
            void init(std::string, size_t, bool);
            void operator=(const ost &);
            void set_volume(int);
            int get_volume();
            void set_pause();
            bool get_pause();
            Music get_ost();
            void set_ost(Music);

            private:
            std::string _music_name;
            Music _mp3;
            int _volume;
            bool _is_paused;
    };
    class Button {
        public:
            Button();
            Button(std::string str, Rectangle src, Rectangle bounds) : filename(str), sourceRec(src), btnBounds(bounds) {}
            ~Button() = default;
            void init();
            std::string filename{nullptr};
            Texture2D button;
            Rectangle sourceRec = { 0, 0, 100, 100 };
            Rectangle btnBounds = {0, 0, 100, 100};
            
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
            void set_pause(bool obj) { is_pause = obj; }
            bool get_pause() { return is_pause; }
            void set_finish(bool obj) { is_finished = obj; }
            bool get_finish() { return is_finished; }
            void set_already_clicked(bool obj) { already_clicked = obj; }
            bool get_already_clicked() { return already_clicked; }

            void set_id(int nb) { id = nb; }
            int get_id() { return id; }
            void set_score(int nb) { score = nb; }
            int get_score() { return score; }

            void game();
            void options();
            void adios();
            void pause();
            void tuto();
            void game_options();
            void title_button();
            void the_end();
            void handle_volume();

        private:
            Vector2 mousepos = { -100.0f, -100.0f };
            bool is_title = true;
            bool is_game = false;
            bool is_options = false;
            bool is_pause = false;
            bool is_tuto = false;
            bool is_finished = false;
            bool already_clicked = false;
            size_t i = 4;
            ost musiic;
            Sound sfx;
            int screenWidth = 1920;
            int screenHeight = 1080;
            std::vector<Button> btns;
            int id = 0;
            int score = 69;
            Texture2D face[4];
            std::vector<Bomberman::Button> immg;

    };
}