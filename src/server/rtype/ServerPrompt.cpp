//
// Created by arthaox on 11/01/18.
//

#include "../../../inc/server/ServerPrompt.hpp"

ServerPrompt::ServerPrompt()
{
  // this->_manager = new commandMannager();
 /* this->_server = new ServerCore();*/
}

ServerPrompt::~ServerPrompt()
{
}

void	ServerPrompt::startPrompt()
{
  // std::thread readThread(readCommand);

  std::cout << "-- Welcome on the server's prompt --" << std::endl;
  //std::cout << "List of Rooms: " << manager.getRooms() << std::endl;
  // std::cout << "List of Player: " << manager.getPlayers() << std::endl;
  std::cout << "Commands: getRooms and getPlayers." << std::endl;
  //readThread.join();
}

void	ServerPrompt::readCommand()
{
  std::string input_command;

  for (input_command; std::getline(std::cin, input_command);)
  {
   // this->_manager->executeCommand(input_command, _server.getVectorRooms())
  }
}