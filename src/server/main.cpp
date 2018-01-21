#include <iostream>
#include "server/GameManager.hpp"
#include "server/ServerCore.hpp"
#include "TcpServer.hpp"

int main()
{
    try
    {
        boost::asio::io_service     service;
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