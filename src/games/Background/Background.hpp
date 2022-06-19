/*
** EPITECH PROJECT, 2022
** Background
** File description:
** Background
*/

#include <raylib.h>
#include "../../graphicals/Draw/Draw.hpp"

#ifndef BACKGROUND_HPP_
    #define BACKGROUND_HPP_

namespace Bomberman {

    class Background : public Raylib::Draw {
        public:
            Background() = default;
            ~Background() {
                free_texture();
            }
            void init() {
                std::string path = std::string("Png/space_background.png");
                set_texture(path);
            }
        protected:
        private:
    };
}

#endif /* !BACKGROUND_HPP_ */
