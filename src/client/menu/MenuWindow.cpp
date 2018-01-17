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
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::update(sf::Event &event)
{
  this->_loginMenu->update(this->_win, event);
 /* auto e = _state.find(EMainMenu);
  std::cout << e->second << std::endl;
  _mainMenu.update(this->_win);*/
  _vecMenu.at(_state)->update(_win);
}

void MenuWindow::start()
{
  while (_win.isOpen())
  {
    sf::Event	event;
    while (_win.pollEvent(event))
    {
      update(event);
      switch (event.type)
      {
	/*case sf::Event::Closed:
	  _win.close();
	  break;
	  */
      }
    }
    _win.clear();
    _vecMenu.at(_state)->draw(_win);
    _win.display();
  }
}