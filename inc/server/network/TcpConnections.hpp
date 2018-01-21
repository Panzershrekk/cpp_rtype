//
// Created by Julien Pretet on 17/01/2018.
//

#ifndef CPP_RTYPE_TCPCONNECTIONS_H_
#define CPP_RTYPE_TCPCONNECTIONS_H_


#include	<boost/asio.hpp>
#include	<memory>
#include	<iostream>
#include	<boost/array.hpp>

class TcpConnections : public std::enable_shared_from_this<TcpConnections>
{
private:
  boost::array<char, 128>		m_buffer;
  boost::asio::ip::tcp::socket		_socket;

  void handleData();

public:
  explicit TcpConnections(boost::asio::io_service&);
  ~TcpConnections();
  typedef std::shared_ptr<TcpConnections> connectorPtr;

  void	start();
  static connectorPtr create(boost::asio::io_service&);
  boost::asio::ip::tcp::socket &getSocket();
  void	asyncWrite(std::string&);
  void	asyncRead(const boost::system::error_code&);
  void	doRead();


};



#endif /* !CPP_RTYPE_TCPCONNECTIONS_H_ */
