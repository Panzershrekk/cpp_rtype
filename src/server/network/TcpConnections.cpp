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
  std::string welcome = "200:Welcome!";
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

void TcpConnections::asyncWrite(const std::string &buff)
{
  boost::asio::async_write(_socket, boost::asio::buffer(buff),
			   std::bind(&TcpConnections::doRead, shared_from_this()));
}

void TcpConnections::asyncRead(const boost::system::error_code& error, size_t nbBytes)
{
  if (!error)
   {
     handleData(nbBytes);
     doRead();
   }
  else
     std::cout << "error = " << error.message() << std::endl;
}

void	TcpConnections::doRead()
{
  boost::asio::async_read(_socket, boost::asio::buffer(m_buffer),
			  boost::asio::transfer_at_least(1),
			  std::bind(&TcpConnections::asyncRead,
				    shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void TcpConnections::handleData(size_t nbBytes)
{
  std::cout << "nb bytes lu = " << nbBytes << std::endl;
  std::cout << "buff " << m_buffer.data() << std::endl;
  std::string tmp(m_buffer.data());
  tmp.resize(nbBytes);
  std::cout << tmp << std::endl;

  std::replace(tmp.begin(), tmp.end(), ':', ' ');  // replace ':' by ' '
  std::vector<std::string> array;
  std::stringstream ss(tmp);
  std::string temp;
  while (ss >> temp)
    array.push_back(temp);
  if (array[1] == "name")
  {
    std::cout << "Player new name is " << array[2] << std::endl;
    _player.setName(array[2]);
    asyncWrite("200:Room:");
  }
  if (tmp == "join_room:0")
  {
    roomList.at(0).join(_player);
    std::cout << "try to join room0";
    std::cout << "room size = " <<roomList.at(0).getSize() << std::endl;
  }
}
