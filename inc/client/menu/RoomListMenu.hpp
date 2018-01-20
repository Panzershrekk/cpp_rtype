//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_ROOMLISTMENU_HPP_
#define CPP_RTYPE_ROOMLISTMENU_HPP_


#include "IMenu.hpp"
#include "ItemRoomListMenu.hpp"

class RoomListMenu : public IMenu
{
  private:
  MenuState &	_state;
  Sprite	_back;
  Sprite	_return;
  Text		_title;
  std::vector<std::shared_ptr<ItemRoomListMenu>>	_vectorRooms;

  public:
    explicit RoomListMenu(MenuState &);
    ~RoomListMenu() override;

    void 	drawItems(Window &);
    void 	genRooms(int);

    void 	joinRoom(Window &, sf::Event &);

    void	start(Window &) override;
    void 	draw(Window &) override;
    void 	update(Window &, sf::Event &) override;

  void returnFunction(Window &win, sf::Event &event);
};

#endif /* !CPP_RTYPE_ROOMLISTMENU_HPP_ */