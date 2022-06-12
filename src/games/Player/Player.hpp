/*
** EPITECH PROJECT, 2022
** Player
** File description:
** Player
*/

#include "raylib.h"
#include "cmath"
#include <stdio.h>

#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

#ifndef COLOR_EQUAL
    #define COLOR_EQUAL(col1, col2) ((col1.r == col2.r)&&(col1.g == col2.g)&&(col1.b == col2.b)&&(col1.a == col2.a))
#endif

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

namespace Bomberman {

    class Player {
        public:
            Player() = default;
            ~Player();
            void init();
            float Player_animation(Color *, Texture2D _cubicTexture);
            float Player_move(Color *, Texture2D _cubicTexture);
            Model get_Model();
            Model get_Model2();
            Vector3 get_pos(int player = 1);
            bool Check_collision(Vector3, int direction, Color *mapPixels, Texture2D _cubicTexture);


        protected:
        private:
            unsigned int _animCount{2};
            int _animFrameCounter{0};
            float rotation{0};
            float rotation2{0};

            Vector3 _pos1{14, 0.1, 6};
            Vector3 _pos2{-15, 0.1, -7};
            Model _model;
            Model _model2;
            ModelAnimation *_anim;
            ModelAnimation *_anim2;
            Texture2D _texture;
            Texture2D _texture2;
    };
}

#endif /* !PLAYER_HPP_ */
