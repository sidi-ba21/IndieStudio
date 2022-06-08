/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include <string>
#include <utility>
#include <vector>

namespace Bomberman {

class IObject {
    public:
        virtual ~IObject() = default;
};

enum Color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

enum Button {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ENTER,
        ESCAPE,
        MENU,
        RESTART,
        PAUSE,
        NOTHING
    };
}

#endif /* !IOBJECT_HPP_ */
