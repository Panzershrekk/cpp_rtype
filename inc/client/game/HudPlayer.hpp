//
// Created by arthaox on 20/01/18.
//

#ifndef _HUDPLAYER_HPP_
#define _HUDPLAYER_HPP_

#include <iostream>
#include <string>

//#include "Player.hpp"
//#include "Character.hpp"
#include "Sprite.hpp"

class HudPlayer
{
private:
    Sprite  _ship;
    Text    _name;
    Text    _score;
    Text    _hp;

public:
    HudPlayer(const std::string &, int, int);
    ~HudPlayer();

    void updateHp(int);
    void updateScore(int);
    void displayInfo(Window&);
};

#endif //_HUDPLAYER_HPP_
