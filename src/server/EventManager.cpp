//
// Created by arthaox on 17/01/18.
//

#include <common/network/packets/PacketProjectiles.hpp>
#include "common/network/packets/PacketEnemies.hpp"
#include "common/network/core/Serializer.hpp"
#include "server/EventManager.hpp"
#

EventManager::EventManager() = default;
EventManager::~EventManager() = default;

void    EventManager::RefreshEnemies(Network::Core::UdpConnection &socketUdp, GameManager &gm)
{
    Network::Packet::PacketEnemies  packetEnemies(gm.getEnemies());
    const std::string               serPacket = Serializer::serialize(packetEnemies);
    std::cout << "-- RefreshEnemies(size = " << packetEnemies.getEnemies().size() << ")" << std::endl;
    for (auto &player : gm.getPlayers())
    {
        socketUdp.async_write(serPacket, Network::Packet::PACKET_ENEMIES, player.getEndpoint(),
                              [&](const boost::system::error_code &e, const long unsigned int&)
                              {
                                  std::cout << "----- Player | id: " << player.getId();
                                  std::cout << " | endpoint: " << player.getEndpoint().getIp() << ":";
                                  std::cout << player.getEndpoint().getPort() << std::endl;
                              });
    }
}

void    EventManager::RefreshProjectiles(Network::Core::UdpConnection &socketUdp, GameManager &gm)
{
    Network::Packet::PacketProjectiles  packetProjectiles(gm.getProjectiles()); // TODO PLAYER
    const std::string                   serPacket = Serializer::serialize(packetProjectiles);
    std::cout << "-- RefreshProjectiles (size= " << packetProjectiles.getProjectiles().size() << ")" << std::endl;
    for (auto &player : gm.getPlayers())
    {
        socketUdp.async_write(serPacket, Network::Packet::PACKET_PROJECTILES, player.getEndpoint(),
                              [&](const boost::system::error_code &e, const long unsigned int&)
                              {
                                  std::cout << "----- Player | id: " << player.getId();
                                  std::cout << " | endpoint: " << player.getEndpoint().getIp() << ":";
                                  std::cout << player.getEndpoint().getPort() << std::endl;
                              });
    }
}
