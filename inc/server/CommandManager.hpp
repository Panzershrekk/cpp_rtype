//
// Created by arthaox on 11/01/18.
//

#ifndef _COMMANDMANAGER_HPP_
#define _COMMANDMANAGER_HPP_

#include "Room.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>

class CommandManager
{
  private:
     std::unordered_map<std::string, std::function<void(const std::vector<Room>&)>>	_manager;
  public:
    CommandManager();
    virtual ~CommandManager();

    void    executeCommand(std::string funcName, std::vector<Room>&);
    void	getRooms(const std::vector<Room>&);
    void	getPlayers(const std::vector<Room>&);
};

#endif //_COMMANDMANAGER_HPP_
