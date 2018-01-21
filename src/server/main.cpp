#include <iostream>
#include "server/GameManager.hpp"
#include "server/ServerCore.hpp"
#include "TcpServer.hpp"

int main()
{
    try
    {
        boost::asio::io_service     service;
        TcpServer                   socketTcp(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), 4242));
        ServerCore                  server(service, Network::Core::Endpoint(4242));

        server.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return 0;
}