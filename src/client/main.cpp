#include <GameRenderer.hpp>
/*#include <boost/asio.hpp>
#include "common/network/core/UdpConnection.hpp"
#include "common/network/core/Endpoint.hpp"*/

int main()
{
  GameRenderer gameRenderer;
  gameRenderer.startGame();
  return (0);
    /*boost::asio::io_service         service;
    Network::Core::UdpConnection    socket(service);
    std::stringstream               ss;

    ss << "Hello world !";
    socket.openV4();
    std::cout << "-- Packet has been sent [" << ss.str() << "]" << std::endl;
    socket.send(ss, Network::Core::Endpoint("127.0.0.1", 4242));
    socket.send(ss, Network::Core::Endpoint("127.0.0.1", 4242));
    socket.send(ss, Network::Core::Endpoint("127.0.0.1", 4242));
    socket.send(ss, Network::Core::Endpoint("127.0.0.1", 4242));
    return 0;*/
}