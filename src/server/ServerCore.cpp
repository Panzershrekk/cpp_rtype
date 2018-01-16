/**
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 * Implementation of the ServerCore
 * @author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * @date January 10, 2018
 *
 */

#include <iostream>
#include "server/ServerCore.hpp"
#include "common/network/core/UdpConnection.hpp"
#include "common/network/core/Endpoint.hpp"
#include "common/network/serialization/APacket.hpp"
#include <boost/asio.hpp>

ServerCore::ServerCore(boost::asio::io_service &service, const Network::Core::Endpoint &ep) :
    _socket(service, ep) {}

ServerCore::~ServerCore() = default;

bool    ServerCore::startExchanges()
{
    while (true)
    {
        Network::Packet::APacket     packet;

        this->_socket.read(packet, [this, packet](const Network::Core::Error &e, Network::Packet::APacket &packet)
        {
            if (e.getCode() != Network::Core::NO_ERROR)
            {
                std::cout << "-- Packet has been received [" << packet.getType() << "]" << std::endl;
                exit(0);
            }
            else
            {
                // std::cout << "[" << e.getCode() << "] " << e.getMessage() << std::endl;
            }
        });
    }
}

bool    ServerCore::start()
{
    std::cout << "*******************************" << std::endl;
    std::cout << "* R-TYPE - SERVER version 1.0 *" << std::endl;
    std::cout << "*    Julien PRETET (Lead)     *" << std::endl;
    std::cout << "*     Guillaume CAUCHOIS      *" << std::endl;
    std::cout << "*     Robin GRATTEPANCHE      *" << std::endl;
    std::cout << "*        Adrien WARIN         *" << std::endl;
    std::cout << "*      Thomas FOSSAERT        *" << std::endl;
    std::cout << "*       Quentin BAUDET        *" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << std::endl;
    startExchanges(); //TODO: Guillaume thread l'appel
}
