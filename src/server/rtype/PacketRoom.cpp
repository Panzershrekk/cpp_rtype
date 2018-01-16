//
// Created by arthaox on 15/01/18.
//

#include "../../../inc/server/PacketRoom.hpp"

PacketRoom::PacketRoom()
{

}

PacketRoom::PacketRoom(const PacketRoom& obj)
{
  this->_room = obj._room;
}

PacketRoom& PacketRoom::operator=(const PacketRoom& obj)
{
  this->_room = obj._room;
  return (*this);
}

PacketRoom::~PacketRoom()
{

}