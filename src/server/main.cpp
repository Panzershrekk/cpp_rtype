#include <iostream>
#include <server/GameManager.hpp>
#include "TcpServer.hpp"

int main()
{
  /*boost::asio::io_service	service;

  try
  {
    TcpServer server(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), 4242));
    service.run();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;*/
  GameManager gameManager;

  Player player("Noobdu59");
  Player player1("XXX_PUSSY_DESTROYER_XXX");
  Player player2("Johnny la classe");
  Player player3("G@MER");

  gameManager.addPlayer(player);
  gameManager.addPlayer(player1);
  gameManager.addPlayer(player2);
  gameManager.addPlayer(player3);

  gameManager.dumpPlayer();
  gameManager.spawnEnnemy();
  gameManager.spawnEnnemy();
  gameManager.update();
  return (0);
}