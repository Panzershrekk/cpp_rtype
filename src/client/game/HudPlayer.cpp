//
// Created by arthaox on 20/01/18.
//

#include "client/game/HudPlayer.hpp"

HudPlayer::HudPlayer(const std::string &path, int x, int y) : _ship(path, x, y), _name("toto", "../KOMIKAX_.ttf"), _hp("100", "../KOMIKAX_.ttf"), _score("0", "../KOMIKAX_.ttf")
{
    this->_ship.setScale(0.2F, 0.2F);
    this->_hp.setCharacterSize(15);
    this->_score.setCharacterSize(15);
    this->_name.setCharacterSize(15);
}

HudPlayer::~HudPlayer()
{

}

void    HudPlayer::updateHp(int dammage)
{
    this->_hp.setString(std::to_string(dammage));
}

void    HudPlayer::updateScore(int NewScore)
{
    this->_score.setString(std::to_string(NewScore));
}

void    HudPlayer::displayInfo(Window &window)
{
   this->_score.setPosition(this->_ship.getPosition().getX() + 425, this->_ship.getPosition().getY());
   this->_hp.setPosition(this->_ship.getPosition().getX() + 275, this->_ship.getPosition().getY());
   this->_name.setPosition(this->_ship.getPosition().getX() + 100, this->_ship.getPosition().getY());

   window.draw(this->_ship);
   window.draw(this->_name);
   window.draw(this->_hp);
   window.draw(this->_score);
}