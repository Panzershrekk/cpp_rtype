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
# include <boost/serialization/access.hpp>

namespace Network
{
    namespace Core
    {
        class Endpoint
        {
        private:
            friend class boost::serialization::access;
            boost::asio::ip::address        _ip;
            unsigned short                  _port;
            boost::asio::ip::udp::endpoint  _endpoint;

        public:
            Endpoint(const std::string, const unsigned short);
            Endpoint(const unsigned short &);
            Endpoint(const Endpoint &);
            Endpoint();
            ~Endpoint();

            /* Operator overloading */
            Endpoint    &operator=(const Endpoint &);
            bool        operator==(const Endpoint &oep) const;

            void                            setIp(const std::string &);
            void                            setPort(const unsigned short &);
            const boost::asio::ip::address  &getIp() const;
            const unsigned short            &getPort() const;
            const boost::asio::ip::udp::endpoint    &getBoostEndpoint() const;

            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
            }
        };
    }
}

#endif      /* !_ENDPOINT__HPP_! */
