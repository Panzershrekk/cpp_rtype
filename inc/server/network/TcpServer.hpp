//
// Created by Julien Pretet on 17/01/2018.
//

#ifndef CPP_RTYPE_TCPSERVER_HPP_
#define CPP_RTYPE_TCPSERVER_HPP_

#include	<boost/asio.hpp>
#include	<iostream>
#include	"TcpConnections.hpp"
#include	"TcpHandler.hpp"
#include	<vector>
#include	"Player.hpp"

class TcpServer
{

public:
  explicit TcpServer(boost::asio::io_service &, const boost::asio::ip::tcp::endpoint &);
  ~TcpServer() = default;

private:
  boost::asio::ip::tcp::acceptor	_acceptor;
  boost::asio::io_service&		_io_service;

  void waitForConnection();
  void handleAccept(const boost::system::error_code&, TcpConnections::connectorPtr &);
};

#endif /* !CPP_RTYPE_TCPSERVER_HPP_ */
