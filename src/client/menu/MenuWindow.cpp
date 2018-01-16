//
// Created by grodin on 15/01/18.
//

#include	"MenuWindow.hpp"
#include	<iostream>

MenuWindow::MenuWindow() : _win(TITLE, 1920, 1080), _mainMenu()
{
//  _state.insert(std::pair<MenuState,int>(EMainMenu,1));
//  _state.insert(std::pair<MenuState,int>(ELoginMenu,2));
//  _state.insert(std::pair<MenuState,int>(ERoomListMenu,3));
//  _state.insert(std::pair<MenuState,int>(ELobbyMenu,4));

  //TODO : Reset la position de la souris pour eviter le bug du clic save
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::update()
{
 /* auto e = _state.find(EMainMenu);
  std::cout << e->second << std::endl;
  _mainMenu.update(this->_win);*/
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