//
// Created by Julien Pretet on 18/01/2018.
//

#ifndef CPP_RTYPE_TCPHANDLER_HPP_
#define CPP_RTYPE_TCPHANDLER_HPP_

#include	<memory>
#include	<string>
#include	<iostream>
#include	"TcpConnections.hpp"

class TcpHandler;

typedef std::shared_ptr<TcpHandler>	TcpHandlerPtr;


class TcpHandler : public std::enable_shared_from_this<TcpHandler>
{
private:
  TcpConnections::connectorPtr	_connector;
  std::string _nData;

  TcpHandler(TcpConnections::connectorPtr &);
  void	waitForData();
  void handleWrite();
  void handleRead(const boost::system::error_code&);

public:
  explicit TcpHandler() = default;

  static TcpHandlerPtr create(TcpConnections::connectorPtr connector)
  {
    TcpHandlerPtr handler (new TcpHandler(connector));
    handler->waitForData();
    return (handler);
  }
};


#endif /* !CPP_RTYPE_TCPHANDLER_HPP_ */
