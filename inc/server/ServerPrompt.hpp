//
// Created by arthaox on 11/01/18.
//

#ifndef CPP_RTYPE_SERVERPROMPT_HPP
#define CPP_RTYPE_SERVERPROMPT_HPP

#include "CommandManager.hpp"

#include <string>
#include <iostream>
#include <thread>

class ServerPrompt
{
  private:
    // CommandManager<std::vector<Rooms>> *_manager;
    /*ServerCore *_server;*/
  public:
    ServerPrompt();
    ~ServerPrompt();

    void	startPrompt();
    void	readCommand();
};

#endif //CPP_RTYPE_SERVERPROMPT_HPP
