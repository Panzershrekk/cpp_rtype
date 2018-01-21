//
// Created by Julien Pretet on 19/01/2018.
//

#include "network/TcpClient.hpp"


TcpClient::TcpClient(boost::asio::ip::tcp::endpoint &endpoint,
		     MenuState &state) :  _state(state)
{
  connect(endpoint);
  //_io_service.run();
  _thread = std::thread(std::bind(&TcpClient::run, this));
}

TcpClient::~TcpClient()
{
std::cout << "Destroy" << std::endl;
}

void TcpClient::connect(boost::asio::ip::tcp::endpoint &endpoint)
{
  std::cout << "async_connect" << std::endl;
  _connection = TcpClientConnections::create(_io_service, _vecMenu);
  boost::asio::ip::tcp::socket& socket = _connection->getSocket();
 socket.async_connect(endpoint,
		       boost::bind(&TcpClient::handleConnect, this, _connection, boost::asio::placeholders::error
				 ));
}

void TcpClient::handleConnect(TcpClientConnections::ptr connect, const boost::system::error_code& error)
{
  if (!error) {
    std::cout << "connected" << std::endl;
    connect->read();
    _state = ERoomListMenu;
  } else
  {
    std::cout << error.message() << std::endl;
  }
}

void TcpClient::run()
{
  _io_service.run();
}

TcpClient::TcpClient(MenuState & state) : _state(state)
{
}

void TcpClient::start(MenuState &state, boost::asio::ip::tcp::endpoint &endpoint)
{
  _state = state;
  connect(endpoint);
  _thread = std::thread(std::bind(&TcpClient::run, this));

}

void TcpClient::disconnect()
{
  if (_connection->getSocket().is_open())
    std::cout << "socket err" << std::endl;
  if (_connection != nullptr) {
    _connection->getSocket().close();
  }
  std::cout << "socket close" << std::endl;
}

bool TcpClient::isConnected()
{
  return (true);
  //std::cout << _connection->getSocket().is_open() << std::endl;
  //return _connection->getSocket().is_open();
}

void TcpClient::write(std::string &str)
{
  _connection->write(str);
}

void TcpClient::setMenu(std::vector<std::shared_ptr<IMenu>> *vecMenu)
{
  _vecMenu = *vecMenu;
  _menuSet = 1;
}

int TcpClient::getMenu()
{
 return _menuSet;
}




