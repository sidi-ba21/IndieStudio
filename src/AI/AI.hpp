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
#include "operator.hpp"
#include <iostream>

class AI: public Bomberman::Player {
    public:
        //AI(std::function<void (const size_t pos, const std::string action)> playerActionsFunc, const std::vector<AI> &AIs, std::vector<std::shared_ptr<Bomberman::Object>> entities, const std::vector<std::string> &map, const size_t &level);
        AI();
        ~AI() = default;
        void run(void) const;
    protected:
    private:
    std::vector<AI> _AIs;
        std::vector<std::shared_ptr<Bomberman::Object>> _entities;
        std::vector<std::string> _map;
        size_t _level;
        std::function<void (const size_t pos, const std::string action)> _playerActionsFunc;
        float calculateDistance(const Point &start, const Point &end) const;
        std::string convertPointIntoAction(const std::pair<int, int> &point) const;
};

#endif /* !AI_HPP_ */
