//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_LOBBYMENU_HPP_
#define CPP_RTYPE_LOBBYMENU_HPP_

#include "IMenu.hpp"

class LobbyMenu : public IMenu
{
  private:

  public:
    explicit LobbyMenu();
    ~LobbyMenu() override;

    void start() override;
    void update() override;
};

#endif /* !CPP_RTYPE_LOBBYMENU_HPP_ */
