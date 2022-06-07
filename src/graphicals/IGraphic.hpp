/*
** EPITECH PROJECT, 2022
** IGraphic
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

namespace Bomberman {

    class IGraphic {
        public:
            IGraphic();
            ~IGraphic();
            IGraphic(const IGraphic&) = delete;
            IGraphic& operator=(const IGraphic&) = delete;
            IGraphic(IGraphic &&) = delete;
            IGraphic& operator=(IGraphic &&) = delete;
            virtual void createWindow() = 0;
            virtual void drawBackground(std::string) = 0;
            virtual void draw(std::shared_ptr<Arcade::IObject> obj) = 0;
            virtual void clear() = 0;
            virtual void update() = 0;
            virtual Arcade::Button getEvent() = 0;

        protected:
        private:
    };

}

#endif /* !IGRAPHIC_HPP_ */
