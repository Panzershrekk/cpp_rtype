//
// Created by arthaox on 17/01/18.
//

#include "common/network/packets/PacketEnemies.hpp"
#include "common/network/core/Serializer.hpp"
#include "server/EventManager.hpp"
#

EventManager::EventManager() = default;
EventManager::~EventManager() = default;

void    EventManager::RefreshEnemies(Network::Core::UdpConnection &socketUdp,
                                  const GameManager &gm)
{
    Network::Packet::PacketEnemies  packetEnemies(gm.getEnemies());
    const std::string               serPacket = Serializer::serialize(packetEnemies);
    for (const auto &player : gm.getPlayers())
    {
        std::cout << "SEND ENEMIES LIST TO PLAYER (" << player.getId() << ")";
        socketUdp.async_write(serPacket, Network::Packet::PACKET_ENEMIES, player.getEndpoint(),
                              [&](const boost::system::error_code &e, const long unsigned int&)
                              {
                                  std::cout << "-- PACKET ENVOYE AU PLAYER" << std::endl;
                                  std::cout << "----- ID" << player.getId() << std::endl;
                                  std::cout << "----- IP" << player.getEndpoint().getIp() << std::endl;
                                  std::cout << "----- PORT" << player.getEndpoint().getPort() << std::endl;
                              });
    }
}
