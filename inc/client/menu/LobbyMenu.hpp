//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_LOBBYMENU_HPP_
#define CPP_RTYPE_LOBBYMENU_HPP_

#include "IMenu.hpp"

class LobbyMenu : public IMenu
{
  private:
  MenuState 	&_state;
  Sprite	_back;

public:
    explicit LobbyMenu(MenuState &);
    ~LobbyMenu() override;

    void start(Window &) override;
    void draw(Window &) override;
    void update(Window &, sf::Event &) override;
};

#endif /* !CPP_RTYPE_LOBBYMENU_HPP_ */
