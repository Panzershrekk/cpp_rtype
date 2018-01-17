//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_IMENU_HPP_
#define CPP_RTYPE_IMENU_HPP_

#include	"Window.hpp"
#include	"MenuState.hpp"

class IMenu
{
  public:
  IMenu();
  virtual ~IMenu();

    virtual void start(Window &) = 0;
    virtual void draw(Window &) = 0;
    virtual void update(Window &, sf::Event &) = 0;
};


#endif /* !CPP_RTYPE_IMENU_HPP_ */
