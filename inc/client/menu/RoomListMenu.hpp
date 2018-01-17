//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_ROOMLISTMENU_HPP_
#define CPP_RTYPE_ROOMLISTMENU_HPP_


#include "IMenu.hpp"

class RoomListMenu : public IMenu
{
  private:
  MenuState &_state;
  public:
    explicit RoomListMenu(MenuState &);
    ~RoomListMenu() override;

    void	start(Window &) override;
    void 	draw(Window &) override;
    void 	update(Window &) override;
};


#endif /* !CPP_RTYPE_ROOMLISTMENU_HPP_ */
