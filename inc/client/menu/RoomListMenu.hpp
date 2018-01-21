//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_ROOMLISTMENU_HPP_
#define CPP_RTYPE_ROOMLISTMENU_HPP_


#include "IMenu.hpp"
#include "ItemRoomListMenu.hpp"
#include "TcpClient.hpp"

class RoomListMenu : public IMenu
{
  private:
  int		_nbRoom = 0;
  MenuState &	_state;
  Sprite	_back;
  Sprite	_return;
  Text		_title;
  std::vector<std::shared_ptr<ItemRoomListMenu>>	_vectorRooms;
  TcpClient				*_client;

  public:
    explicit RoomListMenu(MenuState &);
    ~RoomListMenu() override;

    void 	drawItems(Window &);
    void 	genRooms(int);

    void 	joinRoom(Window &, sf::Event &);

    void	start(Window &) override;
    void 	draw(Window &) override;
    void 	update(Window &, sf::Event &) override;
    void	setClient(TcpClient *&);

  void returnFunction(Window &win, sf::Event &event);

  int getWhichRoom();
};

#endif /* !CPP_RTYPE_ROOMLISTMENU_HPP_ */
