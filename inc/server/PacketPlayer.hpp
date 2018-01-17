//
// Created by arthaox on 15/01/18.
//

#ifndef CPP_RTYPE_PACKETPLAYER_HPP
#define CPP_RTYPE_PACKETPLAYER_HPP

/*#include "Player.hpp"*/

class PacketPlayer: IPacket
{
  private:
    Player	_Player;
  public:
    PacketPlayer();
    PacketPlayer(const PacketPlayer&);
    virtual PacketPlayer();
    PacketPlayer &operator=(const PacketPlayer&);
};

#endif //CPP_RTYPE_PACKETPLAYER_HPP
