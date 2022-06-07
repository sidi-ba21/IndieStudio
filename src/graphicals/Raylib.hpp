/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#include "IGraphic.hpp"
#include "raylib.h"

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

namespace Bomberman {

    class Raylib : public IGraphic {
        public:
            Raylib();
            ~Raylib();
            Raylib(const Raylib&) = delete;
            Raylib& operator=(const Raylib&) = delete;
            Raylib(Raylib &&) = delete;
            Raylib& operator=(Raylib &&) = delete;
            void createWindow();
            void drawBackground(std::string);
            void draw(std::shared_ptr<Arcade::IObject> obj);
            void clear();
            void update();
            Arcade::Button getEvent();
        protected:
        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            TTF_Font *_font;
            Mix_Music *_sound;

    };

}

#endif /* !RAYLIB_HPP_ */
