/*
** EPITECH PROJECT, 2022
** Core
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

namespace Bomberman {

    class Core {
        public:
            Core();
            ~Core();
            Core(const Core&) = delete;
            Core& operator=(const Core&) = delete;
            Core(Core &&) = delete;
            Core& operator=(Core &&) = delete;
        protected:
        private:
    };
}

#endif /* !CORE_HPP_ */
