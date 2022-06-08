/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "IObject.hpp"

namespace Bomberman {

class Sound : public IObject {
    public:
        Sound(std::string path) : _path(path) {};
        ~Sound() override = default;

        std::string getSound() const {
            return _path;
        };
        void setSound(std::string path) {
            _path = std::move(path);
        };

    protected:
    private:
        std::string _path;
};

}

#endif /* !SOUND_HPP_ */
