#include "client/game/GameRenderer.hpp"
#include "MenuWindow.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Window.hpp>
#include <boost/asio.hpp>
#include "common/network/packets/PacketPlayer.hpp"
#include "common/network/core/UdpConnection.hpp"

int main()
{
   // GameRenderer gameRenderer;
   // gameRenderer.startGame();

  MenuWindow menu;

  menu.start();
   /* boost::asio::io_service         service;
    Network::Core::UdpConnection    socket(service);
    Player                          player;
    Network::Core::Endpoint         ep("127.0.0.1", 4244);
    player.setName("Guillaume");
    player.setHp(42);
    player.setScore(0);
    Network::Packet::PacketPlayer   packetPlayer;
    packetPlayer.getPlayer().setName("GUillaume LE vainqueur du UDP !");

    std::cout << packetPlayer.getPlayer().getName() << std::endl;
    std::string                     packetSerialized = Serializer::serialize(packetPlayer);

    socket.openV4();

    socket.async_write(packetSerialized, packetPlayer.getType(), ep,
                       [&](const boost::system::error_code &e, const long unsigned int&)
                       {
                           std::cout << "-- Packet has been sent" << std::endl;
                       });
    service.run();*/
    return 0;
}