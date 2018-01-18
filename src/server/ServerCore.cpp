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
#include <sstream>
#include "server/ServerCore.hpp"

ServerCore::ServerCore(boost::asio::io_service &service, const Network::Core::Endpoint &ep) :
        _socket(service, ep) {}

ServerCore::~ServerCore() = default;

bool    ServerCore::startExchanges()
{
    while (1)
    {
        this->_socket.read(this->_ss,
                           [this] (const Network::Core::Error &e)
                           {
                               if (e.getCode() == Network::Core::NO_ERROR)
                                   std::cout << "-- Packet has been received : [" << this->_ss.str() << "]" << std::endl;
                               else
                                   std::cout << "-- ERROR [" << e.getCode() << "] " << e.getMessage() << std::endl;
                           },
                           [this](const Network::Core::Endpoint &ep)
                           {
                               std::cout << "-- NEW CLIENT [" << ep.getIp() << ":"<< ep.getPort() << "]" << std::endl;
                           });
    }

}

bool    ServerCore::start()
{
    std::cout << "*******************************" << std::endl;
    std::cout << "* R-TYPE - SERVER version 1.0 *" << std::endl;
    std::cout << "*    Julien PRETET (Lead)     *" << std::endl;
    std::cout << "*     Guillaume CAUCHOIS :'(  *" << std::endl;
    std::cout << "*     Robin GRATTEPANCHE      *" << std::endl;
    std::cout << "*        Adrien WARIN         *" << std::endl;
    std::cout << "*      Thomas FOSSAERT        *" << std::endl;
    std::cout << "*       Quentin BAUDET        *" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << std::endl;
    startExchanges(); //TODO: Guillaume thread l'appel
}
