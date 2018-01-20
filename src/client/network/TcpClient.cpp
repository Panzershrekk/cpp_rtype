//
// Created by Julien Pretet on 19/01/2018.
//

#include "network/TcpClient.hpp"


TcpClient::TcpClient(boost::asio::io_service & service,
		     boost::asio::ip::tcp::endpoint &endpoint) : _io_service(service)
{
  connect(endpoint);
 _thread = std::thread(std::bind(&TcpClient::run, this));
}

TcpClient::~TcpClient()
{

}

void TcpClient::connect(boost::asio::ip::tcp::endpoint &endpoint)
{
  std::cout << "connect" << std::endl;
  TcpClientConnections::ptr connection = TcpClientConnections::create(_io_service);
  boost::asio::ip::tcp::socket& socket = connection->getSocket();
 socket.async_connect(endpoint,
		       std::bind(&TcpClient::handleConnect, this, connection
				 ));
}

void TcpClient::handleConnect(TcpClientConnections::ptr connect)
{
  std::cout << "connected" << std::endl;
  connect->read();
}

void TcpClient::run()
{
  _io_service.run();
}




