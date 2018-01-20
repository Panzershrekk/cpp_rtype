//
// Created by grodin on 16/01/18.
//

#include 	<SFML/Window/Event.hpp>
#include	"LobbyMenu.hpp"

LobbyMenu::LobbyMenu(MenuState &state) :
  _state(state),
  _back("../assets/LobbyMenu_Background.jpg"),
  _return("../assets/Menu_Button_Back.png", 25, 900),
  _playerOne("../assets/LobbyMenu_SpaceShip_1.png", 100, 100),
  _playerTwo("../assets/LobbyMenu_SpaceShip_2.png", 1000, 100),
  _playerThree("../assets/LobbyMenu_SpaceShip_3.png", 100, 600),
  _playerFour("../assets/LobbyMenu_SpaceShip_4.png", 1000, 600)
{
  this->_return.setScale(0.5f, 0.5f);
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
  drawItems(win, this->_playerOne);
  drawItems(win, this->_playerTwo);
  drawItems(win, this->_playerThree);
  drawItems(win, this->_playerFour);
}

void LobbyMenu::returnFunction(Window &, sf::Event &)
{
  this->_state = ERoomListMenu;
}

void LobbyMenu::update(Window &win, sf::Event &event)
{
  auto	fBack = std::bind(&LobbyMenu::returnFunction, this, std::placeholders::_1, std::placeholders::_2);

  this->_return.onClick(fBack, win, event);

  if (event.type == sf::Event::Closed)
    win.close();
}
