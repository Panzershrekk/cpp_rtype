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
    for (size_t n = 0; n < rooms.size(); n++)
        std::cout << rooms[n].getId() << std::endl;
}

void CommandManager::getPlayers(const std::vector<Room>& rooms)
{
    for (size_t n = 0; n < rooms.size(); n++) {
        std::cout << "Room's name : " << rooms[n].getId() << std::endl;
/*        for (size_t i = 0; i < rooms[n].getPlayer().size(); i++)
            std::cout << rooms[n].getPlayer()[i] << std::endl;
TODO we need a getPlayer() method in room
*/
    }
}