//
// Created by Julien Pretet on 19/01/2018.
//

#ifndef CPP_RTYPE_TCPCLIENT_HPP_
#define CPP_RTYPE_TCPCLIENT_HPP_

#include	<boost/asio.hpp>
#include	<thread>
#include	"TcpClientConnections.hpp"

class TcpClient
{
private:
  boost::asio::io_service &_io_service;

  void	connect(boost::asio::ip::tcp::endpoint &);
  void	handleConnect(TcpClientConnections::ptr);
  std::thread _thread;
  void run();
public:
  TcpClient(boost::asio::io_service &, boost::asio::ip::tcp::endpoint &);
  ~TcpClient();

};


#endif /* !CPP_RTYPE_TCPCLIENT_HPP_ */
