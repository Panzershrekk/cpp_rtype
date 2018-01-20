//
// Created by grodin on 19/01/18.
//

#ifndef CPP_RTYPE_ITEMLOBBYMENU_HPP_
#define CPP_RTYPE_ITEMLOBBYMENU_HPP_


#include <gameEngine/Sprite.hpp>

class ItemLobbyMenu
{
  private:
    Sprite	_sprite;
    Text	_text;
  public:
    ItemLobbyMenu(const std::string &, int, int);
    ~ItemLobbyMenu();

    Sprite 	&getSprite();
    Text	&getText();

    void 	activeItem(int);
};


#endif /* !CPP_RTYPE_ITEMLOBBYMENU_HPP_ */
