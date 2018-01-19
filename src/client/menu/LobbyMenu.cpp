//
// Created by grodin on 16/01/18.
//

#include 	<SFML/Window/Event.hpp>
#include	"LobbyMenu.hpp"

LobbyMenu::LobbyMenu(MenuState &state) :
  _state(state),
  _back("../assets/LobbyMenu_Background.jpg")
{

}

LobbyMenu::~LobbyMenu()
= default;

void LobbyMenu::start(Window &)
{
}

void LobbyMenu::draw(Window &win)
{
  win.draw(this->_back);
}

void LobbyMenu::update(Window &win, sf::Event &event)
{
  if (event.type == sf::Event::Closed)
    win.close();
}
