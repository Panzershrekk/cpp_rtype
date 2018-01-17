#include "SFML/Graphics.hpp"
#include <iostream>
#include <Window.hpp>
#include <game/GameRenderer.hpp>
#include "menu/MainMenu.hpp"
#include "Window.hpp"
#include <boost/asio.hpp>
#include "common/network/core/UdpConnection.hpp"
#include "common/network/core/Endpoint.hpp"

int main()
{
    GameRenderer gameRenderer;
    gameRenderer.startGame();
    boost::asio::io_service         service;
    Network::Core::UdpConnection    socket(service);
    int                             ss = 42;

    socket.openV4();
    std::cout << "-- Packet has been sent [" << ss << "]" << std::endl;
    socket.async_write(ss, Network::Core::Endpoint("127.0.0.1", 4242),
                       [](const boost::system::error_code &e, const long unsigned int&)
                       {
                       });
    return 0;
}