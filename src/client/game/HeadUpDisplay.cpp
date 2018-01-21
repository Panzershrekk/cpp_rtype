//
// Created by arthaox on 20/01/18.
//

#include <client/game/HeadUpDisplay.hpp>

HeadUpDisplay::HeadUpDisplay(const std::string &path, int x, int y) : _splashScreen(path, x, y)
{
    this->_splashScreen.setScale(1.3, 1.5);
    //TODO obtenir le vector de player ici et set les name à la place de player1, player2 etc..
    this->_hudPlayer.emplace(std::make_pair("Player1", std::make_shared<HudPlayer>("../assets/LobbyMenu_SpaceShip_1.png", 75, 905)));
    this->_hudPlayer.emplace(std::make_pair("Player2", std::make_shared<HudPlayer>("../assets/LobbyMenu_SpaceShip_2.png", 75, 953)));
    this->_hudPlayer.emplace(std::make_pair("Player3", std::make_shared<HudPlayer>("../assets/LobbyMenu_SpaceShip_3.png", 605, 905)));
    this->_hudPlayer.emplace(std::make_pair("Player4", std::make_shared<HudPlayer>("../assets/LobbyMenu_SpaceShip_4.png", 605, 953)));
}

HeadUpDisplay::~HeadUpDisplay()
{

}

void    HeadUpDisplay::update(const std::vector<Player> &players)
{
 /*   for (auto it: players)
    {
        this->_hudPlayer.at(it.getName())->updateScore(it.getScore());
        this->_hudPlayer.at(it.getName())->updateHp(it.getHp());
    }*/
 /* this->_hudPlayer.at("Player1")->updateHp(i);
  this->_hudPlayer.at("Player1")->updateScore(i);
  this->displayHud(window);*/
}

void  HeadUpDisplay::displayHud(Window &window)
{
    window.draw(this->_splashScreen);
    for (auto it: _hudPlayer) {
        it.second->displayInfo(window);
    }
}
