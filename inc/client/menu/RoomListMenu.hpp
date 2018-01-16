//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_ROOMLISTMENU_HPP_
#define CPP_RTYPE_ROOMLISTMENU_HPP_


#include "IMenu.hpp"

class RoomListMenu : public IMenu
{
  private:

  public:
    RoomListMenu();
    ~RoomListMenu() override;

    void	start() override;
    void 	update() override;
};


#endif /* !CPP_RTYPE_ROOMLISTMENU_HPP_ */
