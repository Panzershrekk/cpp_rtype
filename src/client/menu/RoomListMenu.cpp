//
// Created by grodin on 16/01/18.
//

#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>
#include "RoomListMenu.hpp"


RoomListMenu::RoomListMenu(MenuState & state) :
  _state(state),
  _back("../assets/RoomListMenu_Background.jpg"),
  _return("../assets/Menu_Button_Back.png", 25, 900),
  _title("Choose your room", "../Triumph-wheels-rough.ttf", 600, 50)
{
  this->_return.setScale(0.5f, 0.5f);
  this->_title.setCharacterSize(150);
  genRooms(3);
}

RoomListMenu::~RoomListMenu()
= default;

void RoomListMenu::start(Window &win)
{
}

void RoomListMenu::genRooms(int nbRoom)
{
  static float x = 450;
  static float y = 200;

  for (int i = 0; i < nbRoom; i++)
  {
    this->_vectorRooms.push_back(std::make_shared<ItemRoomListMenu>(x, y + 100));
    this->_vectorRooms[i]->updateRoomName(i + 1);
    y = y + 200;
  }
}

void RoomListMenu::joinRoom(Window &win, sf::Event &event)
{
  this->_state = ELobbyMenu;
  getWhichRoom();
}

void RoomListMenu::returnFunction(Window &win, sf::Event &event)
{
  if (_client == nullptr)
    std::cout << "problem" << std::endl;
  else {
    std::cout << "working" << std::endl;
    _client->write("back button");
  }
  /*
  if (_client != nullptr) {
    _client->disconnect();
    _client = nullptr;
  }
  else
    std::cout << "problem" << std::endl;
  this->_state = ELoginMenu;*/
}

int RoomListMenu::getWhichRoom()
{
  std::cout << "room" << this->_nbRoom << std::endl;
  return (this->_nbRoom);
}

void RoomListMenu::update(Window &win, sf::Event &event)
{
  auto fJoin = std::bind(&RoomListMenu::joinRoom, this, std::placeholders::_1, std::placeholders::_2);
  auto fBack = std::bind(&RoomListMenu::returnFunction, this, std::placeholders::_1, std::placeholders::_2);

  this->_return.onClick(fBack, win, event);

  this->_nbRoom = 0;
  for (auto it : this->_vectorRooms)
  {
    it->getBack().onClick(fJoin, win, event);
    this->_nbRoom++;
  }
  _vectorRooms[0]->updatePlayers(1);
  if (event.type == sf::Event::Closed) {
    win.close();
  }
}

void RoomListMenu::drawItems(Window &win)
{
  for (const auto &it : _vectorRooms)
  {
    win.draw(it->getBack());
    win.draw(it->getRoomName());
    win.draw(it->getEnablePlayer());
  }
}

void RoomListMenu::draw(Window &win)
{
  win.draw(this->_back);
  win.draw(this->_return);
  win.draw(this->_title);
  drawItems(win);
}

void RoomListMenu::setClient(TcpClient *&client) {
  _client = std::move(client);
}

