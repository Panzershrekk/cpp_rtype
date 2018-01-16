//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_IMENU_HPP_
#define CPP_RTYPE_IMENU_HPP_

#include	<SFML/Graphics.hpp>
#include	"MainMenu.hpp"
#include	"Window.hpp"
#include	"MenuState.hpp"
#include	"Sprite.hpp"

class IMenu
{
  public:
    virtual ~IMenu() = default;

    virtual void start() = 0;
    virtual void update() = 0;
};


#endif /* !CPP_RTYPE_IMENU_HPP_ */
