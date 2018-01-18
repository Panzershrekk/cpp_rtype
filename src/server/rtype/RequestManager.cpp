//
// Created by arthaox on 17/01/18.
//

#include "../../../inc/server/RequestManager.hpp"

RequestManager::RequestManager()
{
 /* this->_manager["Request"] = std::bind(&Component::handleRequest, std::placeholders::_1);
  this->_manager["Connection"] = std::bind(&Component::handleConnection, std::placeholders::_1);
  this->_manager["Fire"] = std::bind(&Component::handleFireRequest, std::placeholders::_1);
  this->_manager["Join"] = std::bind(&Component::handleJoin, std::placeholders::_1);
  this->_manager["Move"] = std::bind(&Component::handleMoveRequest, std::placeholders::_1);
  this->_manager["Ready"] = std::bind(&Component::handleReady, std::placeholders::_1);*/
}

RequestManager::~RequestManager()
{
}

void	RequestManager::CheckPacket(Packet &p)
{
  return (this->_manager[p->_type]());
}

void	RequestManager::handleRequest(Request, Object &obj)
{
}

void	RequestManager::handleConnection(Object &obj)
{
}

void	RequestManager::handleFireRequest(Object &obj)
{
}

void	RequestManager::handleJoin(Object &obj)
{
}

void	RequestManager::handleMoveRequest(Object &obj)
{
}

void	RequestManager::handleReady(Object &obj)
{
}