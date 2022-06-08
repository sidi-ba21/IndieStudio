/*
** EPITECH PROJECT, 2022
** Exception
** File description:
** Exception
*/

#ifndef RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_
#define RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_

#include <stdexcept>
#include <string>

namespace Bomberman {
    class RaylibException : public std::runtime_error {
        public:
            RaylibException(std::string message) throw() : std::runtime_error(message) {
                // Nothing
            }
            void TraceLog(int logLevel = LOG_ERROR) {
                ::TraceLog(logLevel, std::runtime_error::what());
            }
    };

}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RAYLIBEXCEPTION_HPP_
