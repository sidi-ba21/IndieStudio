/*
** EPITECH PROJECT, 2022
** Score
** File description:
** Score
*/

#include "raylib.h"
#include <cmath>

#ifndef SCORE_HPP_
#define SCORE_HPP_

namespace Bomberman {

    class Score {
        public:
            Score() = default;
            ~Score() = default;
            void init();
            void update1();
            void update2();
            int get_score1();
            int get_score2();
            int get_highscore();

        protected:
        private:
            int _score1{0};
            int _highscore1{0};
            int _score2{0};
    };

}

#endif /* !SCORE_HPP_ */
