//
// Created by arthaox on 20/01/18.
//

#ifndef _HEADUPDISPLAY_HPP_
#define _HEADUPDISPLAY_HPP_

#include <map>
#include <iostream>

#include "Sprite.hpp"
#include "HudPlayer.hpp"
#include "Player.hpp"
#include "Character.hpp"

class HeadUpDisplay
{
private:
    Sprite  _splashScreen;
    std::map<std::string, std::shared_ptr<HudPlayer>>        _hudPlayer;
public:
    HeadUpDisplay(const std::string &, int, int);
    ~HeadUpDisplay();

    void update(const std::vector<Player> &);
    //void update(Window &, int);
  void displayHud(Window &);
};

#endif //_HEADUPDISPLAY_HPP_
