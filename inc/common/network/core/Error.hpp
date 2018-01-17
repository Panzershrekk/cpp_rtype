/**
 * \file ErrorCode.hpp
 * \brief Implementation of Error for Network::Core
 * \author Guillaume CAUCHOIS (guillaume.cauchois@epitech.eu)
 * \version 1.0
 * \date January 13, 2018
 *
 * EPITECH PROJECT 2020 - RTYPE
 *
 */

#ifndef     _ERROR_CODE__HPP_
# define    _ERROR_CODE__HPP_
# include <map>
# include "Exception.hpp"

namespace Network
{
    namespace Core
    {
        typedef enum    ErrorCode
        {
            NO_ERROR = 0,
            INVALID_ARGUMENT = 1,
            INVALID_READ = 2,
            INVALID_HEADER_FORMAT = 3,
            INVALID_DATA_SIZE = 4,
            INVALID_DATA_CONTENT = 5
        }               ErrorCode;

        class Error
        {
        private:
            const std::map<ErrorCode, std::string>      _connections = initConnectionErrorCodeMessage();
            const std::string                           _message;
            const ErrorCode                             _code = ErrorCode::NO_ERROR;

        public:
            Error(const ErrorCode &code);
            ~Error();

            const std::string   getMessage() const;
            const ErrorCode     getCode() const;

            static const std::map<ErrorCode, std::string>    initConnectionErrorCodeMessage()
            {
                std::map<ErrorCode, std::string>  connections;

                connections.emplace(std::make_pair(NO_ERROR, "No error"));
                connections.emplace(std::make_pair(INVALID_READ, "Invalid read informations from socket"));
                connections.emplace(std::make_pair(INVALID_HEADER_FORMAT, "The header format is not valid"));
                connections.emplace(std::make_pair(INVALID_DATA_SIZE, "The data size doesn't match with the header information"));
                connections.emplace(std::make_pair(INVALID_DATA_CONTENT, "the data has been corrupted"));
                return connections;
            };

            const std::string    &getMessageFromCode(const ErrorCode &code) const;
        };
    }
}

#endif      /* !_ERROR_CODE__HPP_! */