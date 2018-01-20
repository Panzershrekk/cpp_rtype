//
// Created by grodin on 19/01/18.
//

#include	"ItemLobbyMenu.hpp"

ItemLobbyMenu::ItemLobbyMenu(const std::string &str, int x, int y) :
  _sprite(str, x, y),
  _text("truc", "../KOMIKAX_.ttf", x, y)
{
  Position2D	pos = this->_sprite.getPosition();

  _text.setCharacterSize(30);
  _text.setPosition(pos.getX() + 400, pos.getY() + 100);
  _sprite.setScale(2, 2);
}

ItemLobbyMenu::~ItemLobbyMenu()
{}

Sprite	&ItemLobbyMenu::getSprite()
{
  return (this->_sprite);
}

Text	&ItemLobbyMenu::getText()
{
  return (this->_text);
}