#include <iostream>
#include "server/GameManager.hpp"
#include "server/ServerCore.hpp"
#include "TcpServer.hpp"

int main()
{
  /*boost::asio::io_service	service;

  try
  {
    TcpServer server(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), 4242));
    service.run();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;*/
  boost::asio::io_service     service;
  ServerCore                  server(service, Network::Core::Endpoint(4242));

  server.start();
  return 0;
}