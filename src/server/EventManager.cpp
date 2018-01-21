//
// Created by arthaox on 17/01/18.
//

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

void    EventManager::RefreshProjectile(Network::Core::UdpConnection &socketUdp, GameManager &gm)
{
   /* Network::Packet::PacketFire  packetFire(gm.getPlayers().front()); // TODO PLAYER
    const std::string            serPacket = Serializer::serialize(packetFire);
    std::cout << "-- RefreshProjectile" << std::endl;
    for (auto &player : gm.getPlayers())
    {
        socketUdp.async_write(serPacket, Network::Packet::PACKET_ENEMIES, player.getEndpoint(),
                              [&](const boost::system::error_code &e, const long unsigned int&)
                              {
                                  std::cout << "----- Player | id: " << player.getId();
                                  std::cout << " | endpoint: " << player.getEndpoint().getIp() << ":";
                                  std::cout << player.getEndpoint().getPort() << std::endl;
                              });
    } */
}
