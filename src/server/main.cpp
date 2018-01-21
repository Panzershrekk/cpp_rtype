#include <iostream>
#include "server/GameManager.hpp"
#include "server/ServerCore.hpp"
#include "TcpServer.hpp"

int main(int argc, char **argv)
{
    unsigned short      port = 0;

    if (argc != 2)
    {
        std::cerr << "Error: You have to provide a valid port as param" << std::endl;
        return (1);
    }
    std::string         arg1(argv[1]);
    std::istringstream  is(arg1);
    is >> port;
    if (port == 0)
    {
        std::cerr << "Error: Invalid port has been provided" << std::endl;
        return (1);
    }
    try
    {
        boost::asio::io_service     service;
        TcpServer                   socketTcp(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), 4242));
        ServerCore                  server(service, Network::Core::Endpoint(port));

        server.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return 0;
}