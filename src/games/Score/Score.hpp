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
            Score();
            ~Score();
            void init();
            void update();
            int get_score();
            int get_highscore();

        protected:
        private:
            int _score{0};
            int _highscore{0};
    };

}

#endif /* !SCORE_HPP_ */
