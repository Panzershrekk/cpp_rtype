//
// Created by arthaox on 15/01/18.
//

#include "../../../inc/server/PacketPlayers.hpp"

PacketPlayers::PacketPlayers()
{
}

PacketPlayers::PacketPlayers(const PacketPlayers &obj)
{
  this->_Players = obj._Players;
}

PacketPlayers& PacketPlayers::operator=(const PacketPlayers &obj)
{
  this->_Players = obj._Players;
  return (*this);
}