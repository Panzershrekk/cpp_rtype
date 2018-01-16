#include "server/ServerCore.hpp"

int main()
{
    boost::asio::io_service     service;
    ServerCore                  server(service, Network::Core::Endpoint(4242));

    server.start();
    return 0;
}