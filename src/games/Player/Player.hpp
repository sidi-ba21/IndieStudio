/*
** EPITECH PROJECT, 2022
** Player
** File description:
** Player
*/

#include "raylib.h"
#include "cmath"
#include <stdio.h>

#define XBOX360_LEGACY_NAME_ID "Xbox Controller"
#if defined(PLATFORM_RPI)
#define XBOX360_NAME_ID "Microsoft X-Box 360 pad"
#define PS3_NAME_ID "PLAYSTATION(R)3 Controller"
#else
#define XBOX360_NAME_ID "Xbox 360 Controller"
#define PS3_NAME_ID "PLAYSTATION(R)3 Controller"
#endif

#ifndef COLOR_EQUAL
#define COLOR_EQUAL(col1, col2) ((col1.r == col2.r) && (col1.g == col2.g) && (col1.b == col2.b) && (col1.a == col2.a))
#endif

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

namespace Bomberman
{

    class Player
    {
    public:
        Player() = default;
        ~Player();
        void init();
        void Player_animation();
        void draw();
        void draw_face();
        void Player_move1(Color *, Texture2D _cubicTexture);
        void Player_move2(Color *, Texture2D _cubicTexture);
        float get_spd1();
        float spd1 = 0.05;
        float spd2 = 0.05;
        Model get_Model();
        Model get_Model2();
        Texture2D score_player_face1();
        Texture2D score_player_face_AI();
        Texture2D score_player_face_2();
        Vector3 get_pos(int player = 1);
        void setPos(Vector3 chk_pos)
        {
            _pos2 = chk_pos;
        }
        ModelAnimation *get_anim2()
        {
            return _anim2;
        }
        int get_anifram()
        {
            return _animFrameCounter;
        }
        float get_rotate1()
        {
            return _rotate1;
        }
        float get_rotate2()
        {
            return _rotate2;
        }
        bool Check_collision(Vector3, int direction, Color *mapPixels, Texture2D _cubicTexture);
        int get_life(int player = 1) {
            if (player == 1)
                return _life1;
            else
                return _life2;
        }
        void set_life(int life, int player = 1) {
            if (player == 1)
                _life1 += life;
            else
                _life2 += life;
        }

    protected:
    private:
        unsigned int _animCount{2};
        int _animFrameCounter{0};
        float _rotate1{0};
        float _rotate2{0};
        int _life1{100};
        int _life2{100};

        Vector3 _pos1{14, 0.1, 6};
        Vector3 _pos2{-15, 0.1, -7};
        Model _model;
        Model _model2;
        ModelAnimation *_anim;
        ModelAnimation *_anim2;
        Texture2D _texture;
        Texture2D _texture2;
        Texture2D _player_face1;
        Texture2D _player_face2;
        Texture2D _player_face_AI;
        int del{0};
    };
}

#endif /* !PLAYER_HPP_ */
