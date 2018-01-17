#include <SFML/Graphics.hpp>
#include <iostream>
#include <Window.hpp>
#include <boost/asio.hpp>
#include "game/GameRenderer.hpp"
#include "common/network/packets/PacketPlayer.hpp"
#include "common/network/core/UdpConnection.hpp"

int main()
{
    GameRenderer gameRenderer;
    gameRenderer.startGame();
    boost::asio::io_service         service;
    Network::Core::UdpConnection    socket(service);
    Player                          player;
    player.setName("Guillaume");
    player.setHp(42);
    player.setScore(0);
    Network::Packet::PacketPlayer   packetPlayer(player);

    socket.openV4();
    socket.async_write(packetPlayer, Network::Core::Endpoint("127.0.0.1", 4242),
                       [](const boost::system::error_code &e, const long unsigned int&)
                       {
                           std::cout << "-- Packet has been sent" << std::endl;
                       });
    return 0;
}