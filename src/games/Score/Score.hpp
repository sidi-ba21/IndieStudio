/*
** EPITECH PROJECT, 2022
** Score
** File description:
** Score
*/

#include "raylib.h"
#include <cmath>
#include <fstream>

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
            void loadScore() {
            std::ifstream file;
            std::string line;
            file.open("Score.txt", std::ifstream::in);
            if (file.peek() == std::ifstream::traits_type::eof())
                _highscore.assign("NOT AVAILABLE");
            else {
                if (file.is_open() && std::getline(file, line))
                    _highscore = line;
            }
            file.close();
        }
        void writeScore(std::string score, std::string name) {
            std::fstream file;
            std::string line;
            std::string tmp;
            (void) name;
            if (_highscore.compare("NOT AVAILABLE") == 0 || std::stoi(_highscore) < std::stoi(score)) {
                file.open("Score.txt",  std::ios::trunc | std::ios::in | std::ios::out);
                file << score << std::endl;
                _highscore = score;
            }
            file.close();
        };
      /*  void setPath(const std::string &path) {
            _path = path;
        }
        std::string getName() {
            return _name;
        }*/
        std::string getHightScore() {
            return _highscore;
        }

        protected:
        private:
            int _score1{0};
            std::string _highscore{ "NOT AVAILABLE" };
            int _score2{0};
    };

}

#endif /* !SCORE_HPP_ */
