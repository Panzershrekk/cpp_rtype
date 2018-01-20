//
// Created by Julien Pretet on 19/01/2018.
//

#include "TcpClientConnections.hpp"
#include "MenuWindow.hpp"

boost::array<char, 128> my_buffer;


TcpClientConnections::TcpClientConnections(boost::asio::io_service &service): _socket(service)
{

}

boost::asio::ip::tcp::socket& TcpClientConnections::getSocket()
{
  return _socket;
}

void TcpClientConnections::read()
{
  //auto f_static = std::bind((int(*)(int, int, int))&Foo::foo_static, 1, 2, 3);

  boost::asio::async_read(_socket, boost::asio::buffer(_network_buffer),
			  boost::asio::transfer_at_least(1),
			  std::bind(&TcpClientConnections::handle_read, shared_from_this(),
				    std::placeholders::_1 ,
				    std::placeholders::_2));
			 /* boost::bind((void(*)(const boost::system::error_code& ,
  					size_t ,
  boost::array<char, 128> ))
			    &MenuWindow::handleData,
  				std::placeholders::_1 ,
				      std::placeholders::_2,
				    std::placeholders::_3)
    std::bind(&MenuWindow::handleData,std::placeholders::_1 ,
	      std::placeholders::_2)
  );*/
}

void TcpClientConnections::handle_read(const boost::system::error_code& error, size_t number_bytes_read)
{
  if (!error)
  {
    std::cout << _network_buffer.data() << std::endl;
    std::string test(_network_buffer.data());
    if (test == "200:Welcome!\n")
    {
      this->write(std::static_pointer_cast<LoginMenu>(this->_vecMenu.at(1))->getName());
      std::cout << "slt" << std::endl;
      this->write("hello serveur");
    }
    if (test.find("200:Room:") != std::string::npos)
    {
      int nbRooms = test.at(test.size() - 2);
      std::static_pointer_cast<RoomListMenu>(this->_vecMenu.at(2))->genRooms(nbRooms);
      this->write("200:join_room:" + std::static_pointer_cast<RoomListMenu>(this->_vecMenu.at(2))->getWhichRoom());
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
{/* boost::asio::async_write(_socket, str,
			   boost::bind(&TcpClientConnections::handleWrite,
				       this));
  boost::asio::async_write(_socket)*/
}

