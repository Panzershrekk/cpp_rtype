//
// Created by Julien Pretet on 17/01/2018.
//

#include	"TcpConnections.hpp"

TcpConnections::TcpConnections(boost::asio::io_service &io_service) : _socket(io_service)
{

}

TcpConnections::~TcpConnections() = default;


void TcpConnections::start()
{
  std::string welcome = "Welcome!	";
  asyncWrite(welcome);
}

boost::asio::ip::tcp::socket &TcpConnections::getSocket()
{
  return _socket;
}

TcpConnections::connectorPtr TcpConnections::create(boost::asio::io_service &io_service)
{
  return connectorPtr(new TcpConnections(io_service));
}

void TcpConnections::asyncWrite(std::string &buff)
{
  boost::asio::async_write(_socket, boost::asio::buffer(buff),
			   std::bind(&TcpConnections::doRead, shared_from_this()));
}

void TcpConnections::asyncRead(const boost::system::error_code& error)
{
  if (!error)
   {
     std::cout << m_buffer.data() << std::endl;
     doRead();
   }
  else
     std::cout << error.message() << std::endl;
}

void	TcpConnections::doRead()
{
  boost::asio::async_read(_socket, boost::asio::buffer(m_buffer),
			  boost::asio::transfer_at_least(1),
			  std::bind(&TcpConnections::asyncRead,
				    shared_from_this(), std::placeholders::_1));
}

void TcpConnections::handleData()
{
  std::string tmp(m_buffer.data());
}
