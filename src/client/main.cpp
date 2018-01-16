#include <iostream>
#include <boost/asio.hpp>
#include "common/network/core/UdpConnection.hpp"
#include "common/network/core/Endpoint.hpp"
#include "common/network/serialization/PacketTest.hpp"

int main()
{
    boost::asio::io_service         service;
    Network::Core::UdpConnection    socket(service);
    Network::Packet::PacketTest     packet;

    socket.openV4();
    socket.send(packet, Network::Core::Endpoint("127.0.0.1", 4242));
    return 0;
}