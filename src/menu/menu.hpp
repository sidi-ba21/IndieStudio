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

static const lt tab[7] =
{
    {{960, 100}, &game},
    {{480, 700}, &options},
    {{320, 400}, &adios},
    {{480, 270}, &minus},
    {{480, 810}, &minus},
    {{1440, 270}, &plus},
    {{1440, 810}, &plus}
};

namespace Bomberman {
        class ost {
        public:
            ost(std::string, size_t, bool);
            ~ost() { CloseAudioDevice(); };
            void init(std::string, size_t, bool);
            void operator=(const ost &) = delete;
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

        private:
            Vector2 mousepos = { -100.0f, -100.0f };
            bool is_title = true;
            int i = -1;
            ost musiic;
            ost sfx;
    };
}

typedef struct lt
{
    std::pair <float, float>coords;
    void (*lt2)(Bomberman::ost &obj, Vector2 mousepos);
}lt;

void game(Bomberman::ost &obj, Vector2 mousepos);
void options(Bomberman::ost &obj, Vector2 mousepos);
void adios(Bomberman::ost &obj, Vector2 mousepos);
void minus(Bomberman::ost &obj, Vector2 mousepos);
void plus(Bomberman::ost &obj, Vector2 mousepos);
