//
// Created by Julien Pretet on 17/01/2018.
//

#include	"TcpServer.hpp"

TcpServer::TcpServer(boost::asio::io_service & io_service,
		     const boost::asio::ip::tcp::endpoint &endpoint) :
  _acceptor(io_service, endpoint), _io_service(io_service)
{
  waitForConnection();
}

void TcpServer::waitForConnection()
{
  std::cout << "Waiting for client" << std::endl;
  TcpConnections::connectorPtr newConnection = TcpConnections::create(_acceptor.get_io_service());

  _acceptor.async_accept(newConnection->getSocket(),
			 std::bind(&TcpServer::handleAccept, this , std::placeholders::_1, newConnection));
}

void TcpServer::handleAccept(const boost::system::error_code& error, TcpConnections::connectorPtr &connector)
{
  std::cout << "New client" << std::endl;
  if (!error)
    connector->start();
  waitForConnection();
}

