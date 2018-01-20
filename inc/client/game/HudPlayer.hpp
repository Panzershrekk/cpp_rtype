//
// Created by arthaox on 20/01/18.
//

#ifndef _HUDPLAYER_HPP_
#define _HUDPLAYER_HPP_

#include "Sprite.hpp";

class HUDPlayer
{
private:
    Sprite  _ship;
    Text    _score;
    Test    _hp;

public:
    HUDPlayer();
    virtual ~HUDPlayer();

    void UpdateHp(int);
    void UpdateScore(int);
};

#endif //_HUDPLAYER_HPP_
