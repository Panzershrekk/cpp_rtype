#include <iostream>
#include "TcpServer.hpp"

int main()
{
  boost::asio::io_service	service;

  try
  {
    TcpServer server(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), 4242));
    service.run();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}