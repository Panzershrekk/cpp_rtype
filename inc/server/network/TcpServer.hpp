//
// Created by Julien Pretet on 17/01/2018.
//

#ifndef CPP_RTYPE_TCPSERVER_HPP_
#define CPP_RTYPE_TCPSERVER_HPP_

#include <boost/asio.hpp>


class TcpServer
{

  explicit TcpServer();
  ~TcpServer() = default;

private:
  boost::asio::ip::tcp::acceptor _acceptor;


  void startAccept();
  void handleAccept();
public:
};


#endif /* !CPP_RTYPE_TCPSERVER_HPP_ */
