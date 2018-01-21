//
// Created by arthaox on 17/01/18.
//

#include "common/network/core/Serializer.hpp"
#include "client/EventManager.hpp"
#include "common/network/packets/PacketFire.hpp"
#include "common/network/packets/PacketMove.hpp"

EventManager::EventManager() = default;
EventManager::~EventManager() = default;

void EventManager::sendFire(Network::Core::UdpConnection &socketUdp,
                            const Player &player, const Network::Core::Endpoint &serverEndpoint)
{
    Network::Packet::PacketFire     packetFire(player);
    const std::string               serPacket = Serializer::serialize(packetFire);
    std::cout << "-- sendFire()" << std::endl;
    socketUdp.async_write(serPacket, Network::Packet::PACKET_ENEMIES, serverEndpoint,
                          [&](const boost::system::error_code &e, const long unsigned int&)
                          {
                              std::cout << "----- Player " << player.getId() << " has fired";
                          });
}

void EventManager::sendMove(Network::Core::UdpConnection &socketUdp,
                            const Player &player, const Network::Core::Endpoint &serverEndpoint)
{
    Network::Packet::PacketMove     packetMove(player);
    const std::string               serPacket = Serializer::serialize(packetMove);
    std::cout << "-- sendMove()" << std::endl;
    socketUdp.async_write(serPacket, Network::Packet::PACKET_ENEMIES, serverEndpoint,
                          [&](const boost::system::error_code &e, const long unsigned int&)
                          {
                              std::cout << "----- Player " << player.getId() << " has fired";
                          });
}