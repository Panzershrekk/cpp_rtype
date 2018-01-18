//
// Created by Julien Pretet on 18/01/2018.
//

#include "TcpHandler.hpp"

TcpHandler::TcpHandler(TcpConnections::connectorPtr &connector) : _connector(connector) {

}

void TcpHandler::waitForData()
{
 /* _connector->asyncRead(
			std::bind(&TcpHandler::handleRead,
			shared_from_this(), boost::asio::placeholders::error));
 //_connector->async_read(_connector->getSocket(),boost::asio::buffer(toto),
 //std::bind(&TcpHandler::handleRead, shared_from_this(), std::placeholders::_1));*/
  
}

void TcpHandler::handleWrite()
{

}

void TcpHandler::handleRead(const boost::system::error_code& error)
{
  if (!error)
    std::cout << _nData << std::endl;
}
