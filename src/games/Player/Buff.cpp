/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Buff
*/

#include "Buff.hpp"

void Bomberman::Buff::Power_up1(Bomberman::Player &_player)
{
    if (_player.get_pos(1).x > -14 &&  _player.get_pos(1).x < -12 &&  _player.get_pos(1).z > -5 &&  _player.get_pos(1).z < -3 && upchk == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk = 1;   
    }
    if ( _player.get_pos(1).x > -15 &&  _player.get_pos(1).x < -13 &&  _player.get_pos(1).z > 3 &&  _player.get_pos(1).z < 5 && upchk1 == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk1 = 1;   

    }
    if ( _player.get_pos(1).x > 13 &&  _player.get_pos(1).x < 15 &&  _player.get_pos(1).z > 3 &&  _player.get_pos(1).z < 5 && upchk2 == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk2 = 1;
    }
    if ( _player.get_pos(1).x > 12 &&  _player.get_pos(1).x < 14 &&  _player.get_pos(1).z > -6 &&  _player.get_pos(1).z < -4 && upchk3 == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk3 = 1;
    }
    if ( _player.get_pos(1).x > -10 &&  _player.get_pos(1).x < -8 &&  _player.get_pos(1).z > -4 &&  _player.get_pos(1).z < -2 && upchk4 == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk4 = 1;
    }
    if ( _player.get_pos(1).x > -8 &&  _player.get_pos(1).x < -6 &&  _player.get_pos(1).z > 4 &&  _player.get_pos(1).z < 6 && upchk5 == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk5 = 1;
    }
    if ( _player.get_pos(1).x > 4 &&  _player.get_pos(1).x < 6 &&  _player.get_pos(1).z > -8 &&  _player.get_pos(1).z < -6 && upchk6 == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk6 = 1;
    }
    if ( _player.get_pos(1).x > 9 &&  _player.get_pos(1).x < 11 &&  _player.get_pos(1).z > 1 &&  _player.get_pos(1).z < 3 && upchk7 == 0){
        _player.spd1 = _player.spd1 + 0.002;
        upchk7 = 1;
    }
}

void Bomberman::Buff::Power_up2(Bomberman::Player &_player)
{
    if (_player.get_pos(2).x > -14 && _player.get_pos(2).x < -12 && _player.get_pos(2).z > -5 && _player.get_pos(2).z < -3 && upchek == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek = 1;   
    }
    if (_player.get_pos(2).x > -15 && _player.get_pos(2).x < -13 && _player.get_pos(2).z > 3 && _player.get_pos(2).z < 5 && upchek1 == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek1 = 1;   

    }
    if (_player.get_pos(2).x > 13 && _player.get_pos(2).x < 15 && _player.get_pos(2).z > 3 && _player.get_pos(2).z < 5 && upchek2 == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek2 = 1;
    }
    if (_player.get_pos(2).x > 12 && _player.get_pos(2).x < 14 && _player.get_pos(2).z > -6 && _player.get_pos(2).z < -4 && upchek3 == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek3 = 1;
    }
    if (_player.get_pos(2).x > -10 && _player.get_pos(2).x < -8 && _player.get_pos(2).z > -4 && _player.get_pos(2).z < -2 && upchek4 == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek4 = 1;
    }
    if (_player.get_pos(2).x > -8 && _player.get_pos(2).x < -6 && _player.get_pos(2).z > 4 && _player.get_pos(2).z < 6 && upchek5 == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek5 = 1;
    }
    if (_player.get_pos(2).x > 4 && _player.get_pos(2).x < 6 && _player.get_pos(2).z > -8 && _player.get_pos(2).z < -6 && upchek6 == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek6 = 1;
    }
    if (_player.get_pos(2).x > 9 && _player.get_pos(2).x < 11 && _player.get_pos(2).z > 1 && _player.get_pos(2).z < 3 && upchek7 == 0){
        _player.spd2 = _player.spd2 + 0.002;
        upchek7 = 1;
    }
}

