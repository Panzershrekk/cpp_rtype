//
// Created by grodin on 18/01/18.
//

#include <iostream>
#include	"ItemRoomListMenu.hpp"

ItemRoomListMenu::ItemRoomListMenu(float x, float y) :
  _back("../assets/RoomListMenu_ItemList.png", x, y),
  _roomName("X", "../KOMIKAX_.ttf"),
  _enablePlayer("/4", "../KOMIKAX_.ttf")
{
  Position2D pos = this->_back.getPosition();

  this->_roomName.setCharacterSize(100);
  this->_enablePlayer.setCharacterSize(100);
  this->_roomName.setPosition(pos.getX() + 100, pos.getY() + 25);
  this->_enablePlayer.setPosition(pos.getX() + 500, pos.getY() + 25);

}

ItemRoomListMenu::~ItemRoomListMenu()
  = default;

Sprite &ItemRoomListMenu::getBack()
{
  return (this->_back);
}

Text &ItemRoomListMenu::getRoomName()
{
  return (this->_roomName);
}

Text &ItemRoomListMenu::getEnablePlayer()
{
  return (this->_enablePlayer);
}

void ItemRoomListMenu::updateRoomName(int nb)
{
  this->getRoomName().setString(std::to_string(nb));
}

void ItemRoomListMenu::updatePlayers(int nPlayer)
{
  std::string tmp;

  this->getEnablePlayer().getString().clear();
  tmp = std::to_string(nPlayer) + this->getEnablePlayer().getString();
  this->getEnablePlayer().setString(tmp);
}