//
// Created by guillobits on 20/01/18.
//

#include "common/network/packets/PacketEnemies.hpp"
#include "common/network/packets/PacketReady.hpp"
#include "ClientCore.hpp"

ClientCore::ClientCore(boost::asio::io_service &service) :
        _socket(service),
        _gameRender(_socket)
{
    this->_socket.openV4();
}

ClientCore::~ClientCore()
{
}

void    ClientCore::start()
{
    std::cout << "*******************************" << std::endl;
    std::cout << "* R-TYPE - CLIENT version 1.0 *" << std::endl;
    std::cout << "*    Julien PRETET (Lead)     *" << std::endl;
    std::cout << "*     Guillaume CAUCHOIS      *" << std::endl;
    std::cout << "*     Robin GRATTEPANCHE      *" << std::endl;
    std::cout << "*        Adrien WARIN         *" << std::endl;
    std::cout << "*      Thomas FOSSAERT        *" << std::endl;
    std::cout << "*       Quentin BAUDET        *" << std::endl;
    std::cout << "*******************************" << std::endl;
    startExchanges();
    std::thread		threadRun(&ClientCore::runService, this);


    /* MENU*/
    this->_endpointServer = Network::Core::Endpoint("0.0.0.0", 4242); // TODO Determined by Menu

    Network::Packet::PacketReady    packetReady;
    packetReady.setPlayer(1234);
    auto ser = Serializer::serialize(packetReady);
    this->_socket.async_write(ser, Network::Packet::PACKET_READY, this->_endpointServer,
                              [&](const boost::system::error_code &e, const long unsigned int&)
                              {
                                  std::cout << "FIRST PACKET HAS BEEN SENT" << std::endl;
                              });
    sleep(1);
    this->_gameRender.startGame(this->_player, this->_endpointServer);
    // this->_menu.start();
    threadRun.join();
}

void    ClientCore::startExchanges()
{
    std::array<char, MAX_READ>      data { 0 };
    boost::asio::ip::udp::endpoint  endpoint;

    this->_socket.read(data, endpoint,
                       [&](boost::system::error_code error, std::size_t size)
                       {
                           if (error || size <= 8)
                           {
                               std::cerr << "-- Received corrupted packet" << std::endl;
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

                               std::cout << "-- Received packet a " << packet->getType() << " packet";
                               this->_requestManager.handleRequest(packet, this->_gameRender);
                           }
                           catch (const std::exception &exept)
                           {
                               std::cerr << exept.what() << std::endl;
                           }
                           this->startExchanges();
                       }
    );
}

std::thread ClientCore::runService()
{
    this->_socket.run();
}