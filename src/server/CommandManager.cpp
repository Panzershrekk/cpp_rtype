//
// Created by arthaox on 11/01/18.
//

#include <server/CommandManager.hpp>

CommandManager::CommandManager()
{
    this->_manager.emplace(std::make_pair("getRooms", std::bind(&CommandManager::getRooms, this, std::placeholders::_1 )));
    this->_manager.emplace(std::make_pair("getPlayers", std::bind(&CommandManager::getPlayers, this, std::placeholders::_1 )));
}

CommandManager::~CommandManager() {}

void CommandManager::executeCommand(std::string funcName, std::vector<Room> &rooms)
{
    return (this->_manager[funcName](rooms));
}

void CommandManager::getRooms(const std::vector<Room> &rooms)
{
    std::cout << "List of Rooms:" << std::endl;
    for (auto &it : rooms)
    {
        std::cout << "Room id :" << it.getId() << std::endl;
    }
}

void CommandManager::getPlayers(const std::vector<Room>& rooms)
{
    for (auto &it : rooms)
    {
        std::cout << "ROOM id: " << it.getId() << std::endl;
        for (auto &it2 : it.getPlayers()) {
            std::cout << it2.getName() << std::endl;
        }
    }
}