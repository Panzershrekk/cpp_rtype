//
// Created by arthaox on 20/01/18.
//

#ifndef _HEADUPDISPLAY_HPP_
#define _HEADUPDISPLAY_HPP_

#include <map>
#include <iostream>
#include <vector>

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
    HeadUpDisplay(std::vector<Player> &, const std::string &, int, int);
    ~HeadUpDisplay();

    void update(std::vector<Player> &, Window&);
    //void update(Window &, int);
  void displayHud(Window &);
};

#endif //_HEADUPDISPLAY_HPP_
