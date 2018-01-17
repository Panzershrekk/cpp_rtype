//
// Created by arthaox on 15/01/18.
//

#include "../../../inc/server/PacketRooms.hpp"

PacketRooms::PacketRooms()
{

}

PacketRooms::PacketRooms(const PacketRooms& obj)
{
  this->_room = obj._room;
}

PacketRooms& PacketRooms::operator=(const PacketRooms& obj)
{
  this->_room = obj._room;
  return (*this);
}

PacketRooms::~PacketRooms()
{

}