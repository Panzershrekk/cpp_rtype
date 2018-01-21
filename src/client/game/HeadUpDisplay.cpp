//
// Created by arthaox on 20/01/18.
//

#include <client/game/HeadUpDisplay.hpp>

HeadUpDisplay::HeadUpDisplay(std::vector<Player> &player, const std::string &path, int x, int y) : _splashScreen(path, x, y)
{
    this->_splashScreen.setScale(1.3, 1.5);
  for (int i = 0; i < player.size(); i++) {
    switch (i) {
      case 0 : this->_hudPlayer.emplace(std::make_pair(player.at(0).getName(),
					      std::make_shared<HudPlayer>(
						player.at(0).getName(),
						"../assets/LobbyMenu_SpaceShip_1.png",
						x + 10, 905)));
	break;
      case 1 : this->_hudPlayer.emplace(std::make_pair(player.at(1).getName(),
					      std::make_shared<HudPlayer>(
						player.at(1).getName(),
						"../assets/LobbyMenu_SpaceShip_2.png",
						x + 10, 953)));
	break;
      case 2 : this->_hudPlayer.emplace(std::make_pair(player.at(2).getName(),
					      std::make_shared<HudPlayer>(
						player.at(2).getName(),
						"../assets/LobbyMenu_SpaceShip_3.png",
						x + 605, 905)));
	break;
      case 3 : this->_hudPlayer.emplace(std::make_pair(player.at(3).getName(),
					      std::make_shared<HudPlayer>(
						player.at(3).getName(),
						"../assets/LobbyMenu_SpaceShip_4.png",
						605, 953)));
	break;
      default:
	break;
    }
  }
}

HeadUpDisplay::~HeadUpDisplay()
{

}

void    HeadUpDisplay::update(std::vector<Player> &players, Window& window)
{
    for (auto it: players)
    {
      this->_hudPlayer.at(it.getName())->updateScore(it.getScore());
        this->_hudPlayer.at(it.getName())->updateHp(it.getHp());
    }
  this->displayHud(window);
}

void  HeadUpDisplay::displayHud(Window &window)
{
    window.draw(this->_splashScreen);
    for (auto it: _hudPlayer) {
        it.second->displayInfo(window);
    }
}
