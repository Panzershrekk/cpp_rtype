#include <SFML/Graphics.hpp>
#include <iostream>
#include <Window.hpp>
#include <boost/asio.hpp>
#include "game/GameRenderer.hpp"
#include "common/network/packets/PacketPlayer.hpp"
#include "common/network/core/UdpConnection.hpp"

int main()
{
    /*GameRenderer gameRenderer;
    gameRenderer.startGame(); */
    boost::asio::io_service         service;
    Network::Core::UdpConnection    socket(service);
    Player                          player;
    player.setName("Guillaume");
    player.setHp(42);
    player.setScore(0);
    auto                           *packetPlayer = new Network::Packet::PacketPlayer(player);
    packetPlayer->getPlayer().setName("GUillaume LE vainqueur du UDP !");

    std::cout << packetPlayer->getPlayer().getName() << std::endl;
    Network::Packet::APacket       *packet;
    packet = packetPlayer;
    std::string                     packetSerialized = Serializer::serialize(*packetPlayer);

    socket.openV4();
    socket.async_write(packetSerialized, Network::Core::Endpoint("127.0.0.1", 4244),
                       [&](const boost::system::error_code &e, const long unsigned int&)
                       {
                           std::cout << "-- Packet has been sent" << std::endl;
                       });
    service.run();
    return 0;
}