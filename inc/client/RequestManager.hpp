//
// Created by arthaox on 17/01/18.
//

#ifndef     _REQUEST_MANAGER__HPP_
# define    _REQUEST_MANAGER__HPP_
# include <map>
# include <functional>
# include <unordered_map>
# include "common/network/packets/APacket.hpp"
# include "GameRenderer.hpp"

class RequestManager
{
private:
    std::unordered_map<Network::Packet::PacketType, std::function<void (Network::Packet::APacket *, GameRenderer &)>>	_manager;

public:
    RequestManager();
    virtual ~RequestManager();

    // HANDLE PACKET
    void	handleRequest(Network::Packet::APacket *, GameRenderer &);
    void    handlePacketEnemies(Network::Packet::APacket *, GameRenderer &);

};

#endif      /* _REQUEST_MANAGER__HPP_ */
