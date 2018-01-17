//
// Created by arthaox on 15/01/18.
//

#ifndef CPP_RTYPE_PACKETROOM_HPP
#define CPP_RTYPE_PACKETROOM_HPP

#include "Room.hpp"

class PacketRoom: IPacket
{
  private:
    Room	_room;
  public:
    PacketRoom();
    PacketRoom(const PacketRoom&);
    virtual ~PacketRoom();
    PacketRoom &operator=(const PacketRoom&);
};

#endif //CPP_RTYPE_PACKETROOM_HPP
