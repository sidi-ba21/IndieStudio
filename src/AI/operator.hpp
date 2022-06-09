/*
** EPITECH PROJECT, 2022
** indie
** File description:
** operator
*/

#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include "raylib.h"

class Point
{
    public:
        Point(const int &x = 0, const int &y = 0);
        bool operator==(const Point &point) {
            return (point._x == _x && point._y == _y);
        }
        bool operator!=(const Point &point) {
            return (point._x != _x || point._y != _y);
        }
        Point operator+(const Point &point) {
            return Point(point._x + _x, point._y + _y);
        }
        Point &operator=(const Point &point) {
            _x = point._x;
            _y = point._y;
            return *this;
        }
    int _y;
    int _x;
};


#endif /* !OPERATOR_HPP */
