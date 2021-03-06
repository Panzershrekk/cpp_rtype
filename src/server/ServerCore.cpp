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
#include "common/network/packets/PacketPlayer.hpp"
#include "server/GameManager.hpp"
#include "server/EventManager.hpp"
#include "server/ServerCore.hpp"
#include "common/network/packets/APacket.hpp"

ServerCore::ServerCore(boost::asio::io_service &service, const Network::Core::Endpoint &ep) :
        _socket(service, ep),
        _gameManager(_socket),
        _requestManager() {}

ServerCore::~ServerCore() = default;

bool    ServerCore::startExchanges()
{
    std::array<char, MAX_READ> data { 0 };
    boost::asio::ip::udp::endpoint  endpoint;

    this->_socket.read(data, endpoint,
                       [&](boost::system::error_code error, std::size_t size)
                       {
                           if (error || size <= 8)
                           {
                               std::cerr << "-- Received corrupted packet" << std::endl;
                               this->startExchanges();
                               return;
                           }
                           try
                           {
                               std::istringstream               streamHeader(std::string(data.begin(), 8));
                               std::size_t                      dataType;
                               Network::Packet::PacketType      packetType;
                               Network::Packet::APacket         *packet;

                               if (!(streamHeader >> std::hex >> dataType))
                               {
                                   std::cerr << "-- Received corrupted packet header" << std::endl;
                                   this->startExchanges();
                                   return;
                               }
                               packetType = (Network::Packet::PacketType)dataType;

                               Serializer   serializer;
                               if (!(packet = serializer.deserialize(std::string(data.begin() + 8, data.begin() + size), packetType)))
                               {
                                   std::cerr << "-- Received unhandled packet" << std::endl;
                                   this->startExchanges();
                                   return;
                               }
                               if (dataType == Network::Packet::PACKET_READY)
                               {
                                   Network::Core::Endpoint  ep(endpoint.address().to_string(), endpoint.port());
                                   this->_requestManager.handleNewUdpClient(ep, this->_gameManager);
                               }
                               else
                                   this->_requestManager.handleRequest(packet, this->_gameManager);

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
    startExchanges();
    std::thread		threadRun(&ServerCore::runService, this);

    Player   newPlayer;
    newPlayer.setName("wiart_m");
    newPlayer.setId(1234);
    this->_gameManager.addPlayer(newPlayer);
    this->_gameManager.spawnEnnemy();
    this->_gameManager.update();
    threadRun.join();
}


std::thread 	ServerCore::runService()
{
    this->_socket.run();
}