//
// Created by guillobits on 20/01/18.
//

#include "ClientCore.hpp"

ClientCore::ClientCore(boost::asio::io_service &service) : _socket(service)
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

    sleep(1);
    this->_socket.async_write("Hello world !", Network::Packet::PACKET_FIRE, Network::Core::Endpoint("0.0.0.0", 4242),
                              [&](const boost::system::error_code &e, const long unsigned int&)
                              {
                                  std::cout << "FIRST PACKET HAS BEEN SENT" << std::endl;
                              });
    this->_gameRender.startGame();
    threadRun.join();
}

// TODO PASSER LE GROS BLOC DANS FN
void    ClientCore::startExchanges()
{
    std::array<char, MAX_READ> data { 0 };
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

                               Player                          player;
                               const Network::Core::Endpoint   ep("127.0.0.1", 4242);
                               player.setName("Guillaume");
                               player.setHp(42);
                               player.setScore(0);
                               Network::Packet::PacketPlayer   packetPlayer;
                               packetPlayer.getPlayer().setName("GUillaume LE vainqueur du UDP !");
                               std::string                     packetSerialized = Serializer::serialize(packetPlayer);
                               this->_socket.async_write(packetSerialized, packetPlayer.getType(), ep,
                                                         [&](const boost::system::error_code &e, const long unsigned int&)
                                                         {
                                                             std::cout << "-- Packet has been sent" << std::endl;
                                                         });

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