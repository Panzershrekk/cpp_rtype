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
  std::thread readThread(&ServerPrompt::readCommand, this);

  std::cout << "-- Welcome on the server's prompt --" << std::endl;
  std::cout << "Commands: getRooms and getPlayers." << std::endl;
  readThread.join();
}

void	ServerPrompt::readCommand()
{
  std::string input_command;

  for (input_command; std::getline(std::cin, input_command);)
  {
      std::cout << "Command: " << input_command << std::endl;
   // this->_manager->executeCommand(input_command, _server.getVectorRooms())
  }
}