void Bomberman::Buff::Power_down1(Bomberman::Player &_player)
{
    if ( _player.get_pos(1).x > -13 &&  _player.get_pos(1).x < -11 &&  _player.get_pos(1).z > -2 &&  _player.get_pos(1).z < 0 && dwchk == 0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk = 1;
    }
    if ( _player.get_pos(1).x > -12 &&  _player.get_pos(1).x < -10 &&  _player.get_pos(1).z > 4 &&  _player.get_pos(1).z < 6 && dwchk1 ==0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk1 = 1;
    }
    if ( _player.get_pos(1).x > 5 &&  _player.get_pos(1).x < 7 &&  _player.get_pos(1).z > -2 &&  _player.get_pos(1).z < 0 && dwchk2 == 0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk2 = 1;
    }
    if ( _player.get_pos(1).x > 11 &&  _player.get_pos(1).x < 13 &&  _player.get_pos(1).z > -8 &&  _player.get_pos(1).z < -6 && dwchk3 == 0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk3 = 1;
    }
    if ( _player.get_pos(1).x > -6 &&  _player.get_pos(1).x < -4 &&  _player.get_pos(1).z > -8 &&  _player.get_pos(1).z < -6 && dwchk4 == 0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk4 = 1;
    }
    if ( _player.get_pos(1).x > -5 &&  _player.get_pos(1).x < -3 &&  _player.get_pos(1).z > -1 &&  _player.get_pos(1).z < 1 && dwchk5 == 0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk5 = 1;
    }
    if ( _player.get_pos(1).x > 1 &&  _player.get_pos(1).x < 3 &&  _player.get_pos(1).z > -5 &&  _player.get_pos(1).z < -3 && dwchk6 == 0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk6 = 1;
    }
    if ( _player.get_pos(1).x > -1 &&  _player.get_pos(1).x < 1 &&  _player.get_pos(1).z > 5 &&  _player.get_pos(1).z < 7 && dwchk7 == 0){
        _player.spd1 = _player.spd1 - 0.002;
        dwchk7 = 1;
    }
}

void Bomberman::Buff::Power_down2(Bomberman::Player &_player)
{
    if (_player.get_pos(2).x > -13 && _player.get_pos(2).x < -11 && _player.get_pos(2).z > -2 && _player.get_pos(2).z < 0 && dwchek == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek = 1;
    }
    if (_player.get_pos(2).x > -12 && _player.get_pos(2).x < -10 && _player.get_pos(2).z > 4 && _player.get_pos(2).z < 6 && dwchek1 == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek1 = 1;
    }
    if (_player.get_pos(2).x > 5 && _player.get_pos(2).x < 7 && _player.get_pos(2).z > -2 && _player.get_pos(2).z < 0 && dwchek2 == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek2 = 1;
    }
    if (_player.get_pos(2).x > 11 && _player.get_pos(2).x < 13 && _player.get_pos(2).z > -8 && _player.get_pos(2).z < -6 && dwchek3 == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek3 = 1;
    }
    if (_player.get_pos(2).x > -6 && _player.get_pos(2).x < -4 && _player.get_pos(2).z > -8 && _player.get_pos(2).z < -6 && dwchek4 == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek4 = 1;
    }
    if (_player.get_pos(2).x > -5 && _player.get_pos(2).x < -3 && _player.get_pos(2).z > -1 && _player.get_pos(2).z < 1 && dwchek5 == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek5 = 1;
    }
    if (_player.get_pos(2).x > 1 && _player.get_pos(2).x < 3 && _player.get_pos(2).z > -5 && _player.get_pos(2).z < -3 && dwchek6 == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek6 = 1;
    }
    if (_player.get_pos(2).x > -1 && _player.get_pos(2).x < 1 && _player.get_pos(2).z > 5 && _player.get_pos(2).z < 7 && dwchek7 == 0){
        _player.spd2 = _player.spd2 - 0.002;
        dwchek7 = 1;
    }
}