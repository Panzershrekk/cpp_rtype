//
// Created by grodin on 15/01/18.
//

#include	"MenuWindow.hpp"
#include	<iostream>


MenuWindow::MenuWindow() : _win(TITLE, 1920, 1080)
{
  _vecMenu.push_back(std::shared_ptr<IMenu>(_mainMenu));
  _vecMenu.push_back(std::shared_ptr<IMenu>(_loginMenu));
  _vecMenu.push_back(std::shared_ptr<IMenu>(_roomListMenu));
  _vecMenu.push_back(std::shared_ptr<IMenu>(_lobbyMenu));

  _loginMenu->setClient(_client);
  _roomListMenu->setClient(_client);
  _lobbyMenu->setClient(_client);

  this->_state = EMainMenu;
  try
  {
    std::string path = "../assets/pierre.jpg";
    Image image(path);
    _win.getRenderWindow().setIcon(image.getWidht(),
				   image.getHeight(),
				   image.getPixelsPtr());
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::update(sf::Event &event)
{
  if (_client != nullptr && _client->getMenu() != 1)
    _client->setMenu(&_vecMenu);
  _vecMenu.at(_state)->update(_win, event);
}

void MenuWindow::start()
{
  while (_win.isOpen())
  {
    sf::Event	event;
    while (_win.pollEvent(event))
    {
      update(event);
      switch (event.type);
    }
    _win.clear();
    _vecMenu.at(_state)->draw(_win);
    _win.display();
  }
}