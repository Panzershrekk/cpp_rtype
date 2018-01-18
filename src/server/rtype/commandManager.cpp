//
// Created by arthaox on 11/01/18.
//

#include "commandManager.hpp"

CommandManager::CommandManager()
{
    // this->_manager["getRooms"] = std::bind(&Component::getRooms, std::placeholders::_1);
    // this->_manager["getPlayers"] = std::bind(&Component::getPlayers, std::placeholders::_1);
}

CommandManager::~CommandManager() {}

/*
void	commandManager::executeCommand(const std::string &funcName, T obj)
{
  return (this->_manager[funcName](obj));
}

void	commandManager::getPlayers(T obj)
{
  std::cout << obj << std::endl;
}

void	commandManager::getRooms(T obj)
{
  std::cout << obj << std::endl;
}
*/