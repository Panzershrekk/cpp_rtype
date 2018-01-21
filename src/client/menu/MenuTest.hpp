//
// Created by Julien Pretet on 21/01/2018.
//

#ifndef CPP_RTYPE_MENUTEST_HPP_
#define CPP_RTYPE_MENUTEST_HPP_

#include "MenuWindow.hpp"

class MenuTest : public MenuWindow
{
private:
int test = 0;
public:
  MenuTest();
  ~MenuTest();
  void print() {
    if (test == 0)
    {
   boost::asio::ip::tcp::endpoint endpoint(
      boost::asio::ip::address::from_string("0.0.0.0"),
      static_cast<unsigned short>(std::stoi("4242")));
    _client = new TcpClient(endpoint, _state);
    test = 1;
  }
    if (_client == nullptr)
      std::cout << "client is nul ptr" << std::endl;
    else
      std::cout << "client pas nul ptr" << std::endl;
  }
};


#endif /* !CPP_RTYPE_MENUTEST_HPP_ */
