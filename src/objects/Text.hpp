/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "IObject.hpp"

namespace Bomberman {

class Text : public IObject {
    public:
        Text(std::string text, Bomberman::Color color, float x, float y):
            _text(text), _color(color), _textPos(std::make_pair(x, y)) {};
        ~Text() override = default;

        std::string getText() const {
            return _text;
        };
        Bomberman::Color getColor() const {
            return _color;
        };
        std::pair<float, float> getPos() const {
            return _textPos;
        };

        void setText(std::string text) {
            _text = std::move(text);
        };
        void setColor(Bomberman::Color color) {
            _color = color;
        };
        void setPos(float x, float y) {
            _textPos.first = x;
            _textPos.second = y;
        };

    protected:
    private:
    std::string _text;
    Bomberman::Color _color;
    std::pair<float, float> _textPos;
};

}

#endif /* !TEXT_HPP_ */
