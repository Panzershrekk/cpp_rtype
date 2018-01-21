
#include "client/ClientCore.hpp"

int main()
{
    boost::asio::io_service     service;
    ClientCore                  core(service);

    core.start();
    return 0;
}