//
// Created by guillobits on 13/01/18.
//

#ifndef     _NETWORK_EXCEPTION__HPP_
# define    _NETWORK_EXCEPTION__HPP_

namespace Network
{
    namespace Core
    {
        class Exception : public std::exception
        {
        private:
            const std::string   _what;

        public:
            Exception(const std::string &what) throw(): _what(what) {}
            const char  *what() const throw() override
            {
                return this->_what.c_str();
            }
        };
    }
}

#endif //CPP_RTYPE_EXCEPTION_H
