//
// Created by grodin on 15/01/18.
//

#include	"MenuWindow.hpp"

MenuWindow::MenuWindow() : _win(TITLE, 1920, 1080), _mainMenu()
{
  this->_menuState = EMainMenu;
  //TODO : Reset la position de la souris pour eviter le bug du clic save
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::update()
{
  _mainMenu.update(this->_win);
}

void MenuWindow::start()
{
  while (_win.isOpen())
  {
    sf::Event event;

    while (_win.pollEvent(event))
    {
      update();
      switch (event.type)
      {
	case sf::Event::Closed:
	  _win.close();

	  break;
      }
    }
    _win.clear();
    _mainMenu.draw(_win);
    _win.display();
  }
}