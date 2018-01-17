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
#include <map>

class CommandManager
{
  private:
    // std::map<std::string, std::function<void(T)>>	_manager;
  public:
    CommandManager();
    virtual ~CommandManager();

    /*
    template <typename T>
    void				executeCommand(std::string, T);

    template <typename T>
    void				getRooms(T);

    template <typename T>
    void				getPlayers(T);
     */
};

#endif //CPP_RTYPE_COMMANDMANAGER_HPP
