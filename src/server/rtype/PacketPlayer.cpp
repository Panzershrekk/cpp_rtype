//
// Created by arthaox on 15/01/18.
//

#include "../../../inc/server/PacketPlayer.hpp"

PacketPlayer::PacketPlayer()
{
}

PacketPlayer::PacketPlayer(const PacketPlayer &obj)
{
  this->_Player = obj._Player;
}

PacketPlayer& PacketPlayer::operator=(const PacketPlayer &obj)
{
  this->_Player = obj._Player;
  return (*this);
}