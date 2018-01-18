/**
 * \file UdpConnection.hpp
 * \brief Implementation of endpoint notion
 * \author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * \version 1.0
 * \date January 10, 2018
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 */

#ifndef     _ENDPOINT__HPP_
# define    _ENDPOINT__HPP_
# include <string>
# include <boost/asio.hpp>

namespace Network
{
    namespace Core
    {
        class Endpoint
        {
        private:
            boost::asio::ip::address        _ip;
            unsigned short                  _port;
            boost::asio::ip::udp::endpoint  _endpoint;

        public:
            Endpoint(const std::string &, const unsigned short &);
            Endpoint(const unsigned short &);
            Endpoint(const Endpoint &);
            ~Endpoint();

            Endpoint    &operator=(const Endpoint &);


            void                            setIp(const std::string &);
            void                            setPort(const unsigned short &);
            const boost::asio::ip::address  &getIp() const;
            const unsigned short            &getPort() const;
            const boost::asio::ip::udp::endpoint    &getBoostEndpoint() const;
        };
    }
}

#endif      /* !_ENDPOINT__HPP_! */
