//
// Created by arthaox on 17/01/18.
//

/*
#include "server/RequestManager.hpp"

RequestManager::RequestManager()
{
    this->_manager.emplace(std::make_pair(Network::Packet::PacketType::PACKET_FIRE, std::bind(&RequestManager::handleFireRequest, this, std::placeholders::_1, std::placeholders::_1)));
    this->_manager.emplace(std::make_pair(Network::Packet::PacketType::PACKET_MOVE, std::bind(&RequestManager::handleMoveRequest, this, std::placeholders::_1, std::placeholders::_2)));
}

RequestManager::~RequestManager()
{
}

void	RequestManager::handleRequest(const Network::Packet::APacket &, GameManager &)
{
    for (auto handler : this->_manager)
    {
        // TODO : Guillaume
    }
}

void	RequestManager::handleFireRequest(const Network::Packet::APacket &, GameManager &)
{
}

void	RequestManager::handleMoveRequest(const Network::Packet::APacket &, GameManager &)
{
}
 */