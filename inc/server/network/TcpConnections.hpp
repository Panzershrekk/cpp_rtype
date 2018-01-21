//
// Created by Julien Pretet on 17/01/2018.
//

#ifndef CPP_RTYPE_TCPCONNECTIONS_H_
#define CPP_RTYPE_TCPCONNECTIONS_H_


#include	<boost/asio.hpp>
#include	<memory>
#include	<iostream>
#include	<boost/array.hpp>
#include	"Player.hpp"
#include	"Room.hpp"
#include	"StringSplit.hpp"

extern std::vector<Room> roomList;

class TcpConnections : public std::enable_shared_from_this<TcpConnections>
{
private:
  boost::array<char, 128>		m_buffer;
  boost::asio::ip::tcp::socket		_socket;
  Player				_player;
  std::vector<Room>			roomList;
  StringSplit				_split;
  std::string				_buff;
  void handleData(size_t);

public:
  explicit TcpConnections(boost::asio::io_service&);
  ~TcpConnections();
  typedef std::shared_ptr<TcpConnections> connectorPtr;

  void	start();
  static connectorPtr create(boost::asio::io_service&);
  boost::asio::ip::tcp::socket &getSocket();
  void	asyncWrite(const std::string&);
  void	asyncRead(const boost::system::error_code&, size_t);
  void	doRead();


};



#endif /* !CPP_RTYPE_TCPCONNECTIONS_H_ */
