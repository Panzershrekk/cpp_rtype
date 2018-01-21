//
// Created by Julien Pretet on 19/01/2018.
//

#include "TcpClientConnections.hpp"
#include "MenuWindow.hpp"


TcpClientConnections::TcpClientConnections(boost::asio::io_service &service): _socket(service)
{
}

boost::asio::ip::tcp::socket& TcpClientConnections::getSocket()
{
  return _socket;
}

void TcpClientConnections::read()
{
  boost::asio::async_read(_socket, boost::asio::buffer(_network_buffer),
			  boost::asio::transfer_at_least(1),
			  std::bind(&TcpClientConnections::handle_read, shared_from_this(),
				    std::placeholders::_1 ,
				    std::placeholders::_2));
}

void TcpClientConnections::handle_read(const boost::system::error_code& error, size_t number_bytes_read)
{
  if (!error)
  {
    std::string test(_network_buffer.data());
    test.resize(number_bytes_read);
    std::cout << test << std::endl;
    if (test == "200:Room:")
    {
   //   int nbRooms = test.at(test.size() - 2);
      std::static_pointer_cast<RoomListMenu>(this->_vecMenu.at(2))->genRooms(1);
 //     this->write("200:join_room:" + std::static_pointer_cast<RoomListMenu>(this->_vecMenu.at(2))->getWhichRoom());
    }
    if (test.find("OK:") != std::string::npos)
    {
      this->write("ready!");
    }
    read();
  }
  else {
    std::cout << error.message();
  }
}

void TcpClientConnections::write(const std::string &str)
{
  std::cout << "my menu = " << _vecMenu.size() << std::endl;
  boost::asio::async_write(_socket, boost::asio::buffer(str.c_str(), str.size()),
			   boost::bind(&TcpClientConnections::handleWrite,
				       this,
				       boost::asio::placeholders::error,
				       boost::asio::placeholders::bytes_transferred
			   ));
}

void TcpClientConnections::handleWrite(const boost::system::error_code&error, std::size_t size)
{
  if (!error)
  {
    std::cout << "success" << std::endl;
  } else
    std::cerr << error.message() << std::endl;
}

void TcpClientConnections::setMenu(std::vector<std::shared_ptr<IMenu>> &menu)
{
  _vecMenu = menu;
  std::cout << "client co size = " << _vecMenu.size() << std::endl;
}

std::vector<std::shared_ptr<IMenu>>& TcpClientConnections::getVecMenu()
{
  return _vecMenu;
}
