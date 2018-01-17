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
    ~LoginMenu();

    void start(Window &) override;
    void update(Window &) override;
    void draw(Window &) override;
};


#endif /* !CPP_RTYPE_LOGINMENU_HPP_ */
