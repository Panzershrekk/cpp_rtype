//
// Created by grodin on 16/01/18.
//

#include 	<SFML/Window/Event.hpp>
#include <iostream>
#include	"LobbyMenu.hpp"

LobbyMenu::LobbyMenu(MenuState &state) :
  _state(state),
  _back("../assets/LobbyMenu_Background.jpg"),
  _return("../assets/Menu_Button_Back.png", 25, 900),
  _ready("../assets/LobbyMenu_Button_Ready.png", 1600, 850)
{
  this->_players.push_back(std::make_shared<ItemLobbyMenu>("../assets/LobbyMenu_SpaceShip_1.png", 400, 200));
  this->_players.push_back(std::make_shared<ItemLobbyMenu>("../assets/LobbyMenu_SpaceShip_2.png", 1100, 200));
  this->_players.push_back(std::make_shared<ItemLobbyMenu>("../assets/LobbyMenu_SpaceShip_3.png", 400, 600));
  this->_players.push_back(std::make_shared<ItemLobbyMenu>("../assets/LobbyMenu_SpaceShip_4.png", 1100, 600));

  this->_return.setScale(0.5f, 0.5f);
  this->_ready.setScale(1.5f, 1.5f);
  for (auto it : this->_players)
    it->activeItem(64);

  setActivePlayers(3);
}

LobbyMenu::~LobbyMenu()
= default;

void LobbyMenu::start(Window &)
{
}

void LobbyMenu::drawItems(Window &win, ItemLobbyMenu &item)
{
  win.draw(item.getSprite());
  win.draw(item.getText());
}

void LobbyMenu::draw(Window &win)
{
  win.draw(this->_back);
  win.draw(this->_return);
  win.draw(this->_ready);
  for (auto it : this->_players)
  {
    drawItems(win, *it);
  }
}

void LobbyMenu::setActivePlayers(int nbPlayer)
{
  for (int i = 0; i < nbPlayer; i++)
    this->_players.at(i)->activeItem(255);
}

void LobbyMenu::returnFunction(Window &, sf::Event &)
{
  this->_state = ERoomListMenu;
}

void LobbyMenu::readyFunction(Window &, sf::Event &)
{
  this->_players.at(0)->getSprite().setColor(0, 255, 0, 255);
  std::cout << "Ready !" << std::endl;
}

void LobbyMenu::whichPlayerIsReady(int player)
{
  this->_players.at(player - 1)->getSprite().setColor(0, 255, 0, 255);
}

void LobbyMenu::update(Window &win, sf::Event &event)
{
  auto	fBack = std::bind(&LobbyMenu::returnFunction, this, std::placeholders::_1, std::placeholders::_2);
  auto	fReady = std::bind(&LobbyMenu::readyFunction, this, std::placeholders::_1, std::placeholders::_2);

  this->_return.onClick(fBack, win, event);
  this->_ready.onClick(fReady, win, event);

  if (event.type == sf::Event::Closed)
    win.close();
}

void LobbyMenu::setClient(TcpClient *client) {
  _client = client;
}
