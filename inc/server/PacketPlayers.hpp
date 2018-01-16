//
// Created by arthaox on 15/01/18.
//

#ifndef CPP_RTYPE_PACKETPLAYERS_HPP
#define CPP_RTYPE_PACKETPLAYERS_HPP

/*#include "Player.hpp"*/

#include <vector>

class PacketPlayers: IPacket
{
  private:
    std::vector<Player>		_Players;
  public:
    PacketPlayers();
    PacketPlayers(const PacketPlayers&);
    virtual PacketPlayers();
    PacketPlayers &operator=(const PacketPlayers&);
};

#endif //CPP_RTYPE_PACKETPLAYERS_HPP
