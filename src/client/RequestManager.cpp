//
// Created by arthaox on 17/01/18.
//

#include <common/network/packets/PacketEnemies.hpp>
#include "client/RequestManager.hpp"

RequestManager::RequestManager()
{
   this->_manager[Network::Packet::PacketType::PACKET_ENEMIES] = std::bind(&RequestManager::handlePacketEnemies, this, std::placeholders::_1, std::placeholders::_2);
}

RequestManager::~RequestManager()
{
}

void	RequestManager::handleRequest(Network::Packet::APacket *packet, GameRenderer &gr)
{
    for (auto handler : this->_manager)
    {
        if (handler.first == packet->getType())
        {
            handler.second(packet, gr);
            return;
        }
    }
}

void    RequestManager::handlePacketEnemies(Network::Packet::APacket *packet, GameRenderer &gr)
{
    auto    pEnemies = static_cast<Network::Packet::PacketEnemies *>(packet);

    std::cout << "-- Received UpdatePacketEnemies request" << std::endl;
    for (auto &enemy : pEnemies->getEnemies())
    {
        std::cout << "---- Enemy | id: " << enemy.getId() << " | hp: " << enemy.getHp();
        std::cout << " | pos: (" << enemy.getPosition().getX() << ", " << enemy.getPosition().getY() << std::endl;
        gr.addEnemies(enemy);
    }
}

