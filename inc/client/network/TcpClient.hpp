//
// Created by Julien Pretet on 19/01/2018.
//

#ifndef CPP_RTYPE_TCPCLIENT_HPP_
#define CPP_RTYPE_TCPCLIENT_HPP_

#include	<boost/asio.hpp>
#include	<thread>
#include	"TcpClientConnections.hpp"
#include	"MenuState.hpp"
#include	<boost/bind.hpp>

class TcpClient
{
private:
  boost::asio::io_service _io_service;
  MenuState		&_state;
  TcpClientConnections::ptr _connection;

  void	connect(boost::asio::ip::tcp::endpoint &);
  void	handleConnect(TcpClientConnections::ptr, const boost::system::error_code&);
  std::thread _thread;
  void run();
public:
  TcpClient(boost::asio::ip::tcp::endpoint &, MenuState &);
  TcpClient(MenuState &);
  ~TcpClient();

  void start(MenuState &, boost::asio::ip::tcp::endpoint &);
  void disconnect();
  bool isConnected();

};


#endif /* !CPP_RTYPE_TCPCLIENT_HPP_ */
