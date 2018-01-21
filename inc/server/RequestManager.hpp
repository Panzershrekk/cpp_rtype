//
// Created by arthaox on 17/01/18.
//

#ifndef     _REQUEST_MANAGER__HPP_
# define    _REQUEST_MANAGER__HPP_
# include <map>
# include <functional>
# include <unordered_map>
# include "common/network/packets/APacket.hpp"
# include "GameManager.hpp"

class RequestManager
{
private:
    std::unordered_map<Network::Packet::PacketType, std::function<void (const Network::Packet::APacket *, GameManager &)>>	_manager;

public:
    RequestManager();
    ~RequestManager();

    // HANDLE CLIENT CONNECTION
    void    handleNewUdpClient(const Network::Core::Endpoint &, GameManager &);

    // HANDLE PACKET
    void	handleRequest(const Network::Packet::APacket *, GameManager &);
    void	handleFireRequest(const Network::Packet::APacket *, GameManager &);
    void	handleMoveRequest(const Network::Packet::APacket *, GameManager &);
};

#endif      /* _REQUEST_MANAGER__HPP_ */
