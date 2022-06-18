/*
** EPITECH PROJECT, 2022
** Time
** File description:
** Time
*/

#include <iostream>
#include <chrono>
#include <raylib.h>

#ifndef TIME_HPP_
#define TIME_HPP_

class Time {
    public:
        Time() : _start(clock_::now()) {}
        ~Time() = default;
        void reset() { _start = clock_::now(); }
        void elapsed() {
            _elapse = std::chrono::duration_cast<second_>(clock_::now() - _start).count();
        }
        float deltaTime() {
            return _elapse * 1/GetFPS();
        }
        float getTime() {
            return _elapse;
        }
    protected:
    private:
        typedef std::chrono::high_resolution_clock clock_;
        typedef std::chrono::duration<float, std::ratio<1> > second_;
        std::chrono::time_point<clock_> _start;
        float _elapse{0};

};

#endif /* !TIME_HPP_ */
