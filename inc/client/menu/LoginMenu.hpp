//
// Created by grodin on 16/01/18.
//

#ifndef CPP_RTYPE_LOGINMENU_HPP_
#define CPP_RTYPE_LOGINMENU_HPP_

#include <unordered_map>
#include "IMenu.hpp"

class LoginMenu : public IMenu
{
  private:
    std::map<std::string, Sprite> 	_sprites;
    Text				_ip;
    std::string				_ipText;
    bool				_isIPCliked = false;
  MenuState	&_state;

    Text				_port;
    std::string				_portText;
    bool				_isPortCliked = false;

    Text				_name;
    std::string				_nameText;
    bool				_isNameCliked = false;

  public:
    explicit LoginMenu(MenuState &);
    ~LoginMenu();

    void start(Window &) override;
    void update(Window &, sf::Event &) override;
    void draw(Window &) override;

    void 	enterIP(Window &, sf::Event &);
    void 	enterPort(Window &, sf::Event &);
    void 	enterName(Window &, sf::Event &);
};


#endif /* !CPP_RTYPE_LOGINMENU_HPP_ */
