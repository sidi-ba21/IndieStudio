/*
** EPITECH PROJECT, 2022
** indie
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include <chrono>
#include <functional>
#include <vector>
#include "../Player/Player.hpp"
#include "Object.hpp"

class AI: public Bomberman::Player {
    public:
        AI();
        ~AI() = default;
    protected:
    private:
};

struct coords
{
    coords(float f = 0, float s = 0, float t = 0) : first(f), second(s), third(t) {};
    coords &operator+=(coords const &rhs) {
        first += rhs.first;
        second += rhs.second;
        third += rhs.third;
        return *this;
    }
    float first;
    float second;
    float third;
};

#endif /* !AI_HPP_ */
