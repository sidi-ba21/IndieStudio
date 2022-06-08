/*
** EPITECH PROJECT, 2022
** INDIE
** File description:
** music
*/

#include <iostream>
#include "raylib.h"

    class ost {
        public:
            ost(std::string, size_t, bool);
            ~ost();
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
