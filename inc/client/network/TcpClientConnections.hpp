//
// Created by Julien Pretet on 19/01/2018.
//

#ifndef CPP_RTYPE_TCPCLIENTCONNECTIONS_HPP_
#define CPP_RTYPE_TCPCLIENTCONNECTIONS_HPP_


#include	<memory>
#include	<boost/asio.hpp>
#include	<boost/array.hpp>
#include	<functional>
#include	<iostream>

class IMenu;

class TcpClientConnections : public std::enable_shared_from_this<TcpClientConnections>
{
private:
  TcpClientConnections(boost::asio::io_service&);
  void handle_read(const boost::system::error_code& , size_t);
  void handleWrite(const boost::system::error_code&, std::size_t);
  boost::array<char, 128>				_network_buffer;
  boost::asio::ip::tcp::socket				_socket;
  std::vector<std::shared_ptr<IMenu>>	_vecMenu;

public:
  typedef std::shared_ptr<TcpClientConnections> ptr;
  void write(const std::string &);
  static ptr create(boost::asio::io_service& ios, std::vector<std::shared_ptr<IMenu>>&)
  {
    return ptr(new TcpClientConnections(ios));
  }
  boost::asio::ip::tcp::socket& getSocket();

  void setMenu(std::vector<std::shared_ptr<IMenu>>&);
  void read();
  std::vector<std::shared_ptr<IMenu>>& getVecMenu();
};


#endif /* !CPP_RTYPE_TCPCLIENTCONNECTIONS_HPP_ */
