#include <iostream>
#include <Player.hpp>
#include <GameManager.hpp>
#include "ServerCore.hpp"

int main()
{
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
    gameManager.dumpEnnemy();
    boost::asio::io_service     service;
    ServerCore                  server(service, Network::Core::Endpoint(4244));


    server.start();
    service.run();
    return 0;
}