//
// Created by arthaox on 17/01/18.
//

#include "server/RequestManager.hpp"

RequestManager::RequestManager(const RtypeApp &type)
{
    this->_manager[Network::Packet::PacketType::PACKET_FIRE] = std::bind(&RequestManager::handleFireRequest, this, std::placeholders::_1, std::placeholders::_2);
    this->_manager[Network::Packet::PacketType::PACKET_MOVE] = std::bind(&RequestManager::handleMoveRequest, this, std::placeholders::_1, std::placeholders::_2);
}

RequestManager::~RequestManager()
{
}

/**
 * HANDLE CLIENT CONNECTION
 */
void    RequestManager::handleNewUdpClient(const Network::Core::Endpoint &endpoint, GameManager &gm)
{
    for (auto player : gm.getPlayers())
    {
        if (player.getEndpoint() == endpoint)
            return;
    }
    Player  newPlayer;
    newPlayer.setName("PLAYER");
    newPlayer.setEndpoint(endpoint);
    gm.addPlayer(newPlayer);

}


/**
 *
 * @param packet
 * @param gm
 */
void	RequestManager::handleRequest(const Network::Packet::APacket &packet, GameManager &gm)
{
    for (auto handler : this->_manager)
    {
        if (handler.first == packet.getType())
        {
            handler.second(packet, gm);
            return;
        }
    }
}

void	RequestManager::handleFireRequest(const Network::Packet::APacket &, GameManager &)
{
}

void	RequestManager::handleMoveRequest(const Network::Packet::APacket &, GameManager &)
{
}