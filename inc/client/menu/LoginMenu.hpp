//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_LOGINMENU_HPP_
#define CPP_RTYPE_LOGINMENU_HPP_


#include "IMenu.hpp"

class LoginMenu : public IMenu
{
  private:

  public:
    explicit LoginMenu();
    ~LoginMenu() override;

    void start() override;
    void update() override;
};


#endif /* !CPP_RTYPE_LOGINMENU_HPP_ */
