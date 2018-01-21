//
// Created by arthaox on 17/01/18.
//

#include "common/network/packets/PacketFire.hpp"
#include "common/network/packets/PacketMove.hpp"
#include "server/RequestManager.hpp"

RequestManager::RequestManager()
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
    for (const auto &player : gm.getPlayers())
    {
        if (player.getEndpoint() == endpoint)
            return;
    }
    for (auto &player : gm.getPlayers())
    {
        if (player.getId() == 1234)
            player.setEndpoint(endpoint);
    }
}

/**
 *
 * @param packet
 * @param gm
 */
void	RequestManager::handleRequest(Network::Packet::APacket *packet, GameManager &gm)
{
    for (auto handler : this->_manager)
    {
        if (handler.first == packet->getType())
        {
            handler.second(packet, gm);
            return;
        }
    }
}

void	RequestManager::handleFireRequest(Network::Packet::APacket *packet, GameManager &gm)
{
    auto    pFire = static_cast<Network::Packet::PacketFire *>(packet);

    std::cout << "-- Received PacketFire request" << std::endl;
    std::cout << "---- Player who fire | id: " << pFire->getPlayer().getId() << " | hp: " << pFire->getPlayer().getHp();
    std::cout << " | pos: (" << pFire->getPlayer().getPosition().getX() << ", " << pFire->getPlayer().getPosition().getY() << std::endl;
    gm.createProjectile(pFire->getPlayer());
}

void	RequestManager::handleMoveRequest(Network::Packet::APacket *packet, GameManager &)
{
    const auto    pMove = static_cast<const Network::Packet::PacketMove *>(packet);

}