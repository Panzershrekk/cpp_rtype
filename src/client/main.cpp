
#include "client/ClientCore.hpp"

int main(int argc, char **argv)
{
    boost::asio::io_service     service;
    ClientCore                  core(service);

    core.start();
    return 0;
}