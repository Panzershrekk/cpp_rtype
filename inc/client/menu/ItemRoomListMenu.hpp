//
// Created by grodin on 18/01/18.
//

#ifndef CPP_RTYPE_ROOMLISTMENU_H_
#define CPP_RTYPE_ROOMLISTMENU_H_


#include <Sprite.hpp>

class ItemRoomListMenu {
  private:
    Sprite	_back;
    Text	_roomName;
    Text	_enablePlayer;

  public:
    ItemRoomListMenu(float, float);
    ~ItemRoomListMenu();

    Sprite	&getBack();
    Text	&getRoomName();
    Text	&getEnablePlayer();

    void updateRoomName(int);
    void updatePlayers(int);

};


#endif /* !CPP_RTYPE_ROOMLISTMENU_H_ */
