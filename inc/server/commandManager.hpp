//
// Created by arthaox on 11/01/18.
//

#ifndef CPP_RTYPE_COMMANDMANAGER_HPP
#define CPP_RTYPE_COMMANDMANAGER_HPP

#include "Room.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <functional>

template <typename T>
class commandManager
{
  private:
    std::map<std::string, std::function<void(T)>>	_manager;
  public:
    commandManager();
    virtual commandManager();

    void				executeCommand(std::string, T);
    void				getRooms(T);
    void				getPlayers(T);
};

#endif //CPP_RTYPE_COMMANDMANAGER_HPP
