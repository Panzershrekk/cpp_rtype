//
// Created by arthaox on 15/01/18.
//

#ifndef CPP_RTYPE_PACKETROOMS_HPP
#define CPP_RTYPE_PACKETROOMS_HPP

#include "Room.hpp"

#include <vector>

class PacketRooms: IPacket
{
  private:
    std::vector<Room>	_rooms;
  public:
    PacketRooms();
    virtual ~PacketRooms();
    PacketRooms(const PacketRooms&);
    PacketRooms &operator=(const PacketRooms&);
};

#endif //CPP_RTYPE_PACKETROOMS_HPP
