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
#include <common/network/packets/PacketPlayer.hpp>
#include "server/ServerCore.hpp"
#include "common/network/packets/APacket.hpp"

ServerCore::ServerCore(boost::asio::io_service &service, const Network::Core::Endpoint &ep) :
        _socket(service, ep) {}

ServerCore::~ServerCore() = default;

bool    ServerCore::startExchanges()
{
        std::array<char, MAX_READ> data{ 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
        boost::asio::ip::udp::endpoint  endpoint;

        this->_socket.read(data, endpoint,
                           [&](boost::system::error_code error, std::size_t size)
                           {
                               if (error || size <= 8)
                               {
                                   std::cerr << "PACKET CORROMPU" << std::endl;
                               }
                               try
                               {
                                   std::istringstream               streamHeader(std::string(data.begin(), 8));
                                   std::size_t                      dataType;
                                   Network::Packet::PacketType      packetType;
                                   Network::Packet::APacket         *packet;

                                   if (!(streamHeader >> std::hex >> dataType))
                                   {
                                       std::cerr << "INVALID TYPE" << std::endl;
                                       this->startExchanges();
                                       return;
                                   }
                                   packetType = (Network::Packet::PacketType)dataType;

                                   Serializer   serializer;
                                   if (!(packet = serializer.deserialize(std::string(data.begin() + 8, data.begin() + size), packetType)))
                                   {
                                       std::cerr << "INVALID TYPE RECEIVED" << std::endl;
                                       this->startExchanges();
                                       return;
                                   }

                                   std::cout << "type packet =" << dataType << std::endl;
                                   std::cout << "CP: " << static_cast<Network::Packet::PacketPlayer *>(packet)->getPlayer().getName() << std::endl;
                               }
                               catch (const std::exception &exept)
                               {
                                   std::cerr << exept.what() << std::endl;
                               }
                               this->startExchanges();
                           }
        );
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
