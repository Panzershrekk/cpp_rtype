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
    std::cout << "NOMBRE D'ENEMIE DANS LE PAQUET : " << packetEnemies.getEnemies().size() << std::endl;
    const std::string               serPacket = Serializer::serialize(packetEnemies);

    Serializer      ser;
    auto    obj = ser.deserialize(serPacket, Network::Packet::PACKET_ENEMIES);
    Network::Packet::PacketEnemies  *pE;
    pE = static_cast<Network::Packet::PacketEnemies *>(obj);

    std::cout << "APRES DESER : " << pE->getEnemies().size() << std::endl;


    std::cout << "-- RefreshEnemies()" << std::endl;
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
